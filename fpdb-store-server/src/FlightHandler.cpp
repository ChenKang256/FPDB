//
// Created by matt on 4/2/22.
//

#include <fmt/format.h>
#include <fpdb/tuple/arrow/Arrays.h>

#include "fpdb/store/server/FlightHandler.hpp"
#include "fpdb/store/server/HeaderMiddlewareFactory.hpp"

namespace fpdb::store::server {

    tl::expected<std::string, std::string> serialize_to_string(const ::arrow::Schema &schema) {
        ::arrow::ipc::DictionaryMemo unused_dict_memo;
        auto maybe_serialized_schema = ::arrow::ipc::SerializeSchema(schema);
        if (!maybe_serialized_schema.ok()) {
            return tl::make_unexpected(maybe_serialized_schema.status().message());
        }

        auto string = std::string(reinterpret_cast<const char *>((*maybe_serialized_schema)->data()),
                                  static_cast<size_t>((*maybe_serialized_schema)->size()));
        return {};
    }

    constexpr std::string_view HeaderMiddlewareKey = "header-middleware";
    constexpr std::string_view BucketHeaderKey = "bucket";
    constexpr std::string_view ObjectHeaderKey = "object";

    FlightHandler::FlightHandler(Location location) : location_(std::move(location)) {
    }

    FlightHandler::~FlightHandler() {
        this->shutdown();
    }

    tl::expected<void, std::string> FlightHandler::init() {
        FlightServerOptions options(location_);
        options.middleware.emplace_back(HeaderMiddlewareKey, std::make_shared<HeaderMiddlewareFactory>());
        auto st = this->Init(options);
        if (!st.ok()) {
            return tl::make_unexpected(st.message());
        }

        // NOTE: This appears to swallow the signal and not allow anything else to handle it
        //  this->SetShutdownOnSignals({SIGTERM});
        this->SetShutdownOnSignals({});
        return {};
    }

    tl::expected<void, std::string> FlightHandler::serve() {
        auto st = this->Serve();
        if (!st.ok()) {
            return tl::make_unexpected(st.message());
        }
        return {};
    }

    tl::expected<void, std::string> FlightHandler::shutdown() {
        auto st = (this->Shutdown());
        if (!st.ok()) {
            return tl::make_unexpected(st.message());
        }
//        st = (this->Wait());
//        if (!st.ok()) {
//            return tl::make_unexpected(st.message());
//        }
        return {};
    }

    tl::expected<int, std::string> FlightHandler::port() {
        return FlightServerBase::port();
    }

    tl::expected<HeaderMiddleware *, std::string>
    FlightHandler::get_header_middleware(const ::arrow::flight::ServerCallContext &context) {
        auto *header_middleware = context.GetMiddleware(
                std::string{HeaderMiddlewareKey.data(), HeaderMiddlewareKey.size()});
        if (header_middleware == nullptr) {
            return tl::make_unexpected("HeaderMiddleware not found in ServerCallContext");
        }
        return dynamic_cast<HeaderMiddleware *>(header_middleware);
    }

    tl::expected<std::string, std::string> FlightHandler::parse_header(const std::string &key,
                                                                       const HeaderMiddleware &middleware) {
        auto it = middleware.headers().find(key);
        if (it == middleware.headers().end()) {
            return tl::make_unexpected(fmt::format("Header '{}' not found", key));
        }
        return std::string{it->second};
    }

    ::arrow::Status FlightHandler::GetFlightInfo(const ServerCallContext &context, const FlightDescriptor &request,
                                                 std::unique_ptr<FlightInfo> *info) {
        auto expected_flight_info = get_flight_info(context, request);
        if (!expected_flight_info.has_value()) {
            return expected_flight_info.error();
        }
        *info = std::move(expected_flight_info.value());
        return ::arrow::Status::OK();
    }

