//
// Created by matt on 4/2/22.
//

#ifndef FPDB_FLIGHTINPUTSERIALIZATION_HPP
#define FPDB_FLIGHTINPUTSERIALIZATION_HPP

#include <nlohmann/json.hpp>
#include <tl/expected.hpp>

#include "fpdb/store/server/InputSerializationType.hpp"
#include "fpdb/store/server/CSVInput.hpp"
#include "fpdb/store/server/ParquetInput.hpp"

namespace fpdb::store::server {

    class FlightInputSerialization {
    public:
        explicit FlightInputSerialization(InputSerializationType type);

        virtual ~FlightInputSerialization() = default;

        [[nodiscard]] InputSerializationType type() const;

        virtual nlohmann::json to_json() = 0;

        static tl::expected<std::shared_ptr<FlightInputSerialization>, std::string>
        parse_json(const nlohmann::json &json);

    private:
        InputSerializationType type_;
    };

    class FlightCSVInputSerialization : public FlightInputSerialization {
    public:
        explicit FlightCSVInputSerialization(const CSVInput &csv_input);

        static std::shared_ptr<FlightCSVInputSerialization> make(const CSVInput &csv_input);

        nlohmann::json to_json() override;

        static tl::expected<std::shared_ptr<FlightCSVInputSerialization>, std::string>
        parse_json(const nlohmann::json &json);

    private:
        CSVInput csv_input;
    };

    class FlightJSONInputSerialization : public FlightInputSerialization {
    public:
        FlightJSONInputSerialization(/*const sql::json::JSONInput& json_input*/);

        static std::shared_ptr<FlightJSONInputSerialization> make(/*const sql::json::JSONInput& json_input*/);

        nlohmann::json to_json() override;

        static tl::expected<std::shared_ptr<FlightJSONInputSerialization>, std::string>
        parse_json(const nlohmann::json &json);

    private:
    };

    class FlightParquetInputSerialization : public FlightInputSerialization {
    public:
        explicit FlightParquetInputSerialization(const ParquetInput &parquet_input);

        static std::shared_ptr<FlightParquetInputSerialization> make(const ParquetInput &parquet_input);

        nlohmann::json to_json() override;

        static tl::expected<std::shared_ptr<FlightParquetInputSerialization>, std::string>
        parse_json(const nlohmann::json &json);

    private:
    };

}

#endif //FPDB_FLIGHTINPUTSERIALIZATION_HPP
