//
// Created by matt on 4/2/22.
//

#ifndef FPDB_HEADERMIDDLEWARE_HPP
#define FPDB_HEADERMIDDLEWARE_HPP

#include <arrow/flight/api.h>

namespace fpdb::store::server {

    class HeaderMiddleware : public ::arrow::flight::ServerMiddleware {
    public:
        explicit HeaderMiddleware(::arrow::flight::CallHeaders headers);

        [[nodiscard]] std::string name() const override;
        void SendingHeaders(::arrow::flight::AddCallHeaders* outgoing_headers) override;
        void CallCompleted(const ::arrow::Status& status) override;

        [[nodiscard]] const ::arrow::flight::CallHeaders& headers() const;

    private:
        ::arrow::flight::CallHeaders headers_;
    };

}

#endif //FPDB_HEADERMIDDLEWARE_HPP
