//
// Created by Yifei Yang on 11/21/21.
//

#include <fpdb/executor/physical/transform/PrePToS3PTransformer.h>
#include <fpdb/executor/physical/prune/PartitionPruner.h>
#include <fpdb/executor/physical/s3/S3GetPOp.h>
#include <fpdb/executor/physical/s3/S3SelectPOp.h>
#include <fpdb/executor/physical/filter/FilterPOp.h>
#include <fpdb/executor/physical/cache/CacheLoadPOp.h>
#include <fpdb/executor/physical/merge/MergePOp.h>
#include <fpdb/catalogue/s3/S3Table.h>
#include <fpdb/util/Util.h>

using namespace fpdb::catalogue::s3;
using namespace fpdb::util;

namespace fpdb::executor::physical {

PrePToS3PTransformer::PrePToS3PTransformer(uint prePOpId,
                                           const shared_ptr<AWSClient> &awsClient,
                                           const shared_ptr<Mode> &mode,
                                           int numNodes) :
  prePOpId_(prePOpId),
  awsClient_(awsClient),
  mode_(mode),
  numNodes_(numNodes) {}

pair<vector<shared_ptr<PhysicalOp>>, vector<shared_ptr<PhysicalOp>>>
PrePToS3PTransformer::transformFilterableScan(const shared_ptr<FilterableScanPrePOp> &filterableScanPrePOp) {
  const auto &s3Table = std::static_pointer_cast<S3Table>(filterableScanPrePOp->getTable());
  const auto &partitions = (const vector<shared_ptr<Partition>> &) s3Table->getS3Partitions();
  const auto &partitionPredicates = PartitionPruner::prune(partitions, filterableScanPrePOp->getPredicate());
  vector<string> projectColumnNames{filterableScanPrePOp->getProjectColumnNames().begin(),
                                    filterableScanPrePOp->getProjectColumnNames().end()};

  switch (mode_->id()) {
    case PULL_UP:
      return transformFilterableScanPullup(filterableScanPrePOp, partitionPredicates, projectColumnNames);
    case PUSHDOWN_ONLY:
      return transformFilterableScanPushdown(filterableScanPrePOp, partitionPredicates, projectColumnNames);
    case CACHING_ONLY:
      return transformFilterableScanCachingOnly(filterableScanPrePOp, partitionPredicates, projectColumnNames);
    case HYBRID:
      return transformFilterableScanHybrid(filterableScanPrePOp, partitionPredicates, projectColumnNames);
    default:
      throw runtime_error(fmt::format("Unsupported mode: {}", mode_->toString()));
  }
}

pair<vector<shared_ptr<PhysicalOp>>, vector<shared_ptr<PhysicalOp>>>
PrePToS3PTransformer::transformFilterableScanPullup(const shared_ptr<FilterableScanPrePOp> &filterableScanPrePOp,
                                                    const unordered_map<shared_ptr<Partition>, shared_ptr<Expression>, PartitionPointerHash, PartitionPointerPredicate> &partitionPredicates,
                                                    const vector<string> &projectColumnNames) {
  vector<shared_ptr<PhysicalOp>> scanPOps, filterPOps;
  const auto &table = filterableScanPrePOp->getTable();

  /**
   * For each partition, construct:
   * a S3Get, a Filter if needed
   */
  uint partitionId = 0;
  for (const auto &partitionPredicateIt: partitionPredicates) {
    const auto &s3Partition = static_pointer_cast<S3Partition>(partitionPredicateIt.first);
    const auto &predicate = partitionPredicateIt.second;
    const auto &s3Bucket = s3Partition->getBucket();
    const auto &s3Object = s3Partition->getObject();
    pair<long, long> scanRange{0, s3Partition->getNumBytes()};

    // project column names and its union with project column names
    vector<string> predicateColumnNames;
    if (predicate) {
      const auto predicateColumnNameSet = predicate->involvedColumnNames();
      predicateColumnNames.assign(predicateColumnNameSet.begin(), predicateColumnNameSet.end());
    }
    const auto &projPredColumnNames = union_(projectColumnNames, predicateColumnNames);

    // s3 get
    const auto &scanPOp = make_shared<s3::S3GetPOp>(fmt::format("S3Get[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                   projPredColumnNames,
                                                   partitionId % numNodes_,
                                                   s3Bucket,
                                                   s3Object,
                                                   scanRange.first,
                                                   scanRange.second,
                                                   table,
                                                   awsClient_,
                                                   true,
                                                   false);
    scanPOps.emplace_back(scanPOp);

    // filter
    if (predicate) {
      const auto &filterPOp = make_shared<filter::FilterPOp>(fmt::format("Filter[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                             projectColumnNames,
                                                             partitionId % numNodes_,
                                                             predicate,
                                                             table);
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

pair<vector<shared_ptr<PhysicalOp>>, vector<shared_ptr<PhysicalOp>>>
PrePToS3PTransformer::transformFilterableScanPushdown(const shared_ptr<FilterableScanPrePOp> &filterableScanPrePOp,
                                                      const unordered_map<shared_ptr<Partition>, shared_ptr<Expression>, PartitionPointerHash, PartitionPointerPredicate> &partitionPredicates,
                                                      const vector<string> &projectColumnNames) {
  vector<shared_ptr<PhysicalOp>> pOps;
  const auto &table = filterableScanPrePOp->getTable();

  /**
   * For each partition, construct:
   * a S3Select
   */
  uint partitionId = 0;
  for (const auto &partitionPredicateIt: partitionPredicates) {
    const auto &s3Partition = static_pointer_cast<S3Partition>(partitionPredicateIt.first);
    const auto &predicate = partitionPredicateIt.second;
    const auto &s3Bucket = s3Partition->getBucket();
    const auto &s3Object = s3Partition->getObject();
    const auto &filterSql = genFilterSql(predicate);
    pair<long, long> scanRange{0, s3Partition->getNumBytes()};

    // s3 select
    pOps.emplace_back(make_shared<s3::S3SelectPOp>(fmt::format("S3Select[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                   projectColumnNames,
                                                   partitionId % numNodes_,
                                                   s3Bucket,
                                                   s3Object,
                                                   filterSql,
                                                   scanRange.first,
                                                   scanRange.second,
                                                   table,
                                                   awsClient_,
                                                   true,
                                                   false));

    ++partitionId;
  }

  return make_pair(pOps, pOps);
}

pair<vector<shared_ptr<PhysicalOp>>, vector<shared_ptr<PhysicalOp>>>
PrePToS3PTransformer::transformFilterableScanCachingOnly(const shared_ptr<FilterableScanPrePOp> &filterableScanPrePOp,
                                                         const unordered_map<shared_ptr<Partition>, shared_ptr<Expression>, PartitionPointerHash, PartitionPointerPredicate> &partitionPredicates,
                                                         const vector<string> &projectColumnNames) {
  vector<shared_ptr<PhysicalOp>> selfConnDownPOps, allPOps;
  const auto &table = filterableScanPrePOp->getTable();

  /**
   * For each partition, construct:
   * a CacheLoad, a S3Get, a Merge, a Filter if needed
   */
  uint partitionId = 0;
  for (const auto &partitionPredicateIt: partitionPredicates) {
    const auto &s3Partition = static_pointer_cast<S3Partition>(partitionPredicateIt.first);
    const auto &predicate = partitionPredicateIt.second;
    const auto &s3Bucket = s3Partition->getBucket();
    const auto &s3Object = s3Partition->getObject();
    pair<long, long> scanRange{0, s3Partition->getNumBytes()};

    // project column names and its union with project column names
    vector<string> predicateColumnNames;
    if (predicate) {
      const auto predicateColumnNameSet = predicate->involvedColumnNames();
      predicateColumnNames.assign(predicateColumnNameSet.begin(), predicateColumnNameSet.end());
    }
    const auto &projPredColumnNames = union_(projectColumnNames, predicateColumnNames);

    // weighted segment keys
    vector<shared_ptr<SegmentKey>> weightedSegmentKeys;
    weightedSegmentKeys.reserve(projPredColumnNames.size());
    for (const auto &weightedColumnName: projPredColumnNames) {
      weightedSegmentKeys.emplace_back(
              SegmentKey::make(s3Partition, weightedColumnName, SegmentRange::make(scanRange.first, scanRange.second)));
    }

    // cache load
    const auto cacheLoadPOp = make_shared<cache::CacheLoadPOp>(fmt::format("CacheLoad[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                               projectColumnNames,
                                                               partitionId % numNodes_,
                                                               predicateColumnNames,
                                                               projPredColumnNames,
                                                               s3Partition,
                                                               scanRange.first,
                                                               scanRange.second,
                                                               awsClient_->getAwsConfig()->getS3ClientType());
    allPOps.emplace_back(cacheLoadPOp);

    // s3 get
    const auto &scanPOp = make_shared<s3::S3GetPOp>(fmt::format("S3Get[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                    projPredColumnNames,
                                                    partitionId % numNodes_,
                                                    s3Bucket,
                                                    s3Object,
                                                    scanRange.first,
                                                    scanRange.second,
                                                    table,
                                                    awsClient_,
                                                    false,
                                                    true);
    allPOps.emplace_back(scanPOp);

    // merge
    const auto &mergePOp = make_shared<merge::MergePOp>(fmt::format("Merge[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                        projPredColumnNames,
                                                        partitionId % numNodes_);
    allPOps.emplace_back(mergePOp);

    // connect
    cacheLoadPOp->setHitOperator(mergePOp);
    cacheLoadPOp->setMissOperatorToCache(scanPOp);
    scanPOp->produce(mergePOp);
    scanPOp->consume(cacheLoadPOp);
    mergePOp->setLeftProducer(cacheLoadPOp);
    mergePOp->setRightProducer(scanPOp);

    // filter
    if (predicate) {
      const auto &filterPOp = make_shared<filter::FilterPOp>(fmt::format("Filter[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                             projectColumnNames,
                                                             partitionId % numNodes_,
                                                             predicate,
                                                             table,
                                                             weightedSegmentKeys);
      mergePOp->produce(filterPOp);
      filterPOp->consume(mergePOp);
      allPOps.emplace_back(filterPOp);
      selfConnDownPOps.emplace_back(filterPOp);
    } else {
      selfConnDownPOps.emplace_back(mergePOp);
    }

    ++partitionId;
  }

  return make_pair(selfConnDownPOps, allPOps);
}

pair<vector<shared_ptr<PhysicalOp>>, vector<shared_ptr<PhysicalOp>>>
PrePToS3PTransformer::transformFilterableScanHybrid(const shared_ptr<FilterableScanPrePOp> &filterableScanPrePOp,
                                                    const unordered_map<shared_ptr<Partition>, shared_ptr<Expression>, PartitionPointerHash, PartitionPointerPredicate> &partitionPredicates,
                                                    const vector<string> &projectColumnNames) {
  vector<shared_ptr<PhysicalOp>> selfConnDownPOps, allPOps;
  const auto &table = filterableScanPrePOp->getTable();

  /**
   * For each partition, construct:
   * a CacheLoad, a S3Get which is to pull up segments to cache, a Merge, a Filter if needed
   * a S3Select, a second Merge for local filtered segments + S3Select result
   */
  uint partitionId = 0;
  for (const auto &partitionPredicateIt: partitionPredicates) {
    const auto &s3Partition = static_pointer_cast<S3Partition>(partitionPredicateIt.first);
    const auto &predicate = partitionPredicateIt.second;
    const auto &s3Bucket = s3Partition->getBucket();
    const auto &s3Object = s3Partition->getObject();
    const auto &filterSql = genFilterSql(predicate);
    pair<long, long> scanRange{0, s3Partition->getNumBytes()};

    // project column names and its union with project column names
    vector<string> predicateColumnNames;
    if (predicate) {
      const auto predicateColumnNameSet = predicate->involvedColumnNames();
      predicateColumnNames.assign(predicateColumnNameSet.begin(), predicateColumnNameSet.end());
    }
    const auto &projPredColumnNames = union_(projectColumnNames, predicateColumnNames);

    // weighted segment keys
    vector<shared_ptr<SegmentKey>> weightedSegmentKeys;
    weightedSegmentKeys.reserve(projPredColumnNames.size());
    for (const auto &weightedColumnName: projPredColumnNames) {
      weightedSegmentKeys.emplace_back(
              SegmentKey::make(s3Partition, weightedColumnName, SegmentRange::make(scanRange.first, scanRange.second)));
    }

    // cache load
    const auto cacheLoadPOp = make_shared<cache::CacheLoadPOp>(fmt::format("CacheLoad[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                               projectColumnNames,
                                                               partitionId % numNodes_,
                                                               predicateColumnNames,
                                                               projPredColumnNames,
                                                               s3Partition,
                                                               scanRange.first,
                                                               scanRange.second,
                                                               awsClient_->getAwsConfig()->getS3ClientType());
    allPOps.emplace_back(cacheLoadPOp);

    // s3 select (cache)
    const auto &scanPOp = make_shared<s3::S3SelectPOp>(fmt::format("S3Select(cache)[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                       projPredColumnNames,
                                                       partitionId % numNodes_,
                                                       s3Bucket,
                                                       s3Object,
                                                       "",
                                                       scanRange.first,
                                                       scanRange.second,
                                                       table,
                                                       awsClient_,
                                                       false,
                                                       true);
    allPOps.emplace_back(scanPOp);

    // first merge
    const auto &mergePOp1 = make_shared<merge::MergePOp>(fmt::format("merge1[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                         projPredColumnNames,
                                                         partitionId % numNodes_);
    allPOps.emplace_back(mergePOp1);

    // connect cache load, s3 select (to cache) and first merge
    cacheLoadPOp->setHitOperator(mergePOp1);
    cacheLoadPOp->setMissOperatorToCache(scanPOp);
    scanPOp->produce(mergePOp1);
    scanPOp->consume(cacheLoadPOp);
    mergePOp1->setLeftProducer(cacheLoadPOp);
    mergePOp1->setRightProducer(scanPOp);

    // filter
    shared_ptr<PhysicalOp> localResultPOp;
    if (predicate) {
      const auto &filterPOp = make_shared<filter::FilterPOp>(fmt::format("Filter[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                             projectColumnNames,
                                                             partitionId % numNodes_,
                                                             predicate,
                                                             table,
                                                             weightedSegmentKeys);
      allPOps.emplace_back(filterPOp);
      mergePOp1->produce(filterPOp);
      filterPOp->consume(mergePOp1);
      localResultPOp = filterPOp;
    } else {
      localResultPOp = mergePOp1;
    }

    // s3 select (pushdown)
    const auto &selectPOp = make_shared<s3::S3SelectPOp>(fmt::format("S3Select(pushdown)[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                         projectColumnNames,
                                                         partitionId % numNodes_,
                                                         s3Bucket,
                                                         s3Object,
                                                         filterSql,
                                                         scanRange.first,
                                                         scanRange.second,
                                                         table,
                                                         awsClient_,
                                                         false,
                                                         false,
                                                         weightedSegmentKeys);
    allPOps.emplace_back(selectPOp);

    // second merge
    const auto &mergePOp2 = make_shared<merge::MergePOp>(fmt::format("merge2[{}]-{}/{}", prePOpId_, s3Bucket, s3Object),
                                                         projectColumnNames,
                                                         partitionId % numNodes_);
    allPOps.emplace_back(mergePOp2);

    // connect op of local result, s3 select (pushdown) and second merge
    cacheLoadPOp->setMissOperatorToPushdown(selectPOp);
    localResultPOp->produce(mergePOp2);
    selectPOp->consume(cacheLoadPOp);
    selectPOp->produce(mergePOp2);
    mergePOp2->setLeftProducer(localResultPOp);
    mergePOp2->setRightProducer(selectPOp);

    // second merge is the connect op to downstream
    selfConnDownPOps.emplace_back(mergePOp2);

    ++partitionId;
  }

  return make_pair(selfConnDownPOps, allPOps);
}

string PrePToS3PTransformer::genFilterSql(const shared_ptr<Expression> &predicate) {
  if (predicate != nullptr) {
    std::string filterStr = predicate->alias();
    return " where " + filterStr;
  } else {
    return "";
  }
}

}
