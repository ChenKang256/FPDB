//
// Created by matt on 4/2/22.
//

#include "fpdb/store/server/CmdObject.hpp"

#include <fmt/format.h>

namespace fpdb::store::server {

    static constexpr std::string_view SelectObjectContentRequestJSONName = "select-object-content-request";

    CmdObject::CmdObject(std::shared_ptr<CmdType> type) : type_(std::move(type)) {
    }

    const std::shared_ptr<CmdType> &CmdObject::type() const {
        return type_;
    }

    std::string CmdObject::serialize(bool pretty) {
        return to_json().dump(pretty ? 2 : -1);
    }

    tl::expected<std::shared_ptr<CmdObject>, std::string> CmdObject::from_json(const nlohmann::json &json) {
        if (json.is_object()) {
            if (json.contains(SelectObjectContentRequestJSONName.data())) {
                return SelectObjectContentCmd::from_json(json[SelectObjectContentRequestJSONName.data()]);
            }
        }

        return tl::make_unexpected(fmt::format("Cannot parse FlightDescriptor cmd JSON"));
    }

    tl::expected<std::shared_ptr<CmdObject>, std::string> CmdObject::deserialize(const std::string &string) {
        try {
            auto document = nlohmann::json::parse(string);

            if (document.is_object()) {
                if (document.contains(SelectObjectContentRequestJSONName.data())) {
                    return SelectObjectContentCmd::from_json(document[SelectObjectContentRequestJSONName.data()]);
                }
            }

            return tl::make_unexpected(fmt::format("Cannot parse FlightDescriptor cmd JSON '{}'", string));
        }
        catch (nlohmann::json::parse_error &ex) {
            return tl::make_unexpected(ex.what());
        }
    }

    SelectObjectContentCmd::SelectObjectContentCmd(
            std::shared_ptr<FlightSelectObjectContentRequest> select_object_content)
            : CmdObject(CmdType::select_object_content()), select_object_content_(std::move(select_object_content)) {
    }

    std::shared_ptr<SelectObjectContentCmd>
    SelectObjectContentCmd::make(std::shared_ptr<FlightSelectObjectContentRequest> select_object_content) {
        return std::make_shared<SelectObjectContentCmd>(std::move(select_object_content));
    }

    const std::shared_ptr<FlightSelectObjectContentRequest> &SelectObjectContentCmd::select_object_content() const {
        return select_object_content_;
    }

    nlohmann::json SelectObjectContentCmd::to_json() {
        nlohmann::json value;
        value.emplace(SelectObjectContentRequestJSONName.data(), select_object_content_->to_json());
        return value;
    }

    tl::expected<std::shared_ptr<SelectObjectContentCmd>, std::string>
    SelectObjectContentCmd::from_json(const nlohmann::json &json) {
        auto
                maybe_select_object_content = FlightSelectObjectContentRequest::from_json(json);
        if (!maybe_select_object_content.has_value()) {
            return tl::make_unexpected(maybe_select_object_content.error());
        }
        return SelectObjectContentCmd::make(maybe_select_object_content.value());
    }

    tl::expected<std::shared_ptr<SelectObjectContentCmd>, std::string>
    SelectObjectContentCmd::deserialize(const std::string &string) {
        auto
                maybe_select_object_content = FlightSelectObjectContentRequest::deserialize(string);
        if (!maybe_select_object_content.has_value()) {
            return tl::make_unexpected(maybe_select_object_content.error());
        }
        return SelectObjectContentCmd::make(maybe_select_object_content.value());
    }

}