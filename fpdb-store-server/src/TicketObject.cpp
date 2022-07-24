//
// Created by matt on 4/2/22.
//

#include <nlohmann/json.hpp>
#include <fmt/format.h>

#include "fpdb/store/server/TicketObject.hpp"

namespace fpdb::store::server {

    static constexpr std::string_view SelectObjectContentRequestJSONName = "select-object-content-request";
    static constexpr std::string_view GetObjectContentRequestJSONName = "get-object-request";
    static constexpr std::string_view BucketJSONName = "bucket";
    static constexpr std::string_view ObjectJSONName = "object";

    TicketObject::TicketObject(std::shared_ptr<TicketType> type) : type_(std::move(type)) {
    }

    const std::shared_ptr<TicketType>& TicketObject::type() const {
        return type_;
    }

    ::arrow::flight::Ticket TicketObject::to_ticket(bool pretty) {
        return arrow::flight::Ticket{serialize(pretty)};
    }

    tl::expected<std::shared_ptr<TicketObject>, std::string> TicketObject::deserialize(const std::string& string) {

        auto document = nlohmann::json::parse(string);

        if(document.is_object()) {
            if(document.contains(BucketJSONName.data())) {
                const auto bucket = document[BucketJSONName.data()].get<std::string>();
                if(document.contains(ObjectJSONName.data())) {
                    const auto object = document[ObjectJSONName.data()].get<std::string>();
                    if(document.contains(SelectObjectContentRequestJSONName.data())) {
                        auto& select_object_content_value = document[SelectObjectContentRequestJSONName.data()];
                        if(select_object_content_value.is_object()) {
                            auto maybe_select_object_content =
                                    FlightSelectObjectContentRequest::from_json(select_object_content_value);

                            if(!maybe_select_object_content.has_value()){
                                return tl::make_unexpected(maybe_select_object_content.error());
                            }

                            return SelectObjectContentTicket::make(std::string(bucket), std::string(object), maybe_select_object_content.value());
                        }
                    }
                    else if(document.contains(GetObjectContentRequestJSONName.data())) {
                        return GetObjectTicket::make(std::string(bucket), std::string(object));
                    }
                }
            }
        }

        return tl::make_unexpected(fmt::format("Cannot parse Ticket cmd JSON '{}'", string));
    }

    tl::expected<std::shared_ptr<TicketObject>, std::string>
    TicketObject::deserialize(const ::arrow::flight::Ticket& ticket) {
        return deserialize(ticket.ticket);
    }

    GetObjectTicket::GetObjectTicket(std::string bucket, std::string object)
            : TicketObject(TicketType::get_object()), bucket_(std::move(bucket)), object_(std::move(object)) {
    }

    std::shared_ptr<GetObjectTicket> GetObjectTicket::make(std::string bucket, std::string object) {
        return std::make_shared<GetObjectTicket>(std::move(bucket), std::move(object));
    }

    const std::string& GetObjectTicket::object() const {
        return object_;
    }

    const std::string& GetObjectTicket::bucket() const {
        return bucket_;
    }

    std::string GetObjectTicket::serialize(bool pretty) {
        nlohmann::json document;

        nlohmann::json bucket;
        bucket = bucket_.c_str();
        document.emplace(BucketJSONName.data(), bucket);

        nlohmann::json object;
        object = object_.c_str();
        document.emplace(ObjectJSONName.data(), object);

        document.emplace(GetObjectContentRequestJSONName.data(),  nlohmann::json{});

        return document.dump(pretty ? 2: -1);
    }

    SelectObjectContentTicket::SelectObjectContentTicket(
            std::string bucket, std::string object, std::shared_ptr<FlightSelectObjectContentRequest> select_object_content)
            : TicketObject(TicketType::select_object_content()),
              bucket_(std::move(bucket)),
              object_(std::move(object)),
              select_object_content_(std::move(select_object_content)) {
    }

    std::shared_ptr<SelectObjectContentTicket>
    SelectObjectContentTicket::make(std::string bucket, std::string object,
                                    std::shared_ptr<FlightSelectObjectContentRequest> select_object_content) {
        return std::make_shared<SelectObjectContentTicket>(std::move(bucket), std::move(object),
                                                           std::move(select_object_content));
    }

    const std::string& SelectObjectContentTicket::bucket() const {
        return bucket_;
    }

    const std::string& SelectObjectContentTicket::object() const {
        return object_;
    }

    std::string SelectObjectContentTicket::serialize(bool pretty) {

        nlohmann::json document;

        nlohmann::json bucket;
        bucket = bucket_.c_str();
        document.emplace(BucketJSONName.data(), bucket);

        nlohmann::json object;
        object = object_.c_str();
        document.emplace(ObjectJSONName.data(), object);

        document.emplace(SelectObjectContentRequestJSONName.data(),                           select_object_content_->to_json());

        return document.dump(pretty ? 2 : -1);
    }

    const std::shared_ptr<FlightSelectObjectContentRequest>& SelectObjectContentTicket::select_object_content() const {
        return select_object_content_;
    }
}