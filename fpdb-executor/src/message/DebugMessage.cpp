//
// Created by Czk on 08/01/22.
//

#include <fpdb/executor/message/DebugMessage.h>
#include <utility>

namespace fpdb::executor::message {

DebugMessage::DebugMessage(std::string sender) :
  Message(DEBUG, std::move(sender)) {
}

std::string DebugMessage::getTypeString() const {
  return "DebugMessage";
}

}