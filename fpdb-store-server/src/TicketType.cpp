//
// Created by matt on 4/2/22.
//

#include "fpdb/store/server/TicketType.hpp"

namespace fpdb::store::server {

    TicketType::TicketType(TicketTypeId id, std::string name) : id_(id), name_(std::move(name)) {
    }

    std::shared_ptr<TicketType> TicketType::get_object() {
        return std::make_shared<TicketType>(TicketTypeId::GetObject, "object");
    }

    std::shared_ptr<TicketType> TicketType::select_object_content() {
        return std::make_shared<TicketType>(TicketTypeId::SelectObjectContent, "select");
    }

    TicketTypeId TicketType::id() const {
        return id_;
    }

    const std::string& TicketType::name() const {
        return name_;
    }

}