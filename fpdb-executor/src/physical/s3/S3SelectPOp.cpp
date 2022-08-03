//
// Created by Matt Woicik on 1/19/21.
//

#include <fpdb/executor/physical/s3/S3SelectPOp.h>
#include <fpdb/executor/physical/Globals.h>
#include <fpdb/executor/message/Message.h>
#include <fpdb/catalogue/format/CSVFormat.h>
#include <fpdb/cache/SegmentKey.h>
#include <fpdb/tuple/TupleSet.h>

#include <arrow/csv/reader.h>                               // for TableReader
#include <arrow/io/buffered.h>                              // for BufferedI...
#include <arrow/type_fwd.h>                                 // for default_m...
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/ratelimiter/DefaultRateLimiter.h>
#include <aws/s3/model/CSVInput.h>                          // for CSVInput
#include <aws/s3/model/CSVOutput.h>                         // for CSVOutput
#include <aws/s3/model/ExpressionType.h>                    // for Expressio...
#include <aws/s3/model/FileHeaderInfo.h>                    // for FileHeade...
#include <aws/s3/model/InputSerialization.h>                // for InputSeri...
#include <aws/s3/model/OutputSerialization.h>               // for OutputSer...
#include <aws/s3/model/RecordsEvent.h>                      // for RecordsEvent
#include <aws/s3/model/SelectObjectContentHandler.h>        // for SelectObj...
#include <aws/s3/model/StatsEvent.h>                        // for StatsEvent
#include <aws/s3/model/GetObjectRequest.h>                  // for GetObj...
#include <aws/s3/model/SelectObjectContentRequest.h>
#include <utility>
#include <memory>
#include <cstdlib>

namespace Aws::Utils::RateLimits { class RateLimiterInterface; }
namespace arrow { class MemoryPool; }

using namespace Aws;
using namespace Aws::Auth;
using namespace Aws::Http;
using namespace Aws::Client;
using namespace Aws::S3;
using namespace Aws::S3::Model;

using namespace fpdb::cache;
using namespace fpdb::catalogue::format;

