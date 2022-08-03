//
// Created by Matt Woicik on 1/19/21.
//

#include <fpdb/executor/physical/s3/S3GetPOp.h>
#include <fpdb/executor/physical/Globals.h>
#include <fpdb/executor/message/Message.h>
#include <fpdb/executor/message/cache/LoadResponseMessage.h>
#include <fpdb/catalogue/format/CSVFormat.h>
#include <fpdb/tuple/TupleSet.h>
#include <fpdb/tuple/arrow/ArrowAWSInputStream.h>

#include <arrow/csv/options.h> 
#include <arrow/csv/reader.h>
#include <arrow/io/buffered.h>
#include <arrow/io/memory.h>
#include <arrow/type_fwd.h>
#include <parquet/arrow/reader.h>
#include <aws/core/auth/AWSAuthSigner.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/ratelimiter/DefaultRateLimiter.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <aws/s3/S3Client.h>
#include <iostream>
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

std::mutex GetConvertLock;
int activeGetConversions = 0;

S3GetPOp::S3GetPOp(std::string name,
               std::vector<std::string> projectColumnNames,
               int nodeId,
						   std::string s3Bucket,
						   std::string s3Object,
						   int64_t startOffset,
						   int64_t finishOffset,
               std::shared_ptr<Table> table,
               std::shared_ptr<fpdb::aws::AWSClient> awsClient,
						   bool scanOnStart,
               bool toCache) :
  S3SelectScanAbstractPOp(std::move(name),
                          S3_GET,
                          std::move(projectColumnNames),
                          nodeId,
                          std::move(s3Bucket),
                          std::move(s3Object),
                          startOffset,
                          finishOffset,
                          std::move(table),
                          std::move(awsClient),
                          scanOnStart,
                          toCache) {
}

std::string S3GetPOp::getTypeString() const {
  return "S3GetPOp";
}

bool S3GetPOp::parallelTuplesetCreationSupported() {
  // We only supports combining uncompressed CSV in parallel,
  // though in the future we will support Parquet, this will require
  // different code than CSV though so it hasn't been done yet.
  if (s3Object_.find("gz") != std::string::npos ||
      s3Object_.find("bz2") != std::string::npos ||
      s3Object_.find("csv") == std::string::npos) {
    return false;
  }
  return true;
}

std::shared_ptr<TupleSet> S3GetPOp::readCSVFile(std::shared_ptr<arrow::io::InputStream> &arrowInputStream) {
  auto ioContext = arrow::io::IOContext();
  auto parse_options = arrow::csv::ParseOptions::Defaults();
  auto read_options = arrow::csv::ReadOptions::Defaults();
  read_options.use_threads = false;
  read_options.skip_rows = 1; // Skip the header
  read_options.column_names = getProjectColumnNames();
  auto convert_options = arrow::csv::ConvertOptions::Defaults();
  std::unordered_map<std::string, std::shared_ptr<::arrow::DataType>> columnTypes;
  for(const auto &columnName: getProjectColumnNames()){
	  columnTypes.emplace(columnName, table_->getSchema()->GetFieldByName(columnName)->type());
  }
  convert_options.column_types = columnTypes;
  convert_options.include_columns = getProjectColumnNames();

  // Instantiate TableReader from input stream and options
  auto makeReaderResult = arrow::csv::TableReader::Make(ioContext,
														arrowInputStream,
														read_options,
														parse_options,
														convert_options);
  if (!makeReaderResult.ok())
	  ctx()->notifyError(fmt::format(
            "Cannot parse S3 payload  |  Could not create a table reader, error: '{}'",
            makeReaderResult.status().message()));
  auto tableReader = *makeReaderResult;

  // Parse the payload and create the tupleset
  auto expTupleSet = TupleSet::make(tableReader);
  if (!expTupleSet.has_value()) {
    ctx()->notifyError(expTupleSet.error());
  }
  return *expTupleSet;
}

std::shared_ptr<TupleSet> S3GetPOp::readParquetFile(std::basic_iostream<char, std::char_traits<char>> &retrievedFile) {
  std::string parquetFileString(std::istreambuf_iterator<char>(retrievedFile), {});
  auto bufferedReader = std::make_shared<arrow::io::BufferReader>(parquetFileString);

  std::unique_ptr<parquet::arrow::FileReader> arrow_reader;
  arrow::MemoryPool *pool = arrow::default_memory_pool();
  arrow::Status st = parquet::arrow::OpenFile(bufferedReader, pool, &arrow_reader);
  arrow_reader->set_use_threads(false);

  if (!st.ok()) {
    ctx()->notifyError(fmt::format("Error opening file for {}\nError: {}", name(), st.message()));
  }
  std::shared_ptr<arrow::Table> table;
  // only read the needed columns from the file
  std::vector<int> neededColumnIndices;
  for (const auto& fieldName : getProjectColumnNames()) {
    neededColumnIndices.emplace_back(table_->getSchema()->GetFieldIndex(fieldName));
  }
  st = arrow_reader->ReadTable(neededColumnIndices, &table);
  if (!st.ok()) {
    ctx()->notifyError(fmt::format("Error reading parquet data for {}\nError: {}", name(), st.message()));
  }
  return TupleSet::make(table);
}

