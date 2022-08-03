//
// Created by matt on 4/2/22.
//

#ifndef FPDB_TICKETOBJECT_HPP
#define FPDB_TICKETOBJECT_HPP

#include <memory>

#include <arrow/flight/api.h>
#include <tl/expected.hpp>

#include "fpdb/store/server/TicketType.hpp"
#include "fpdb/store/server/FlightSelectObjectContentRequest.hpp"

namespace fpdb::store::server {
    /**
 * A structured representation of a Flight ticket. Concrete subclasses of type GetObject and SelectObjectContent ticket.
 *
 */
    class TicketObject {
    public:
        explicit TicketObject(std::shared_ptr<TicketType> type);

        virtual ~TicketObject() = default;

        virtual std::string serialize(bool pretty) = 0;

        ::arrow::flight::Ticket to_ticket(bool pretty);

        static tl::expected<std::shared_ptr<TicketObject>, std::string> deserialize(const std::string &ticket_string);

        static tl::expected<std::shared_ptr<TicketObject>, std::string>
        deserialize(const ::arrow::flight::Ticket &ticket);

        [[nodiscard]] const std::shared_ptr<TicketType> &type() const;

    private:
        std::shared_ptr<TicketType> type_;
    };

/**
 * Ticket for retrieving a whole object from the store.
 */
    class GetObjectTicket : public TicketObject {
    public:
        GetObjectTicket(std::string bucket, std::string object);

        static std::shared_ptr<GetObjectTicket> make(std::string bucket, std::string object);

        std::string serialize(bool pretty) override;

        [[nodiscard]] const std::string &bucket() const;

        [[nodiscard]] const std::string &object() const;

    private:
        std::string bucket_;
        std::string object_;
    };

/**
 * Ticket for executing and returning the results of a query on an object in the store.
 */
    class SelectObjectContentTicket : public TicketObject {
    public:
        SelectObjectContentTicket(std::string bucket, std::string object,
                                  std::shared_ptr<FlightSelectObjectContentRequest> select_object_content);

        static std::shared_ptr<SelectObjectContentTicket>
        make(std::string bucket, std::string object,
             std::shared_ptr<FlightSelectObjectContentRequest> select_object_content);

        std::string serialize(bool pretty) override;

        [[nodiscard]] const std::string &bucket() const;

        [[nodiscard]] const std::string &object() const;

        [[nodiscard]] const std::shared_ptr<FlightSelectObjectContentRequest> &select_object_content() const;

    private:
        std::string bucket_;
        std::string object_;
        std::shared_ptr<FlightSelectObjectContentRequest> select_object_content_;
    };
}

#endif //FPDB_TICKETOBJECT_HPP