    ::arrow::Status FlightHandler::DoGet(const ServerCallContext &context, const Ticket &request,
                                         std::unique_ptr<FlightDataStream> *stream) {
        auto expected_flight_stream = do_get(context, request);
        if (!expected_flight_stream.has_value()) {
            return expected_flight_stream.error();
        }
        *stream = std::move(expected_flight_stream.value());
        return ::arrow::Status::OK();
    }

    tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status>
    FlightHandler::get_flight_info(const ServerCallContext &context, const FlightDescriptor &request) {

        auto expected_middleware = get_header_middleware(context);
        if (!expected_middleware.has_value()) {
            return tl::make_unexpected(MakeFlightError(FlightStatusCode::Internal, "Internal error"));
        }
        auto *middleware = expected_middleware.value();

        auto expected_bucket = parse_header({BucketHeaderKey.data(), BucketHeaderKey.size()}, *middleware);
        if (!expected_bucket.has_value()) {
            return tl::make_unexpected(MakeFlightError(FlightStatusCode::Failed, expected_bucket.error()));
        }
        auto bucket = expected_bucket.value();

        auto expected_object = parse_header({ObjectHeaderKey.data(), ObjectHeaderKey.size()}, *middleware);
        if (!expected_object.has_value()) {
            return tl::make_unexpected(MakeFlightError(FlightStatusCode::Failed, expected_object.error()));
        }
        auto object = expected_object.value();

        switch (request.type) {
            case FlightDescriptor::UNKNOWN: {
                return tl::make_unexpected(MakeFlightError(
                        FlightStatusCode::Failed,
                        fmt::format("FlightDescriptor type '{}' not supported", request.type)));
            }
            case FlightDescriptor::PATH: {
                return get_flight_info_for_path(context, request, bucket, object);
            }
            case FlightDescriptor::CMD: {
                return get_flight_info_for_cmd(context, request, bucket, object);
            }
        }

        return tl::make_unexpected(
                MakeFlightError(FlightStatusCode::Failed,
                                fmt::format("Unrecognized FlightDescriptor type '{}'", request.type)));
    }

    tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status>
    FlightHandler::get_flight_info_for_path(const ServerCallContext &context, const FlightDescriptor &request,
                                            std::string bucket, std::string object) {

        // Create the ticket
        auto ticket_object = GetObjectTicket::make(std::move(bucket), std::move(object));

        // Create the endpoints (dummy for now)
        std::vector<FlightEndpoint> endpoints;
        FlightEndpoint endpoint{ticket_object->to_ticket(false), {}};
        endpoints.push_back(endpoint);

        // Create the FlightInfo object, contains the original descriptor and the endpoints to find the data
        FlightInfo::Data flight_data;
        flight_data.descriptor = request;
        flight_data.endpoints = endpoints;
        auto expected_serialized_schema = serialize_to_string(*::arrow::schema({}));
        if (!expected_serialized_schema.has_value()) {
            return tl::make_unexpected(MakeFlightError(FlightStatusCode::Internal, "Internal error"));
        }
        flight_data.schema = expected_serialized_schema.value();
        flight_data.total_records = -1;
        flight_data.total_bytes = -1;

        return std::make_unique<FlightInfo>(flight_data);
    }

    tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status>
    FlightHandler::get_flight_info_for_cmd(const ServerCallContext &context, const FlightDescriptor &request,
                                           std::string bucket, std::string object) {

        // Parse the cmd object
        auto expected_cmd_object = CmdObject::deserialize(request.cmd);
        if (!expected_cmd_object.has_value()) {
            return tl::make_unexpected(MakeFlightError(FlightStatusCode::Failed, expected_cmd_object.error()));
        }
        auto cmd_object = expected_cmd_object.value();

        switch (cmd_object->type()->id()) {
            case CmdTypeId::SelectObjectContent: {
                auto select_object_content_cmd = std::static_pointer_cast<SelectObjectContentCmd>(cmd_object);
                return get_flight_info_for_select_object_content_cmd(context, request, std::move(bucket),
                                                                     std::move(object),
                                                                     select_object_content_cmd);
            }
        }

        return tl::make_unexpected(MakeFlightError(FlightStatusCode::Internal, "Internal error"));
    }

    tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status>
    FlightHandler::get_flight_info_for_select_object_content_cmd(
            const ServerCallContext &context, const FlightDescriptor &request, std::string bucket, std::string object,
            const std::shared_ptr<SelectObjectContentCmd> &select_object_content_cmd) {

        // Create the ticket
        auto ticket_object = SelectObjectContentTicket::make(std::move(bucket), std::move(object),
                                                             select_object_content_cmd->select_object_content());

        // Create the endpoints (dummy for now)
        std::vector<FlightEndpoint> endpoints;
        FlightEndpoint endpoint{ticket_object->to_ticket(false), {}};
        endpoints.push_back(endpoint);

        // Create the FlightInfo object, contains the original descriptor and the endpoints to find the data
        FlightInfo::Data flight_data;
        flight_data.descriptor = request;
        flight_data.endpoints = endpoints;
        auto expected_serialized_schema = serialize_to_string(*::arrow::schema({}));
        if (!expected_serialized_schema.has_value()) {
            return tl::make_unexpected(MakeFlightError(FlightStatusCode::Internal, "Internal error"));
        }
        flight_data.schema = expected_serialized_schema.value();
        flight_data.total_records = -1;
        flight_data.total_bytes = -1;

        return std::make_unique<FlightInfo>(flight_data);
    }

    tl::expected<std::unique_ptr<FlightDataStream>, ::arrow::Status> FlightHandler::do_get_select_object_content(
            const ServerCallContext &context,
            const std::shared_ptr<SelectObjectContentTicket> &select_object_content_ticket) {

        const auto &bucket_name = select_object_content_ticket->bucket();
        const auto &object_name = select_object_content_ticket->object();

        auto schema = ::arrow::schema({
                                              {field("f0", ::arrow::int32())},
                                              {field("f1", ::arrow::int32())},
                                              {field("f2", ::arrow::int32())},
                                      });

        auto array_0_0 = Arrays::make<::arrow::Int32Type>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}).value();
        auto array_0_1 = Arrays::make<::arrow::Int32Type>(
                {10, 11, 12, 13, 14, 15, 16, 17, 18, 19}).value();
        auto array_0_2 = Arrays::make<::arrow::Int32Type>(
                {20, 21, 22, 23, 24, 25, 26, 27, 28, 29}).value();

        auto rb_0 = ::arrow::RecordBatch::Make(schema, 10, {array_0_0, array_0_1, array_0_2});
        auto rb_1 = ::arrow::RecordBatch::Make(schema, 10, {array_0_0, array_0_1, array_0_2});

        auto rb_reader = ::arrow::RecordBatchReader::Make({rb_0, rb_1});

        return std::make_unique<::arrow::flight::RecordBatchStream>(*rb_reader);
    }

    tl::expected<std::unique_ptr<FlightDataStream>, ::arrow::Status>
    FlightHandler::do_get(const ServerCallContext &context,
                          const Ticket &request) {

        auto expected_ticket_object = TicketObject::deserialize(request);
        if (!expected_ticket_object.has_value()) {
            return tl::make_unexpected(
                    MakeFlightError(FlightStatusCode::Failed,
                                    fmt::format("Cannot parse Flight Ticket '{}'", request.ticket)));
        }
        auto ticket_object = expected_ticket_object.value();

        switch (ticket_object->type()->id()) {
            case TicketTypeId::GetObject: {
                return tl::make_unexpected(::arrow::flight::MakeFlightError(FlightStatusCode::Internal, "NYI"));
            }
            case TicketTypeId::SelectObjectContent: {
                auto select_object_content_ticket = std::static_pointer_cast<SelectObjectContentTicket>(ticket_object);
                return do_get_select_object_content(context, select_object_content_ticket);
            }
        }

        return tl::make_unexpected(MakeFlightError(
                FlightStatusCode::Failed,
                fmt::format("Unrecognized Flight Ticket type '{}'", ticket_object->type()->name())));
    }

}