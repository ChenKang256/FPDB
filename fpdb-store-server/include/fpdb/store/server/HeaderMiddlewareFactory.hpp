//
// Created by matt on 4/2/22.
//

#ifndef FPDB_HEADERMIDDLEWAREFACTORY_HPP
#define FPDB_HEADERMIDDLEWAREFACTORY_HPP

#include <arrow/flight/api.h>

namespace fpdb::store::server {

    class HeaderMiddlewareFactory : public ::arrow::flight::ServerMiddlewareFactory {

    public:
        ::arrow::Status StartCall(const ::arrow::flight::CallInfo& info, const ::arrow::flight::CallHeaders& incoming_headers,
                                  std::shared_ptr<::arrow::flight::ServerMiddleware>* middleware) override;
    };

}

#endif //FPDB_HEADERMIDDLEWAREFACTORY_HPP
