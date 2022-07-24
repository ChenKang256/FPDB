//
// Created by matt on 4/2/22.
//

#include <fmt/format.h>

#include "fpdb/store/server/FlightSelectObjectContentRequest.hpp"

namespace fpdb::store::server {

    constexpr std::string_view ExpressionJSONName = "expression";
    constexpr std::string_view InputSerializationJSONName = "input-serialization";

    FlightSelectObjectContentRequest::FlightSelectObjectContentRequest(
            std::string expression, std::shared_ptr<FlightInputSerialization> input_serialization)
            : expression_(std::move(expression)), input_serialization_(std::move(input_serialization)) {
    }

    std::shared_ptr<FlightSelectObjectContentRequest>
    FlightSelectObjectContentRequest::make(const std::string &expression,
                                           std::shared_ptr<FlightInputSerialization> input_serialization) {
        return std::make_shared<FlightSelectObjectContentRequest>(expression, std::move(input_serialization));
    }

    const std::string &FlightSelectObjectContentRequest::expression() const {
        return expression_;
    }

    const std::shared_ptr<FlightInputSerialization> &FlightSelectObjectContentRequest::input_serialization() const {
        return input_serialization_;
    }

    nlohmann::json FlightSelectObjectContentRequest::to_json() {

        nlohmann::json value;

        value.emplace(ExpressionJSONName.data(), expression_.data());
        value.emplace(InputSerializationJSONName.data(), input_serialization_->to_json());

        return value;
    }

    std::string FlightSelectObjectContentRequest::serialize(bool pretty) {
        return to_json().dump(pretty ? 2 : -1);
    }

    tl::expected<std::shared_ptr<FlightSelectObjectContentRequest>, std::string>
    FlightSelectObjectContentRequest::from_json(const nlohmann::json &json) {
        if (json.is_object()) {
            if (json.contains(ExpressionJSONName.data())) {
                if (json[ExpressionJSONName.data()].is_string()) {
                    const auto expression = json[ExpressionJSONName.data()].get<std::string>();
                    if (json.contains(InputSerializationJSONName.data())) {
                        const auto &input_serialization_json = json[InputSerializationJSONName.data()];
                        auto maybe_input_serialization =
                                FlightInputSerialization::parse_json(input_serialization_json);
                        if (!maybe_input_serialization.has_value()) {
                            return tl::make_unexpected(maybe_input_serialization.error());
                        }
                        return FlightSelectObjectContentRequest::make(expression, maybe_input_serialization.value());
                    }
                }
            }
        }

        return tl::make_unexpected(fmt::format("Cannot parse SelectObjectContentRequest JSON"));
    }

    tl::expected<std::shared_ptr<FlightSelectObjectContentRequest>, std::string>
    FlightSelectObjectContentRequest::deserialize(const std::string &string) {
        try {
            auto document = nlohmann::json::parse(string);
            return from_json(document);
        }
        catch (nlohmann::json::parse_error &ex) {
            return tl::make_unexpected(ex.what());

        }
    }

}