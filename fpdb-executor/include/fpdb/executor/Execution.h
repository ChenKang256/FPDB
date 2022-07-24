//
// Created by Yifei Yang on 11/23/21.
//

#ifndef FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_EXECUTION_H
#define FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_EXECUTION_H

#include <fpdb/executor/physical/PhysicalOp.h>
#include <fpdb/executor/physical/PhysicalPlan.h>
#include <fpdb/executor/physical/POpDirectory.h>
#include <fpdb/executor/physical/collate/CollatePOp.h>
#include <fpdb/executor/physical/collate/CollatePOp2.h>
#include <fpdb/executor/physical/s3/S3SelectScanAbstractPOp.h>
#include <fpdb/tuple/TupleSet.h>
#include <caf/all.hpp>
#include <memory>

using namespace fpdb::executor::physical;
using namespace std;

namespace fpdb::executor {

inline constexpr const char *ExecutionRootActorName = "execution_root";

/**
 * Execution of a single query
 */
class Execution {

public:
  Execution(long queryId,
            const shared_ptr<::caf::actor_system> &actorSystem,
            const vector<::caf::node_id> &nodes,
            const ::caf::actor &segmentCacheActor,
            const shared_ptr<PhysicalPlan> &physicalPlan,
            bool isDistributed);
  ~Execution();

  long getQueryId() const;

  shared_ptr<TupleSet> execute();

  long getElapsedTime();
  shared_ptr<PhysicalOp> getPhysicalOp(const std::string &name);
  physical::s3::S3SelectScanStats getAggregateS3SelectScanStats();
  std::tuple<size_t, size_t, size_t> getFilterTimeNSInputOutputBytes();
  string showMetrics(bool showOpTimes = true, bool showScanMetrics = true);

  void write_graph(const string &file);

private:
  void boot();
  void start();
  void join();
  void close();

  ::caf::actor localSpawn(const shared_ptr<PhysicalOp> &op);
  ::caf::actor remoteSpawn(const shared_ptr<PhysicalOp> &op, int nodeId);

  long queryId_;
  shared_ptr<::caf::actor_system> actorSystem_;
  vector<::caf::node_id> nodes_;
  shared_ptr<::caf::scoped_actor> rootActor_;
  ::caf::actor segmentCacheActor_;
  shared_ptr<PhysicalPlan> physicalPlan_;
  bool isDistributed_;

  POpDirectory opDirectory_;
  [[maybe_unused]] physical::collate::CollateActor collateActorHandle_;
  shared_ptr<physical::collate::CollatePOp> legacyCollateOperator_;

  // for execution time
  chrono::steady_clock::time_point startTime_;
  chrono::steady_clock::time_point stopTime_;

};

}


#endif //FPDB_FPDB_EXECUTOR_INCLUDE_FPDB_EXECUTOR_EXECUTION_H
