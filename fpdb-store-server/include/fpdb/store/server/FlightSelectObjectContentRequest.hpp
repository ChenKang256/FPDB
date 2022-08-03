//
// Created by matt on 4/2/22.
//

#ifndef FPDB_FLIGHTSELECTOBJECTCONTENTREQUEST_HPP
#define FPDB_FLIGHTSELECTOBJECTCONTENTREQUEST_HPP

#include <string>
#include <memory>

#include <tl/expected.hpp>
#include <nlohmann/json.hpp>

#include "fpdb/store/server/FlightInputSerialization.hpp"

namespace fpdb::store::server {

    class FlightSelectObjectContentRequest {
    public:
        FlightSelectObjectContentRequest(std::string expression,
                                         std::shared_ptr<FlightInputSerialization> input_serialization);

        static std::shared_ptr<FlightSelectObjectContentRequest>
        make(const std::string &expression, std::shared_ptr<FlightInputSerialization> input_serialization);

        [[nodiscard]] const std::string &expression() const;

        [[nodiscard]] const std::shared_ptr<FlightInputSerialization> &input_serialization() const;

        nlohmann::json to_json();

        std::string serialize(bool pretty = false);

        static tl::expected<std::shared_ptr<FlightSelectObjectContentRequest>, std::string>
        from_json(const nlohmann::json &json);

        static tl::expected<std::shared_ptr<FlightSelectObjectContentRequest>, std::string>
        deserialize(const std::string &command_string);

    private:
        std::string expression_;
        std::shared_ptr<FlightInputSerialization> input_serialization_;
    };
}

#endif //FPDB_FLIGHTSELECTOBJECTCONTENTREQUEST_HPP
