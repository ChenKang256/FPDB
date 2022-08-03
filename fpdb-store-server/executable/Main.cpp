//
// Created by matt on 4/2/22.
//

#include <cstring>
#include <future>

#include <arrow/status.h>
#include <arrow/flight/api.h>
#include <fpdb/store/server/FlightHandler.hpp>

#include "Global.hpp"

using namespace fpdb::store::server;

std::unique_ptr<FlightHandler> flight_handler;

void signal_handler( int signum ) {

    SPDLOG_INFO("FlexPushdownDB Store Server stopping (Signal {}:{})", signum, strsignal(signum));

    flight_handler->shutdown();

    SPDLOG_INFO("FlexPushdownDB Store Server stopped ");
    exit(signum);
}

int main(int argc, char **argv) {

    ::arrow::Status st;

    SPDLOG_INFO("FlexPushdownDB Store Server starting");

    // Start the server
    ::arrow::flight::Location server_location;
    st = ::arrow::flight::Location::ForGrpcTcp("0.0.0.0", 10000, &server_location);
    if(!st.ok()){
        SPDLOG_ERROR("Could not start FlightHandler, {}", st.message());
    }
    flight_handler = std::make_unique<FlightHandler>(server_location);
    auto ex = flight_handler->init();
    if(!ex.has_value()){
        SPDLOG_ERROR("Could not start FlightHandler, {}", st.message());
    }

    signal(SIGINT, signal_handler);
    signal(SIGHUP, signal_handler);
    signal(SIGQUIT, signal_handler);
    signal(SIGTERM, signal_handler);

    SPDLOG_INFO("FlexPushdownDB Store Server started (FlightHandler listening on {})", flight_handler->port().value());
    auto stopped_future = std::async([&]() { return flight_handler->serve(); });

    stopped_future.wait();

    return 0;
}