//
// Created by Partho on 3/26/22.
//

#include <fpdb/executor/physical/transform/PrePToLocalFSPTransformer.h>
#include <fpdb/executor/physical/prune/PartitionPruner.h>
#include <fpdb/executor/physical/file/FileScanPOp.h>
#include <fpdb/executor/physical/filter/FilterPOp.h>
#include <fpdb/executor/physical/cache/CacheLoadPOp.h>
#include <fpdb/executor/physical/merge/MergePOp.h>
#include <fpdb/catalogue/local-fs/LocalFSTable.h>
#include <fpdb/util/Util.h>

using namespace fpdb::catalogue::local_fs;
using namespace fpdb::util;

namespace fpdb::executor::physical {

PrePToLocalFSPTransformer::PrePToLocalFSPTransformer(uint prePOpId,
                                           int numNodes) :
  prePOpId_(prePOpId),
  numNodes_(numNodes) {}

pair<vector<shared_ptr<PhysicalOp>>, vector<shared_ptr<PhysicalOp>>>
PrePToLocalFSPTransformer::transformFilterableScan(const shared_ptr<FilterableScanPrePOp> &filterableScanPrePOp) {
  const auto &localFsTable = std::static_pointer_cast<LocalFSTable>(filterableScanPrePOp->getTable());
  const auto &partitions = (const vector<shared_ptr<Partition>> &) localFsTable->getLocalFSPartitions();
  const auto &partitionPredicates = PartitionPruner::prune(partitions, filterableScanPrePOp->getPredicate());
  vector<string> projectColumnNames{filterableScanPrePOp->getProjectColumnNames().begin(),
                                    filterableScanPrePOp->getProjectColumnNames().end()};

  return transformFilterableScan_(filterableScanPrePOp, partitionPredicates, projectColumnNames);
}

pair<vector<shared_ptr<PhysicalOp>>, vector<shared_ptr<PhysicalOp>>>
PrePToLocalFSPTransformer::transformFilterableScan_(const shared_ptr<FilterableScanPrePOp> &filterableScanPrePOp,
                                                    const unordered_map<shared_ptr<Partition>, shared_ptr<Expression>, PartitionPointerHash, PartitionPointerPredicate> &partitionPredicates,
                                                    const vector<string> &projectColumnNames) {
  vector<shared_ptr<PhysicalOp>> scanPOps, filterPOps;
  const auto &table = filterableScanPrePOp->getTable();

  /**
   * For each partition, construct:
   * a FileScan, a Filter if needed
   */
  uint partitionId = 0;
  for (const auto &partitionPredicateIt: partitionPredicates) {
    const auto &localFsPartition = static_pointer_cast<LocalFSPartition>(partitionPredicateIt.first);
    const auto &predicate = partitionPredicateIt.second;
    const auto &localFsObject = localFsPartition->getObject();
    const auto &localFsObjectName = localFsPartition->getObjectName();

    // project column names and its union with project column names
    vector<string> predicateColumnNames;
    if (predicate) {
      const auto predicateColumnNameSet = predicate->involvedColumnNames();
      predicateColumnNames.assign(predicateColumnNameSet.begin(), predicateColumnNameSet.end());
    }
    const auto &projPredColumnNames = union_(projectColumnNames, predicateColumnNames);

    // file scan
    std::pair<bool, std::string> remoteSpawnInfo = make_pair(true, "_onRemote");
    const auto &scanPOp = make_shared<file::FileScanPOp>(fmt::format("FileScan{}[{}]-{}", remoteSpawnInfo.second, prePOpId_, localFsObjectName),
                                                   projPredColumnNames,
                                                   partitionId % numNodes_,
                                                   localFsObject,
                                                   table,
                                                   true);
    scanPOp->setSpawnOnRemote(remoteSpawnInfo.first);  
    scanPOps.emplace_back(scanPOp);

    // filter
    if (predicate) {
      const auto &filterPOp = make_shared<filter::FilterPOp>(fmt::format("Filter{}[{}]-{}", remoteSpawnInfo.second, prePOpId_, localFsObjectName),
                                                             projectColumnNames,
                                                             partitionId % numNodes_,
                                                             predicate,
                                                             table);
      filterPOp->setSpawnOnRemote(remoteSpawnInfo.first); 
      filterPOps.emplace_back(filterPOp);
      scanPOp->produce(filterPOp);
      filterPOp->consume(scanPOp);
    }

    ++partitionId;
  }

  if (filterPOps.empty()) {
    return make_pair(scanPOps, scanPOps);
  } else {
    vector<shared_ptr<PhysicalOp>> allPOps;
    allPOps.insert(allPOps.end(), scanPOps.begin(), scanPOps.end());
    allPOps.insert(allPOps.end(), filterPOps.begin(), filterPOps.end());
    return make_pair(filterPOps, allPOps);
  }
}

}
