//
// Created by matt on 4/2/22.
//

#ifndef FPDB_CSVINPUT_HPP
#define FPDB_CSVINPUT_HPP

#include "FileHeaderInfo.hpp"

namespace fpdb::store::server {

    class CSVInput {
    public:
        explicit CSVInput(FileHeaderInfo file_header_info);

        [[nodiscard]] FileHeaderInfo &file_header_info();

        [[nodiscard]] const FileHeaderInfo &file_header_info() const;

    private:
        FileHeaderInfo file_header_info_;
    };
}

#endif //FPDB_CSVINPUT_HPP
