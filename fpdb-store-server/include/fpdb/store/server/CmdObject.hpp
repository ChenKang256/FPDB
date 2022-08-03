//
// Created by matt on 4/2/22.
//

#ifndef FPDB_CMDOBJECT_HPP
#define FPDB_CMDOBJECT_HPP

#include <memory>

#include "CmdType.hpp"
#include "FlightSelectObjectContentRequest.hpp"

namespace fpdb::store::server {

/**
 * Flight descriptor cmd
 *
 */
    class CmdObject {
    public:
        explicit CmdObject(std::shared_ptr<CmdType> type);

        virtual ~CmdObject() = default;

        [[nodiscard]] const std::shared_ptr<CmdType> &type() const;

        virtual nlohmann::json to_json() = 0;

        std::string serialize(bool pretty = false);

        static tl::expected<std::shared_ptr<CmdObject>, std::string> from_json(const nlohmann::json &json);

        static tl::expected<std::shared_ptr<CmdObject>, std::string> deserialize(const std::string &string);

    private:
        std::shared_ptr<CmdType> type_;
    };

    class SelectObjectContentCmd : public CmdObject {
    public:

        explicit SelectObjectContentCmd(std::shared_ptr<FlightSelectObjectContentRequest> select_object_content);

        static std::shared_ptr<SelectObjectContentCmd>
        make(std::shared_ptr<FlightSelectObjectContentRequest> select_object_content);

        [[nodiscard]] const std::shared_ptr<FlightSelectObjectContentRequest> &select_object_content() const;

        [[nodiscard]] nlohmann::json to_json() override;

        static tl::expected<std::shared_ptr<SelectObjectContentCmd>, std::string>
        deserialize(const std::string &command_string);

        static tl::expected<std::shared_ptr<SelectObjectContentCmd>, std::string> from_json(const nlohmann::json &json);

    private:
        std::shared_ptr<FlightSelectObjectContentRequest> select_object_content_;
    };
}

#endif //FPDB_CMDOBJECT_HPP
