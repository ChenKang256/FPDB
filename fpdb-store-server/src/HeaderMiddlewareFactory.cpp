//
// Created by matt on 4/2/22.
//

#include "fpdb/store/server/HeaderMiddlewareFactory.hpp"
#include "fpdb/store/server/HeaderMiddleware.hpp"

namespace fpdb::store::server {

    ::arrow::Status HeaderMiddlewareFactory::StartCall(const ::arrow::flight::CallInfo &info,
                                                       const ::arrow::flight::CallHeaders &incoming_headers,
                                                       std::shared_ptr<::arrow::flight::ServerMiddleware> *middleware) {
        *middleware = std::make_shared<HeaderMiddleware>(incoming_headers);
        return ::arrow::Status::OK();
    }

}