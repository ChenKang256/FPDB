//
// Created by matt on 4/2/22.
//

#include <fmt/format.h>

#include "fpdb/store/server/FlightInputSerialization.hpp"

namespace fpdb::store::server {

    constexpr std::string_view CSVJSONName = "csv";
    constexpr std::string_view FileHeaderInfoJSONName = "file-header-info";
    constexpr std::string_view FileHeaderInfoNoneJSONValue = "NONE";
    constexpr std::string_view FileHeaderInfoIgnoreJSONValue = "IGNORE";
    constexpr std::string_view FileHeaderInfoUseJSONValue = "USE";
    constexpr std::string_view JSONJSONName = "json";
    constexpr std::string_view ParquetJSONName = "parquet";

    tl::expected<std::shared_ptr<FlightInputSerialization>, std::string>
    FlightInputSerialization::parse_json(const nlohmann::json &json) {

        if (json.is_object()) {
            if (json.contains(CSVJSONName.data())) {
                return FlightCSVInputSerialization::parse_json(json[CSVJSONName.data()]);
            }

            if (json.contains(JSONJSONName.data())) {
                return FlightJSONInputSerialization::parse_json(json[JSONJSONName.data()]);
            }

            if (json.contains(ParquetJSONName.data())) {
                return FlightParquetInputSerialization::parse_json(json[ParquetJSONName.data()]);
            }
        }

        return tl::make_unexpected(fmt::format("Cannot parse InputSerialization JSON"));
    }

    FlightInputSerialization::FlightInputSerialization(InputSerializationType type) : type_(type) {
    }

    InputSerializationType FlightInputSerialization::type() const {
        return type_;
    }

    FlightCSVInputSerialization::FlightCSVInputSerialization(const CSVInput &csv_input)
            : FlightInputSerialization(InputSerializationType::CSV), csv_input(csv_input) {
    }

    std::shared_ptr<FlightCSVInputSerialization> FlightCSVInputSerialization::make(const CSVInput &csv_input) {
        return std::make_shared<FlightCSVInputSerialization>(csv_input);
    }

    nlohmann::json FlightCSVInputSerialization::to_json() {

        nlohmann::json input_serialization;

        nlohmann::json csv;

        //  rapidjson::Value
        //  allow_quoted_record_delimiter(input_serialization_.csv_input().value().allow_quoted_record_delimiter() ?
        //  rapidjson::kTrueType : rapidjson::kFalseType); csv.AddMember("allow-quoted-record-delimiter",
        //  allow_quoted_record_delimiter, document.GetAllocator());

        //  rapidjson::Value comments(rapidjson::kStringType);
        //  comments.SetString("#");
        //  csv.AddMember("comments", comments, document.GetAllocator());

        //  rapidjson::Value field_delimiter(rapidjson::kStringType);
        //  field_delimiter.SetString(",");
        //  csv.AddMember("field-delimiter", field_delimiter, document.GetAllocator());

        nlohmann::json file_header_info;
        switch (csv_input.file_header_info()) {
            case FileHeaderInfo::None:
                file_header_info = FileHeaderInfoNoneJSONValue.data();
            case FileHeaderInfo::Ignore:
                file_header_info = FileHeaderInfoIgnoreJSONValue.data();
            case FileHeaderInfo::Use:
                file_header_info = FileHeaderInfoUseJSONValue.data();
        }
        csv.emplace(FileHeaderInfoJSONName.data(), file_header_info);

        //  rapidjson::Value quote_character(rapidjson::kStringType);
        //  quote_character.SetString("\"");
        //  csv.AddMember("quote-character", quote_character, document.GetAllocator());

        //  rapidjson::Value quote_escape_character(rapidjson::kStringType);
        //  quote_escape_character.SetString("\"");
        //  csv.AddMember("quote-escape-character", quote_escape_character, document.GetAllocator());

        //  rapidjson::Value record_delimiter(rapidjson::kStringType);
        //  record_delimiter.SetString("\n");
        //  csv.AddMember("record-delimiter", record_delimiter, document.GetAllocator());

        input_serialization.emplace(CSVJSONName.data(), csv);

        return input_serialization;
    }

    tl::expected<std::shared_ptr<FlightCSVInputSerialization>, std::string>
    FlightCSVInputSerialization::parse_json(const nlohmann::json &json) {

        if (json.is_object()) {
            if (json.contains(FileHeaderInfoJSONName.data())) {
                const auto &file_header_info_value = json[FileHeaderInfoJSONName.data()];
                if (file_header_info_value.is_string()) {
                    const auto file_header_info = file_header_info_value.get<std::string>();
                    if (std::string_view(file_header_info) == FileHeaderInfoNoneJSONValue) {
                        return FlightCSVInputSerialization::make(CSVInput(FileHeaderInfo::None));
                    }
                    if (std::string_view(file_header_info) == FileHeaderInfoIgnoreJSONValue) {
                        return FlightCSVInputSerialization::make(CSVInput(FileHeaderInfo::Ignore));
                    }
                    if (std::string_view(file_header_info) == FileHeaderInfoUseJSONValue) {
                        return FlightCSVInputSerialization::make(CSVInput(FileHeaderInfo::Use));
                    }
                }
            }
        }

        return tl::make_unexpected(fmt::format("Cannot parse CSVInputSerialization JSON"));
    }

    FlightJSONInputSerialization::FlightJSONInputSerialization(/*const sql::json::JSONInput& json_input*/)
            : FlightInputSerialization(InputSerializationType::CSV) {
    }

    std::shared_ptr<FlightJSONInputSerialization> FlightJSONInputSerialization::make() {
        return std::make_shared<FlightJSONInputSerialization>(/*const sql::json::JSONInput& json_input*/);
    }

    nlohmann::json FlightJSONInputSerialization::to_json() {
        nlohmann::json input_serialization;

        nlohmann::json json;

        input_serialization.emplace(JSONJSONName.data(), json);

        return input_serialization;
    }

    tl::expected<std::shared_ptr<FlightJSONInputSerialization>, std::string>
    FlightJSONInputSerialization::parse_json(const nlohmann::json &json) {
        return tl::make_unexpected(fmt::format("Not yet implemented"));
    }

    FlightParquetInputSerialization::FlightParquetInputSerialization(const ParquetInput &parquet_input)
            : FlightInputSerialization(InputSerializationType::Parquet) {
    }

    std::shared_ptr<FlightParquetInputSerialization>
    FlightParquetInputSerialization::make(const ParquetInput &parquet_input) {
        return std::make_shared<FlightParquetInputSerialization>(parquet_input);
    }

    nlohmann::json FlightParquetInputSerialization::to_json() {
        nlohmann::json input_serialization;

        nlohmann::json parquet;

        input_serialization.emplace(ParquetJSONName.data(), parquet);

        return input_serialization;
    }

    tl::expected<std::shared_ptr<FlightParquetInputSerialization>, std::string>
    FlightParquetInputSerialization::parse_json(const nlohmann::json & /*json*/) {
        return tl::make_unexpected(fmt::format("Not yet implemented"));
    }

}