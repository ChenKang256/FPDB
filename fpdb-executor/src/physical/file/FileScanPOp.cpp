#include <fpdb/executor/physical/file/FileScanPOp.h>
#include <fpdb/executor/physical/Globals.h>
#include <fpdb/executor/physical/PhysicalOp.h>
#include <fpdb/executor/physical/cache/CacheHelper.h>
#include <fpdb/executor/message/Message.h>
#include <fpdb/catalogue/format/CSVFormat.h>
#include <fpdb/executor/message/TupleMessage.h>
#include <fpdb/catalogue/local-fs/LocalFSPartition.h>
#include <fpdb/tuple/TupleSet.h>
#include <arrow/csv/options.h> 
#include <arrow/csv/reader.h>
#include <arrow/io/buffered.h>
#include <arrow/io/api.h>
#include <arrow/io/memory.h>
#include <arrow/type_fwd.h>            // for default_memory_pool
#include <arrow/csv/api.h>
#include <memory>                      // for make_unique, unique_ptr, __sha...
#include <utility>
#include <filesystem>
#include <algorithm> //transform

using namespace fpdb::executor::physical::cache;
using namespace fpdb::executor::message;
using namespace fpdb::tuple;
using namespace fpdb::catalogue::format;

namespace arrow { class MemoryPool; }
string mytoupper(string s){
    string res = "";
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='a'&&s[i]<='z'){
            s[i]-=32;
     res += s[i];
      } else {
      res += s[i];
     }
    }
  return res;
}
namespace fpdb::executor::physical::file {

std::shared_ptr<TupleSet> FileScanPOp::readCSVFile(std::shared_ptr<arrow::io::ReadableFile> &arrowInputStream) {
    auto ioContext = arrow::io::IOContext();
    auto parse_options = arrow::csv::ParseOptions::Defaults();
    auto read_options = arrow::csv::ReadOptions::Defaults();
    read_options.use_threads = false;
    auto convert_options = arrow::csv::ConvertOptions::Defaults();
    std::unordered_map<std::string, std::shared_ptr<::arrow::DataType>> columnTypes;
    std::vector<std::string> temp = getProjectColumnNames();
    for (int i=0; i < temp.size(); i++) {
     //temp[i] = std::transform(temp[i].begin(), temp[i].end(), temp[i].begin(), std::toupper);
         //temp[i] = std::toupper(temp[i]);
        temp[i] = mytoupper(temp[i]);
    }
    convert_options.include_columns = temp;
    parse_options.delimiter = '|';

    for(const auto &columnName: this->projectColumnNames_) {
        columnTypes.emplace(mytoupper(columnName), table_->getSchema()->GetFieldByName(columnName)->type());
    }
    convert_options.column_types = columnTypes;
    // Instantiate TableReader from input stream and options
    auto makeReaderResult = arrow::csv::TableReader::Make(ioContext,
                                                            arrowInputStream,
                                                            read_options,
                                                            parse_options,
                                                            convert_options);
    if (!makeReaderResult.ok()) {
        ctx()->notifyError(fmt::format(
                "Cannot parse S3 payload  |  Could not create a table reader, error: '{}'",
                makeReaderResult.status().message()));
    }
    std::shared_ptr<arrow::csv::TableReader> tableReader = *makeReaderResult;
    // Parse the payload and create the tupleset
    auto expTupleSet = TupleSet::make(tableReader);
    if (!expTupleSet.has_value()) {
        ctx()->notifyError(expTupleSet.error());
    }
    //std::cout << expTupleSet->toString() << std::endl;
    return *expTupleSet;
}

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
  auto inFile = std::filesystem::absolute(this->filePath_);//if it's a relative path, please replace absolute with relative
  auto expectedInFile = arrow::io::ReadableFile::Open(inFile, arrow::default_memory_pool());
  auto inputStream = *expectedInFile;
  auto tupleSet = readCSVFile(inputStream);
  inputStream->Close();


//   std::fstream retrievedFile(this->filePath_);

//  std::vector<std::shared_ptr<arrow::Field>> fields;
//   for (const auto& column : this->projectColumnNames_) {
//     fields.emplace_back(::arrow::field(column, table_->getSchema()->GetFieldByName(column)->type()));
//     //std::cout << "2" << column << table_->getSchema()->GetFieldByName(column)->type()->name() <<std::endl;
//   }
//   auto outputSchema = std::make_shared<::arrow::Schema>(fields);
//  auto csvTableFormat = std::static_pointer_cast<CSVFormat>(table_->getFormat());
//   auto parser = CSVToArrowSIMDStreamParser(name(),
//                                            DefaultS3ConversionBufferSize,
//                                            retrievedFile,
//                                            true,
//                                            table_->getSchema(),
//                                            outputSchema,
//                                            false,
//                                            csvTableFormat->getFieldDelimiter());
//   auto tupleSet1 = parser.constructTupleSet();
  tupleSet->renameColumns(this->projectColumnNames_);
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