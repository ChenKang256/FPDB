//
// Created by matt on 4/2/22.
//

#ifndef FPDB_TICKETTYPE_HPP
#define FPDB_TICKETTYPE_HPP

#include <string>
#include <memory>

namespace fpdb::store::server {

    enum class TicketTypeId {
        GetObject, SelectObjectContent
    };

    class TicketType {
    public:
        TicketType(TicketTypeId id, std::string name);

        [[nodiscard]] TicketTypeId id() const;

        [[nodiscard]] const std::string &name() const;

        static std::shared_ptr<TicketType> get_object();

        static std::shared_ptr<TicketType> select_object_content();

    private:
        TicketTypeId id_;
        std::string name_;
    };

}

#endif //FPDB_TICKETTYPE_HPP
