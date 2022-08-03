//
// Created by Czk on 08/03/22.
//

#ifndef FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_PHYSICAL_TEST_RECEIVEPOP_H
#define FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_PHYSICAL_TEST_RECEIVEPOP_H

#include <fpdb/executor/physical/PhysicalOp.h>
#include <fpdb/executor/message/DebugMessage.h>
#include <fpdb/executor/message/CompleteMessage.h>
#include <fpdb/expression/gandiva/Expression.h>
#include <memory>

using namespace fpdb::executor::message;
using namespace fpdb::catalogue;

namespace fpdb::executor::physical::test {

class ReceivePOp : public PhysicalOp {

public:
  explicit ReceivePOp(std::string name,
                  std::vector<std::string> projectColumnNames,
                  int nodeId);
  ReceivePOp() = default;
  ReceivePOp(const ReceivePOp&) = default;
  ReceivePOp& operator=(const ReceivePOp&) = default;

  void onReceive(const Envelope &Envelope) override;
  void clear() override;
  std::string getTypeString() const override;

private:
  void onStart();
  void onDebug();
  void onComplete();

// caf inspect
public:
  template <class Inspector>
  friend bool inspect(Inspector& f, ReceivePOp& op) {
    return f.object(op).fields(f.field("name", op.name_),
                               f.field("type", op.type_),
                               f.field("projectColumnNames", op.projectColumnNames_),
                               f.field("nodeId", op.nodeId_),
                               f.field("queryId", op.queryId_),
                               f.field("opContext", op.opContext_),
                               f.field("producers", op.producers_),
                               f.field("consumers", op.consumers_));
  }
};
}

#endif //FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_PHYSICAL_TEST_RECEIVEPOP_H