namespace fpdb::executor::physical::s3 {

std::mutex SelectConvertLock;
int activeSelectConversions = 0;

S3SelectPOp::S3SelectPOp(std::string name,
               std::vector<std::string> projectColumnNames,
               int nodeId,
						   std::string s3Bucket,
						   std::string s3Object,
						   std::string filterSql,
						   int64_t startOffset,
						   int64_t finishOffset,
               std::shared_ptr<Table> table,
               std::shared_ptr<fpdb::aws::AWSClient> awsClient,
						   bool scanOnStart,
               bool toCache,
               std::vector<std::shared_ptr<fpdb::cache::SegmentKey>> weightedSegmentKeys) :
  S3SelectScanAbstractPOp(std::move(name),
                          S3_SELECT,
                          std::move(projectColumnNames),
                          nodeId,
                          std::move(s3Bucket),
                          std::move(s3Object),
                          startOffset,
                          finishOffset,
                          std::move(table),
                          std::move(awsClient),
                          scanOnStart,
                          toCache),
	filterSql_(std::move(filterSql)),
	weightedSegmentKeys_(std::move(weightedSegmentKeys)) {
}

std::string S3SelectPOp::getTypeString() const {
  return "S3SelectPOp";
}

std::shared_ptr<S3CSVParser> S3SelectPOp::generateCSVParser() {
  std::vector<std::shared_ptr<::arrow::Field>> fields;
  for (auto const &columnName: getProjectColumnNames()) {
    fields.emplace_back(table_->getSchema()->GetFieldByName(columnName));
  }
  auto csvTableFormat = std::static_pointer_cast<CSVFormat>(table_->getFormat());
  auto parser = std::make_shared<S3CSVParser>(getProjectColumnNames(),
                                              std::make_shared<::arrow::Schema>(fields),
                                              csvTableFormat->getFieldDelimiter());
  return parser;
}


InputSerialization S3SelectPOp::getInputSerialization() {
  InputSerialization inputSerialization;
  if (s3Object_.find("csv") != std::string::npos) {
    CSVInput csvInput;
    csvInput.SetFileHeaderInfo(FileHeaderInfo::USE);
    auto csvTableFormat = std::static_pointer_cast<CSVFormat>(table_->getFormat());
    std::string delimiter = std::string(1, csvTableFormat->getFieldDelimiter());
    csvInput.SetFieldDelimiter(Aws::String(delimiter));
    csvInput.SetRecordDelimiter("\n");
    inputSerialization.SetCSV(csvInput);
    if (s3Object_.find("gz") != std::string::npos) {
      inputSerialization.SetCompressionType(CompressionType::GZIP);
    } else if (s3Object_.find("bz2") != std::string::npos) {
      inputSerialization.SetCompressionType(CompressionType::BZIP2);
    }
  } else if (s3Object_.find("parquet") != std::string::npos) {
    ParquetInput parquetInput;
    inputSerialization.SetParquet(parquetInput);
  }
  return inputSerialization;
}

bool S3SelectPOp::scanRangeSupported() {
  // S3 only supports support uncompressed CSV and we don't yet support Parquet
  if (s3Object_.find("gz") != std::string::npos ||
      s3Object_.find("bz2") != std::string::npos) {
    return false;
  }
  return true;
}

std::shared_ptr<TupleSet> S3SelectPOp::s3Select(uint64_t startOffset, uint64_t endOffset) {
  // Create the necessary parser
  auto parser = generateCSVParser();

  // create s3select request (must create a new one for each call as different start/end offsets require a new
  // S3Select request object
  std::optional<std::string> optionalErrorMessage;

  Aws::String bucketName = Aws::String(s3Bucket_);

  SelectObjectContentRequest selectObjectContentRequest;
  selectObjectContentRequest.SetBucket(bucketName);
  selectObjectContentRequest.SetKey(Aws::String(s3Object_));

  // Airmettle says they do not fully support byte range scans so
  // leave it out when running with Airmettle.
  if (awsClient_->getAwsConfig()->getS3ClientType() != AIRMETTLE) {
    if (scanRangeSupported()) {
      ScanRange scanRange;
      scanRange.SetStart(startOffset);
      scanRange.SetEnd(endOffset);

      selectObjectContentRequest.SetScanRange(scanRange);
    }
  }
  selectObjectContentRequest.SetExpressionType(ExpressionType::SQL);

  // combine columns with filterSql
  std::string sql;
  for (size_t colIndex = 0; colIndex < getProjectColumnNames().size(); colIndex++) {
    if (colIndex == 0) {
      sql += getProjectColumnNames()[colIndex];
    } else {
      sql += ", " + getProjectColumnNames()[colIndex];
    }
  }
  sql = "select " + sql + " from s3Object" + filterSql_;

  selectObjectContentRequest.SetExpression(sql.c_str());

  InputSerialization inputSerialization = getInputSerialization();

  selectObjectContentRequest.SetInputSerialization(inputSerialization);

  CSVOutput csvOutput;
  OutputSerialization outputSerialization;
  outputSerialization.SetCSV(csvOutput);
  selectObjectContentRequest.SetOutputSerialization(outputSerialization);

  SelectObjectContentHandler handler;
  bool hasEndEvent = false;

  handler.SetRecordsEventCallback([&](const RecordsEvent &recordsEvent) {
    SPDLOG_DEBUG("S3 Select RecordsEvent  |  name: {}, size: {}",
                 name(),
                 recordsEvent.GetPayload().size());
    auto payload = recordsEvent.GetPayload();
    if (!payload.empty()) {
      // Airmettle doesn't trigger StatsEvent callback, so add up returned bytes here.
      if (awsClient_->getAwsConfig()->getS3ClientType() == AIRMETTLE) {
        splitReqLock_->lock();
        s3SelectScanStats_.returnedBytes += payload.size();
        splitReqLock_->unlock();
      }
      while (true) {
        if (SelectConvertLock.try_lock()) {
          if (activeSelectConversions < maxConcurrentArrowConversions) {
            activeSelectConversions++;
            SelectConvertLock.unlock();
            break;
          } else {
            SelectConvertLock.unlock();
          }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % variableSleepRetryTimeMS + minimumSleepRetryTimeMS));
      }
      std::chrono::steady_clock::time_point startConversionTime = std::chrono::steady_clock::now();

      s3Result_.insert(s3Result_.end(), payload.begin(), payload.end());

      std::chrono::steady_clock::time_point stopConversionTime = std::chrono::steady_clock::now();
      auto conversionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
              stopConversionTime - startConversionTime).count();
      SelectConvertLock.lock();
      activeSelectConversions--;
      SelectConvertLock.unlock();
      splitReqLock_->lock();
      s3SelectScanStats_.selectConvertTimeNS += conversionTime;
      s3SelectScanStats_.selectTransferTimeNS -= conversionTime;
      splitReqLock_->unlock();
    }
  });
  handler.SetStatsEventCallback([&](const StatsEvent &statsEvent) {
    SPDLOG_DEBUG("S3 Select StatsEvent  |  name: {}, scanned: {}, processed: {}, returned: {}",
                 name(),
                 statsEvent.GetDetails().GetBytesScanned(),
                 statsEvent.GetDetails().GetBytesProcessed(),
                 statsEvent.GetDetails().GetBytesReturned());
    splitReqLock_->lock();
    s3SelectScanStats_.processedBytes += statsEvent.GetDetails().GetBytesProcessed();
    if (awsClient_->getAwsConfig()->getS3ClientType() != AIRMETTLE) {
      s3SelectScanStats_.returnedBytes += statsEvent.GetDetails().GetBytesReturned();
    }
    splitReqLock_->unlock();
  });

  handler.SetEndEventCallback([&]() {
    SPDLOG_DEBUG("S3 Select EndEvent  |  name: {}",
                 name());
    hasEndEvent = true;
  });
  handler.SetOnErrorCallback([&](const AWSError<S3Errors> &errors) {
    SPDLOG_ERROR("S3 Select Error  |  name: {}, message: {}",
                 name(),
                 std::string(errors.GetMessage()));
    optionalErrorMessage = std::optional(errors.GetMessage());
  });

  selectObjectContentRequest.SetEventStreamHandler(handler);

  // retry loop for S3 Select request
  // Sleep for 0.01sec on failure, no need to busy spin the entire time while waiting to try again
  uint64_t retrySleepTimeMS = 10;
  while (true) {

    std::chrono::steady_clock::time_point startTransferTime = std::chrono::steady_clock::now();
    auto selectObjectContentOutcome = awsClient_->getS3Client()->SelectObjectContent(selectObjectContentRequest);
    std::chrono::steady_clock::time_point stopTransferTime = std::chrono::steady_clock::now();
    splitReqLock_->lock();
    s3SelectScanStats_.selectTransferTimeNS += std::chrono::duration_cast<std::chrono::nanoseconds>(
            stopTransferTime - startTransferTime).count();
    splitReqLock_->unlock();
    if (selectObjectContentOutcome.IsSuccess()) {
      break;
    }
    std::this_thread::sleep_for (std::chrono::milliseconds(retrySleepTimeMS));
  }

  // If the request doesn't complete we don't count it in our costs as these requests seem to fail before sending
  // messages to S3 (some internal AWS CPP SDK event most likely causes this).
  // This sometimes occurs when sending many S3 Select requests in parallel from our machine, though setting
  // maxConnections in AWSClient to a safe value mitigates this issue.

  return nullptr;
}

