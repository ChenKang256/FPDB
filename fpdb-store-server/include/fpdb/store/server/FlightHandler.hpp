//
// Created by matt on 4/2/22.
//

#ifndef FPDB_FLIGHTHANDLER_HPP
#define FPDB_FLIGHTHANDLER_HPP

#include <arrow/api.h>
#include <arrow/flight/api.h>
#include <tl/expected.hpp>

#include "HeaderMiddleware.hpp"
#include "TicketObject.hpp"
#include "CmdObject.hpp"

namespace fpdb::store::server {

    using namespace ::arrow::flight;

    class FlightHandler : FlightServerBase {

    public:
        /**
         *
         * @param location
         */
        explicit FlightHandler(Location location);

        /**
         *
         */
        ~FlightHandler() override;

        /**
         *
         * @return
         */
        tl::expected<void, std::string> init();

        /**
         *
         * @return
         */
        tl::expected<void, std::string> serve();

        /**
         *
         * @return
         */
        tl::expected<void, std::string> shutdown();

        /**
         *
         * @return
         */
        tl::expected<int, std::string> port();

        /**
         *
         * @param context
         * @param request
         * @param info
         * @return
         */
        ::arrow::Status GetFlightInfo(const ServerCallContext &context, const FlightDescriptor &request,
                                      std::unique_ptr<FlightInfo> *info) override;

        /**
         *
         * @param context
         * @param request
         * @param stream
         * @return
         */
        ::arrow::Status DoGet(const ServerCallContext &context, const Ticket &request,
                              std::unique_ptr<FlightDataStream> *stream) override;

    private:
        /**
         *
         * @param context
         * @return
         */
        static tl::expected<HeaderMiddleware *, std::string> get_header_middleware(const ServerCallContext &context);

//        /**
//         *
//         * @param context
//         * @return
//         */
//        tl::expected<AuthorizeMiddleware *, std::string>
//        get_authorize_middleware(const ::arrow::flight::ServerCallContext &context);

        /**
         *
         * @param key
         * @param middleware
         * @return
         */
        static tl::expected<std::string, std::string>
        parse_header(const std::string &key, const HeaderMiddleware &middleware);

        /**
         *
         * @param context
         * @param request
         * @param bucket
         * @param object
         * @return
         */
        static tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status>
        get_flight_info_for_path(const ServerCallContext &context, const FlightDescriptor &request, std::string bucket,
                                 std::string object);

        /**
         *
         * @param context
         * @param request
         * @param bucket
         * @param object
         * @return
         */
        tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status>
        get_flight_info_for_cmd(const ServerCallContext &context, const FlightDescriptor &request, std::string bucket,
                                std::string object);

        /**
         *
         * @param context
         * @param request
         * @param bucket
         * @param object
         * @param select_object_content_cmd
         * @return
         */
        static tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status> get_flight_info_for_select_object_content_cmd(
                const ServerCallContext &context, const FlightDescriptor &request, std::string bucket,
                std::string object,
                const std::shared_ptr<SelectObjectContentCmd> &select_object_content_cmd);

        /**
         *
         * @param context
         * @param request
         * @return
         */
        tl::expected<std::unique_ptr<FlightInfo>, ::arrow::Status> get_flight_info(const ServerCallContext &context,
                                                                                   const FlightDescriptor &request);

        /**
         *
         * @param context
         * @param account
         * @param select_object_content_ticket
         * @return
         */
        static tl::expected<std::unique_ptr<FlightDataStream>, ::arrow::Status>
        do_get_select_object_content(const ServerCallContext &context,
                                     const std::shared_ptr<SelectObjectContentTicket> &select_object_content_ticket);

        /**
         *
         * @param context
         * @param request
         * @return
         */
        tl::expected<std::unique_ptr<FlightDataStream>, ::arrow::Status> do_get(const ServerCallContext &context,
                                                                                const Ticket &request);

        ::arrow::flight::Location location_;
    };

}


#endif //FPDB_FLIGHTHANDLER_HPP
