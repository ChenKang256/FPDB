//
// Created by matt on 12/12/19.
//

#include <fpdb/executor/physical/file/FileScanPOp.h>
#include <fpdb/executor/physical/Globals.h>
#include <fpdb/executor/physical/PhysicalOp.h>
#include <fpdb/executor/physical/cache/CacheHelper.h>
#include <fpdb/executor/message/Message.h>
#include <fpdb/catalogue/format/CSVFormat.h>
#include <fpdb/executor/message/TupleMessage.h>
#include <fpdb/catalogue/local-fs/LocalFSPartition.h>
#include <fpdb/tuple/TupleSet.h>
#include <arrow/type_fwd.h>            // for default_memory_pool
#include <memory>                      // for make_unique, unique_ptr, __sha...
#include <utility>

#include <fpdb/tuple/arrow/CSVToArrowSIMDStreamParser.h>

using namespace fpdb::executor::physical::cache;
using namespace fpdb::executor::message;
using namespace fpdb::tuple;
using namespace fpdb::catalogue::format;

namespace arrow { class MemoryPool; }

namespace fpdb::executor::physical::file {

FileScanPOp::FileScanPOp(std::string name,
           std::vector<std::string> projectColumnNames,
           int nodeId,
				   const std::string& filePath,
           std::shared_ptr<Table> table,
				   bool scanOnStart) :
	PhysicalOp(std::move(name), FILE_SCAN, std::move(projectColumnNames), nodeId),
	scanOnStart_(scanOnStart),
  filePath_(filePath),
  table_(std::move(table)){}

std::string FileScanPOp::getTypeString() const {
  return "FileScanPOp";
}

void FileScanPOp::onReceive(const Envelope &message) {
  if (message.message().type() == MessageType::START) {
	  this->onStart();
  } else if (message.message().type() == MessageType::SCAN) {
    auto scanMessage = dynamic_cast<const ScanMessage &>(message.message());
    this->onCacheLoadResponse(scanMessage);
  } else if (message.message().type() == MessageType::COMPLETE) {
    auto completeMessage = dynamic_cast<const CompleteMessage &>(message.message());
    this->onComplete(completeMessage);
  } else {
    ctx()->notifyError("Unrecognized message type " + message.message().getTypeString());
  }
}

void FileScanPOp::onComplete(const CompleteMessage &) {
  if(ctx()->operatorMap().allComplete(POpRelationshipType::Producer)){
	ctx()->notifyComplete();
  }
}

void FileScanPOp::onStart() {
  SPDLOG_DEBUG("Starting operator  |  name: '{}'", this->name());
  if(scanOnStart_){
	readAndSendTuples(getProjectColumnNames());
	ctx()->notifyComplete();
  }
}

void FileScanPOp::readAndSendTuples(const std::vector<std::string> &columnNames){
  // Read the columns not present in the cache
  /*
   * FIXME: Should support reading the file in pieces
   */

  std::shared_ptr<TupleSet> readTupleSet;
  if (columnNames.empty()) {
    readTupleSet = TupleSet::makeWithEmptyTable();
  } else {
    readTupleSet = readTuples();
		SPDLOG_DEBUG("{} -> {} rows", name(), readTupleSet->numRows());

    // Store the read columns in the cache
    // requestStoreSegmentsInCache(readTupleSet);
  }

  std::shared_ptr<Message> message = std::make_shared<TupleMessage>(readTupleSet, this->name());
  ctx()->tell(message);
}

std::shared_ptr<TupleSet> FileScanPOp::readTuples() {
	std::fstream retrievedFile(this->filePath_);

	std::vector<std::shared_ptr<arrow::Field>> fields;
  for (const auto& column : this->projectColumnNames_) {
    fields.emplace_back(::arrow::field(column, table_->getSchema()->GetFieldByName(column)->type()));
  }
  auto outputSchema = std::make_shared<::arrow::Schema>(fields);
	auto csvTableFormat = std::static_pointer_cast<CSVFormat>(table_->getFormat());
	auto parser = CSVToArrowSIMDStreamParser(name(),
                                           DefaultS3ConversionBufferSize,
                                           retrievedFile,
                                           true,
                                           table_->getSchema(),
                                           outputSchema,
                                           false,
                                           csvTableFormat->getFieldDelimiter());
  auto tupleSet = parser.constructTupleSet();
	return tupleSet;
}

void FileScanPOp::onCacheLoadResponse(const ScanMessage &Message) {
  readAndSendTuples(Message.getColumnNames());
}

bool FileScanPOp::isScanOnStart() const {
  return scanOnStart_;
}

void FileScanPOp::clear() {
  // Noop
}

}