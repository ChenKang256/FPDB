//
// Created by Czk on 08/03/22.
//

#include <fpdb/executor/physical/test/SendPOp.h>
#include <fpdb/executor/physical/Globals.h>
#include <fpdb/executor/message/DebugMessage.h>
#include <fpdb/expression/gandiva/BinaryExpression.h>
#include <fpdb/tuple/Globals.h>
#include <utility>

using namespace fpdb::executor::physical::test;
using namespace fpdb::cache;
using namespace fpdb::expression::gandiva;

SendPOp::SendPOp(std::string name,
               std::vector<std::string> projectColumnNames,
               int nodeId) :
	PhysicalOp(std::move(name), SEND, std::move(projectColumnNames), nodeId) {}

std::string SendPOp::getTypeString() const {
  return "SendPOp";
}

void SendPOp::onReceive(const Envelope &Envelope) {
  const auto& message = Envelope.message();

  if (message.type() == MessageType::START) {
	  this->onStart();
  } else {
    ctx()->notifyError("Unrecognized message type " + message.getTypeString());
  }
}

void SendPOp::onStart() {
    SPDLOG_DEBUG("Starting '{}'", name());
    ctx()->notifyDebug();
    ctx()->notifyComplete();
}

void SendPOp::clear() {
    //Noop
}
