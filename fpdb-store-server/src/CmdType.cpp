//
// Created by matt on 4/2/22.
//

#include "fpdb/store/server/CmdType.hpp"

namespace fpdb::store::server {

    CmdType::CmdType(CmdTypeId id, std::string name) : id_(id), name_(std::move(name)) {
    }

    CmdTypeId CmdType::id() const {
        return id_;
    }

    const std::string &CmdType::name() const {
        return name_;
    }

    std::shared_ptr<CmdType> CmdType::select_object_content() {
        return std::make_shared<CmdType>(CmdTypeId::SelectObjectContent, "select-object-content");
    }

}