std::shared_ptr<TupleSet> S3GetPOp::s3GetFullRequest() {
  GetObjectRequest getObjectRequest;
  getObjectRequest.SetBucket(Aws::String(s3Bucket_));
  getObjectRequest.SetKey(Aws::String(s3Object_));

  std::chrono::steady_clock::time_point startTransferTime = std::chrono::steady_clock::now();
  GetObjectOutcome getObjectOutcome;
  int maxRetryAttempts = 100;
  int attempts = 0;
  while (true) {
    attempts++;
    getObjectOutcome = awsClient_->getS3Client()->GetObject(getObjectRequest);
    if (getObjectOutcome.IsSuccess()) {
      break;
    }
    if (attempts > maxRetryAttempts) {
      const auto& err = getObjectOutcome.GetError();
      ctx()->notifyError(fmt::format("{}, {} after {} retries", err.GetMessage(), name(), maxRetryAttempts));
    }
    // Something went wrong with AWS API on our end or remotely, wait and try again
    std::this_thread::sleep_for (std::chrono::milliseconds(minimumSleepRetryTimeMS));
  }
  std::chrono::steady_clock::time_point stopTransferTime = std::chrono::steady_clock::now();
  auto transferTime = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTransferTime - startTransferTime).count();
  splitReqLock_->lock();
  s3SelectScanStats_.getTransferTimeNS += transferTime;
  s3SelectScanStats_.numRequests++;
  splitReqLock_->unlock();

  std::shared_ptr<TupleSet> tupleSet;
  auto getResult = getObjectOutcome.GetResultWithOwnership();
  int64_t resultSize = getResult.GetContentLength();
  splitReqLock_->lock();
  s3SelectScanStats_.processedBytes += resultSize;
  s3SelectScanStats_.returnedBytes += resultSize;
  splitReqLock_->unlock();
  std::vector<std::shared_ptr<arrow::Field>> fields;
  for (const auto& column : getProjectColumnNames()) {
    fields.emplace_back(::arrow::field(column, table_->getSchema()->GetFieldByName(column)->type()));
  }
  auto outputSchema = std::make_shared<::arrow::Schema>(fields);
  while (true) {
    if (GetConvertLock.try_lock()) {
      if (activeGetConversions < maxConcurrentArrowConversions) {
        activeGetConversions++;
        GetConvertLock.unlock();
        break;
      } else {
        GetConvertLock.unlock();
      }
    }
    std::this_thread::sleep_for (std::chrono::milliseconds(rand() % variableSleepRetryTimeMS + minimumSleepRetryTimeMS));
  }
  std::chrono::steady_clock::time_point startConversionTime = std::chrono::steady_clock::now();
  Aws::IOStream &retrievedFile = getResult.GetBody();
  return nullptr;
}

GetObjectResult S3GetPOp::s3GetRequestOnly(const std::string &s3Object, uint64_t startOffset, uint64_t endOffset) {
  GetObjectRequest getObjectRequest;
  getObjectRequest.SetBucket(Aws::String(s3Bucket_));
  getObjectRequest.SetKey(Aws::String(s3Object));
  if (awsClient_->getAwsConfig()->getS3ClientType() != AIRMETTLE) {
    std::stringstream ss;
    ss << "bytes=" << startOffset << '-' << endOffset;
    getObjectRequest.SetRange(ss.str().c_str());
  }

  std::chrono::steady_clock::time_point startTransferTime = std::chrono::steady_clock::now();
  GetObjectOutcome getObjectOutcome;
  int maxRetryAttempts = 100;
  int attempts = 0;
  while (true) {
    attempts++;
    getObjectOutcome = awsClient_->getS3Client()->GetObject(getObjectRequest);
    if (getObjectOutcome.IsSuccess()) {
      break;
    }
    if (attempts > maxRetryAttempts) {
      const auto& err = getObjectOutcome.GetError();
      ctx()->notifyError(fmt::format("{}, {} after {} retries", err.GetMessage(), name(), maxRetryAttempts));
    }
    // Something went wrong with AWS API on our end or remotely, wait and try again
    std::this_thread::sleep_for (std::chrono::milliseconds(minimumSleepRetryTimeMS));
  }
  std::chrono::steady_clock::time_point stopTransferTime = std::chrono::steady_clock::now();
  auto transferTime = std::chrono::duration_cast<std::chrono::nanoseconds>(stopTransferTime - startTransferTime).count();

  std::shared_ptr<TupleSet> tupleSet;
  auto getResult = getObjectOutcome.GetResultWithOwnership();
  int64_t resultSize = getResult.GetContentLength();
  splitReqLock_->lock();
  s3SelectScanStats_.getTransferTimeNS += transferTime;
  s3SelectScanStats_.numRequests++;
  s3SelectScanStats_.processedBytes += resultSize;
  s3SelectScanStats_.returnedBytes += resultSize;
  splitReqLock_->unlock();
  return getResult;
}

std::shared_ptr<TupleSet> S3GetPOp::readTuples() {
  std::shared_ptr<TupleSet> readTupleSet;

  if (getProjectColumnNames().empty()) {
    readTupleSet = TupleSet::makeWithEmptyTable();
  } else {

    SPDLOG_DEBUG("Reading From S3: {}", name());

    // Read columns from s3
    //readTupleSet = s3GetFullRequest();

    // Store the read columns in the cache, if this operator is to load segments to cache
    if (toCache_) {
      // TODO: only send caching columns
      requestStoreSegmentsInCache(readTupleSet);
    }
  }

  SPDLOG_DEBUG("Finished Reading: {}", name());
  return readTupleSet;
}

void S3GetPOp::processScanMessage(const ScanMessage &message) {
  // This is for hybrid caching as we later determine which columns to pull up
  // Though currently this is only called for SELECT in our system
  setProjectColumnNames(message.getColumnNames());
}

void S3GetPOp::clear() {
  reqNumToAdditionalOutput_.clear();
  columnsReadFromS3_.clear();
  splitReqNumToTable_.clear();
}

}
