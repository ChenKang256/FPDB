//
// Created by Czk on 08/01/22.
//


#ifndef FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_MESSAGE_DEBUGMESSAGE_H
#define FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_MESSAGE_DEBUGMESSAGE_H

#include <fpdb/executor/message/Message.h>
#include <memory>

namespace fpdb::executor::message {

/**
 * Message containing a list of tuples
 */
class DebugMessage : public Message {

public:
  explicit DebugMessage(std::string sender);
  DebugMessage() = default;
  DebugMessage(const DebugMessage&) = default;
  DebugMessage& operator=(const DebugMessage&) = default;
  ~DebugMessage() override = default;

  std::string getTypeString() const override;

// caf inspect
public:
  template <class Inspector>
  friend bool inspect(Inspector& f, DebugMessage& msg) {
    return f.object(msg).fields(f.field("type", msg.type_),
                                f.field("sender", msg.sender_));
  }
};

}

#endif //FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_MESSAGE_DEBUGMESSAGE_H