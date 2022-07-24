//
// Created by matt on 4/2/22.
//

#ifndef FPDB_CMDTYPE_HPP
#define FPDB_CMDTYPE_HPP

#include <string>
#include <memory>

namespace fpdb::store::server {

    enum class CmdTypeId {
        SelectObjectContent
    };

    class CmdType {
    public:
        CmdType(CmdTypeId id, std::string name);

        [[nodiscard]] CmdTypeId id() const;

        [[nodiscard]] const std::string &name() const;

        static std::shared_ptr<CmdType> select_object_content();

    private:
        CmdTypeId id_;
        std::string name_;
    };
}

#endif //FPDB_CMDTYPE_HPP