void S3SelectPOp::s3SelectIndividualReq(int reqNum, uint64_t startOffset, uint64_t endOffset) {
  std::shared_ptr<TupleSet> readTupleSet = s3Select(startOffset, endOffset);
  splitReqLock_->lock();
  splitReqNumToTable_.insert(std::pair<int, std::shared_ptr<arrow::Table>>(reqNum, readTupleSet->table()));
  splitReqLock_->unlock();
}

std::shared_ptr<TupleSet> S3SelectPOp::s3SelectParallelReqs() {
  int totalReqs = 0;
  uint64_t currentStartOffset = 0;

  // Spawn all of the requests
  std::vector<std::thread> threadVector = std::vector<std::thread>();
  while (currentStartOffset < finishOffset_) {
    totalReqs += 1;
    uint64_t reqEndOffset = currentStartOffset + DefaultS3RangeSize;
    if (reqEndOffset > finishOffset_) {
      reqEndOffset = finishOffset_;
    }
    // If there is only a little bit of data left to scan just combine it in this request rather than
    // starting a new request.
    if ((double) (finishOffset_ - reqEndOffset) < (double) (DefaultS3RangeSize * 0.30)) {
      reqEndOffset = finishOffset_;
    }
    threadVector.emplace_back(std::thread([&, totalReqs, currentStartOffset, reqEndOffset]() {
      s3SelectIndividualReq(totalReqs, currentStartOffset, reqEndOffset);
    }));
    currentStartOffset = reqEndOffset + 1;
  }

  // Wait for all requests to finish
  for (auto &t: threadVector) {
    t.join();
  }

  // Now join together all of the arrow tables
  std::vector<std::shared_ptr<arrow::Table>> tables;
  for (int i = 1; i <= totalReqs; i++) {
    std::shared_ptr<arrow::Table> currentTable = splitReqNumToTable_[i];
    // Don't need to concatenate empty tables
    if (currentTable->num_rows() > 0) {
      tables.push_back(currentTable);
    }
  }

  // Create and return the TupleSet result
  if (tables.empty()) {
    return TupleSet::makeWithEmptyTable();
  } else if (tables.size() == 1) {
    return fpdb::tuple::TupleSet::make(tables[0]);
  } else {
    const arrow::Result<std::shared_ptr<arrow::Table>> &res = arrow::ConcatenateTables(tables);
    if (!res.ok())
      abort();
    return fpdb::tuple::TupleSet::make(*res);
  }
}

