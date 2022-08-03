//
// Created by Czk on 08/03/22.
//

#include <fpdb/executor/physical/test/ReceivePOp.h>
#include <fpdb/executor/physical/Globals.h>
#include <fpdb/executor/message/DebugMessage.h>
#include <fpdb/expression/gandiva/BinaryExpression.h>
#include <fpdb/tuple/Globals.h>
#include <utility>

using namespace fpdb::executor::physical::test;
using namespace fpdb::cache;
using namespace fpdb::expression::gandiva;

ReceivePOp::ReceivePOp(std::string name,
               std::vector<std::string> projectColumnNames,
               int nodeId) :
	PhysicalOp(std::move(name), RECEIVE, std::move(projectColumnNames), nodeId) {}

std::string ReceivePOp::getTypeString() const {
  return "ReceivePOp";
}

void ReceivePOp::onReceive(const Envelope &Envelope) {
  const auto& message = Envelope.message();

  if (message.type() == MessageType::START) {
	  this->onStart();
  } else if (message.type() == MessageType::DEBUG) {
      this->onDebug();
    } else if (message.type() == MessageType::COMPLETE) {
      this->onComplete();
    } else {
    ctx()->notifyError("Unrecognized message type " + message.getTypeString());
  }
}

void ReceivePOp::onStart() {
    SPDLOG_DEBUG("Starting '{}'", name());
}

void ReceivePOp::onDebug() {
    SPDLOG_DEBUG("'{}' is alive!", name());
    cout << this->name() + " is alive!" << endl;
}

void ReceivePOp::onComplete() {
  ctx()->notifyComplete();
}

void ReceivePOp::clear() {
    //Noop
}
