//
// Created by matt on 11/8/20.
//

#include "fpdb/tuple/Converter.h"

#include <filesystem>

#include <arrow/io/api.h>
#include <arrow/csv/api.h>
#include <parquet/arrow/writer.h>

#include <fpdb/tuple/Globals.h>

using namespace fpdb::tuple;

tl::expected<void, std::string> Converter::csvToParquet(const std::string &inFile,
														const std::string &outFile,
														const ::arrow::Schema &schema,
														int rowGroupSize,
														::parquet::Compression::type compressionType) {
  ::arrow::io::IOContext ioContext;
  auto absoluteInFile = std::filesystem::absolute(inFile);
  auto absoluteOutFile = std::filesystem::absolute(outFile);

  auto expectedInputStream = ::arrow::io::ReadableFile::Open(absoluteInFile, ::arrow::default_memory_pool());
  if (!expectedInputStream.ok())
	return tl::make_unexpected(expectedInputStream.status().message());
  auto inputStream = *expectedInputStream;

  auto read_options = arrow::csv::ReadOptions::Defaults();
  read_options.skip_rows = 1;
  read_options.use_threads = true;
  auto parse_options = arrow::csv::ParseOptions::Defaults();
  auto convert_options = arrow::csv::ConvertOptions::Defaults();
  std::vector<std::string> columnNames;
  std::unordered_map<std::string, std::shared_ptr<::arrow::DataType>> columnTypes;
  for (const auto &field: schema.fields()) {
    columnNames.emplace_back(field->name());
    columnTypes.emplace(field->name(), field->type());
  }
  read_options.column_names = columnNames;
  convert_options.column_types = columnTypes;

  auto expectedReader = ::arrow::csv::TableReader::Make(ioContext,
														inputStream,
														read_options,
														parse_options,
														convert_options);
  if (!expectedReader.ok())
	return tl::make_unexpected(expectedReader.status().message());
  auto reader = *expectedReader;

  auto expectedTable = reader->Read();
  if (!expectedTable.ok())
	return tl::make_unexpected(expectedTable.status().message());
  auto table = *expectedTable;

  std::shared_ptr<arrow::io::FileOutputStream> outfile;
  auto expectedOutputStream = arrow::io::FileOutputStream::Open(absoluteOutFile);
  if (!expectedOutputStream.ok())
	return tl::make_unexpected(expectedOutputStream.status().message());
  auto outputStream = *expectedOutputStream;

  auto writerProperties = ::parquet::WriterProperties::Builder()
	  .max_row_group_length(rowGroupSize)
	  ->compression(compressionType)
	  ->build();

  auto arrowWriterProperties = ::parquet::ArrowWriterProperties::Builder()
	  .build();

  auto result = ::parquet::arrow::WriteTable(*table,
											 arrow::default_memory_pool(),
											 outputStream,
											 DefaultChunkSize,
											 writerProperties,
											 arrowWriterProperties);

  if (!result.ok())
	return tl::make_unexpected(result.message());

  return {};
}