std::shared_ptr<TupleSet> S3SelectPOp::readTuples() {
  std::shared_ptr<TupleSet> readTupleSet;

  if (getProjectColumnNames().empty()) {
    readTupleSet = TupleSet::makeWithEmptyTable();
  } else {

    SPDLOG_DEBUG("Reading From S3: {}", name());

    // Read columns from s3
    if (awsClient_->getAwsConfig()->getS3ClientType() == S3ClientType::S3 && scanRangeSupported()
        && (finishOffset_ - startOffset_ > DefaultS3RangeSize)) {
      readTupleSet = s3SelectParallelReqs();
    } else {
      readTupleSet = s3Select(startOffset_, finishOffset_);
    }

//    SPDLOG_CRITICAL("Object: {}, numRows: {}", s3Object_, readTupleSet->numRows());

    // Airmettle doesn't trigger necessarily trigger the SetStatsEventCallback in s3Select (at least not yet)
    // so if this happens we estimate the value here
    if (s3SelectScanStats_.processedBytes == 0) {
      s3SelectScanStats_.processedBytes += finishOffset_ - startOffset_;
    }

    // Store the read columns in the cache, if not in full-pushdown mode
    if (toCache_) {
      // TODO: no need to wrap segments to a tupleset to send
      requestStoreSegmentsInCache(readTupleSet);
    } else {
      // send segment filter weight
      if (!weightedSegmentKeys_.empty() && s3SelectScanStats_.processedBytes > 0) {
        sendSegmentWeight();
      }
    }
  }

  SPDLOG_DEBUG("Finished Reading: {}", name());
  return readTupleSet;
}

void S3SelectPOp::processScanMessage(const ScanMessage &message) {
  // This is for hybrid caching as we later determine which columns to pull up
  setProjectColumnNames(message.getColumnNames());
  columnsReadFromS3_ = std::vector<std::shared_ptr<std::pair<std::string, ::arrow::ArrayVector>>>(message.getColumnNames().size());
}

int subStrNum(const std::string& str, const std::string& sub) {
  int num = 0;
  size_t len = sub.length();
  if (len == 0) len = 1;
  for (size_t i = 0; (i = str.find(sub, i)) != std::string::npos; num++, i += len);
  return num;
}

int S3SelectPOp::getPredicateNum() {
  return filterSql_.empty() ? 
    0 : subStrNum(filterSql_, "and") + subStrNum(filterSql_, "or") + 1;
}

void S3SelectPOp::sendSegmentWeight() {
  /**
   * Compute selectivity, CSV and Parquet are different
   */
  auto filteredBytes = (double) s3SelectScanStats_.returnedBytes;
  auto processedBytes = (double) s3SelectScanStats_.processedBytes;
  auto lenRow = (double) table_->getApxRowLength();
  double selectivity;
  if (table_->getFormat()->getType() == catalogue::format::CSV) {
    double lenColSum = 0.0;
    for (auto const &returnedColumnName: getProjectColumnNames()) {
      lenColSum += table_->getApxColumnLength(returnedColumnName);
    }
    double processedReturnedColumnBytes = (lenColSum / lenRow) * processedBytes;
    selectivity = filteredBytes / processedReturnedColumnBytes;
  } else {
    selectivity = filteredBytes / processedBytes;
  }

  /**
   * Weight function:
   *   w = sel / vNetwork + (lenRow / (lenCol * vScan) + #pred / (lenCol * vFilter)) / #key
   */
  double predicateNum = getPredicateNum();
  auto numKey = (double) weightedSegmentKeys_.size();
  std::unordered_map<std::shared_ptr<SegmentKey>, double> weightMap;
  for (auto const &segmentKey: weightedSegmentKeys_) {
    auto columnName = segmentKey->getColumnName();
    auto lenCol = (double) table_->getApxColumnLength(columnName);

    auto weight = selectivity / vNetwork + (lenRow / (lenCol * vS3Scan) + predicateNum / (lenCol * vS3Filter)) / numKey;
    weightMap.emplace(segmentKey, weight);
  }

  ctx()->send(WeightRequestMessage::make(weightMap, name()), "SegmentCache");
}

void S3SelectPOp::clear() {
  s3Result_.clear();
  parser_.reset();
  columnsReadFromS3_.clear();
  splitReqNumToTable_.clear();
}

}
