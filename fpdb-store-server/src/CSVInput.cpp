//
// Created by matt on 4/2/22.
//

#include "fpdb/store/server/CSVInput.hpp"

namespace fpdb::store::server {

    CSVInput::CSVInput(FileHeaderInfo file_header_info) : file_header_info_(file_header_info) {
    }


    FileHeaderInfo &CSVInput::file_header_info() {
        return file_header_info_;
    }

    const FileHeaderInfo &CSVInput::file_header_info() const {
        return file_header_info_;
    }
}