//
// Created by matt on 4/2/22.
//

#include <future>

#include <doctest/doctest.h>
#include <fpdb/store/server/TicketObject.hpp>
#include "fpdb/store/server/FlightHandler.hpp"
#include "fpdb/store/server/CmdObject.hpp"
#include "fpdb/store/server/FlightInputSerialization.hpp"

#include "Module.hpp"

using namespace fpdb::store::server;

TEST_SUITE ("fpdb-store-server/FlightTest" * doctest::skip(false)) {

    TEST_CASE ("fpdb-store-server/FlightTest/test-cmd-serialization" * doctest::skip(false)) {

        // Define cmd
        auto src_cmd = SelectObjectContentCmd::make(FlightSelectObjectContentRequest::make(
                "select * from s3object", FlightCSVInputSerialization::make(CSVInput(FileHeaderInfo::Use))));

        // Serialize cmd
        auto src_string = src_cmd->serialize(true);
        SPDLOG_DEBUG(src_string);
                REQUIRE_EQ(src_string, R"({
  "select-object-content-request": {
    "expression": "select * from s3object",
    "input-serialization": {
      "csv": {
        "file-header-info": "USE"
      }
    }
  }
})");

        // Deserialize cmd
        auto dst_cmd = CmdObject::deserialize(src_string);
        auto dst_string = dst_cmd.value()->serialize(true);
        SPDLOG_DEBUG(dst_string);
                REQUIRE_EQ(dst_string, R"({
  "select-object-content-request": {
    "expression": "select * from s3object",
    "input-serialization": {
      "csv": {
        "file-header-info": "USE"
      }
    }
  }
})");
    }

    TEST_CASE ("fpdb-store-server/FlightTest/test-ticket-serialization" * doctest::skip(false)) {

        // Define ticket
        auto src_ticket = SelectObjectContentTicket::make(
                "test-bucket", "test-object",
                FlightSelectObjectContentRequest::make("select * from s3object",
                                                       FlightCSVInputSerialization::make(
                                                               CSVInput(FileHeaderInfo::Use))));

        // Serialize ticket
        auto src_string = src_ticket->serialize(true);
        SPDLOG_DEBUG(src_string);
                REQUIRE_EQ(src_string, R"({
  "bucket": "test-bucket",
  "object": "test-object",
  "select-object-content-request": {
    "expression": "select * from s3object",
    "input-serialization": {
      "csv": {
        "file-header-info": "USE"
      }
    }
  }
})");

        // Deserialize ticket
        auto dst_ticket = TicketObject::deserialize(src_string);
        auto dst_string = dst_ticket.value()->serialize(true);
        SPDLOG_DEBUG(dst_string);
                REQUIRE_EQ(dst_string, R"({
  "bucket": "test-bucket",
  "object": "test-object",
  "select-object-content-request": {
    "expression": "select * from s3object",
    "input-serialization": {
      "csv": {
        "file-header-info": "USE"
      }
    }
  }
})");
    }

    TEST_CASE ("fpdb-store-server/FlightTest/test-get-flight-info" * doctest::skip(false)) {

        ::arrow::Status st;

        // Start the server
        ::arrow::flight::Location server_location;
        st = ::arrow::flight::Location::ForGrpcTcp("0.0.0.0", 0, &server_location);
                REQUIRE(st.ok());
        auto server = std::make_unique<FlightHandler>(server_location);
        server->init();
        auto stopped_future = std::async([&]() { return server->serve(); });

        // Connect the client
        arrow::flight::Location client_location;
        auto port = server->port();
        st = arrow::flight::Location::ForGrpcTcp("localhost", port.value(), &client_location);
                REQUIRE(st.ok());
        arrow::flight::FlightClientOptions client_options = arrow::flight::FlightClientOptions::Defaults();
        std::unique_ptr<arrow::flight::FlightClient> client;
        st = arrow::flight::FlightClient::Connect(client_location, client_options, &client);
                REQUIRE(st.ok());

        // Get FlightInfo
        arrow::flight::FlightCallOptions call_options2;
        call_options2.headers.emplace_back("bucket", "test");
        call_options2.headers.emplace_back("object", "test");
        auto flight_descriptor = FlightDescriptor::Path({"test"});
        std::unique_ptr<FlightInfo> flight_info;
        st = client->GetFlightInfo(call_options2, flight_descriptor, &flight_info);
                REQUIRE(st.ok());

        SPDLOG_DEBUG(flight_info->descriptor().ToString());
        SPDLOG_DEBUG(flight_info->endpoints()[0].ticket.ticket);
        SPDLOG_DEBUG(flight_info->endpoints()[0].locations.size());

        server->shutdown();
        stopped_future.wait();
    }

    TEST_CASE ("fpdb-store-server/FlightTest/test-do-get" * doctest::skip(false)) {
        ::arrow::Status st;

        // Start the server
        ::arrow::flight::Location server_location;
        st = ::arrow::flight::Location::ForGrpcTcp("0.0.0.0", 0, &server_location);
                REQUIRE(st.ok());
        auto server = std::make_unique<FlightHandler>(server_location);
        server->init();
        auto stopped_future = std::async([&]() { return server->serve(); });

        // Connect the client
        arrow::flight::Location client_location;
        auto port = server->port();
        st = arrow::flight::Location::ForGrpcTcp("localhost", port.value(), &client_location);
                REQUIRE(st.ok());
        arrow::flight::FlightClientOptions client_options = arrow::flight::FlightClientOptions::Defaults();
        std::unique_ptr<arrow::flight::FlightClient> client;
        st = arrow::flight::FlightClient::Connect(client_location, client_options, &client);
                REQUIRE(st.ok());

        auto ticket_obj = SelectObjectContentTicket::make(
                "test-bucket", "test-object", FlightSelectObjectContentRequest::make("select * from s3object",
                                                                                     FlightCSVInputSerialization::make(
                                                                                             CSVInput(
                                                                                                     FileHeaderInfo::Use))));
        std::unique_ptr<::arrow::flight::FlightStreamReader> reader;
        st = client->DoGet(ticket_obj->to_ticket(false), &reader);
                REQUIRE(st.ok());

        std::shared_ptr<::arrow::Table> table;
        st = reader->ReadAll(&table);
                REQUIRE(st.ok());

                REQUIRE_EQ(table->num_columns(), 3);
                REQUIRE_EQ(table->num_rows(), 20);

        server->shutdown();
        stopped_future.wait();
    }

}