//
// Created by czk on 09/04/22.
//

#include <fpdb/executor/ModeCtrl.h>
#include <fpdb/util/Util.h>

using namespace fpdb::util;

namespace fpdb::executor {
ModeCtrl::ModeCtrl(bool external) {
    if (external) {
        std::unordered_map<std::string, std::string> config = readConfig("mode.conf");
        _mapping.insert({POpType::AGGREGATE, config["AGGREGATE"]});
        _mapping.insert({POpType::COLLATE, config["COLLATE"]});
        _mapping.insert({POpType::FILE_SCAN, config["FILE_SCAN"]});
        _mapping.insert({POpType::FILTER, config["FILTER"]});
        _mapping.insert({POpType::GROUP, config["GROUP"]});
        _mapping.insert({POpType::HASH_JOIN_BUILD, config["HASH_JOIN_BUILD"]});
        _mapping.insert({POpType::HASH_JOIN_PROBE, config["HASH_JOIN_PROBE"]});
        _mapping.insert({POpType::SHUFFLE, config["SHUFFLE"]});
        _mapping.insert({POpType::SORT, config["SORT"]});
    } else {
        _mapping.insert({POpType::AGGREGATE, pullup});
        _mapping.insert({POpType::COLLATE, pullup});
        _mapping.insert({POpType::FILE_SCAN, pushdown});
        _mapping.insert({POpType::FILTER, pullup});
        _mapping.insert({POpType::GROUP, pullup});
        _mapping.insert({POpType::HASH_JOIN_BUILD, pullup});
        _mapping.insert({POpType::HASH_JOIN_PROBE, pullup});
        _mapping.insert({POpType::SHUFFLE, pullup});
        _mapping.insert({POpType::SORT, pullup});
    }
    
}

ModeCtrl::~ModeCtrl() {
    //nop
}

bool ModeCtrl::canPushdown(POpType type) {
    auto mode = _mapping.find(type);
    if (mode == _mapping.end() || 
        mode->second != pushdown) {
            return false;
    } else {
        return true;
    }
}

}