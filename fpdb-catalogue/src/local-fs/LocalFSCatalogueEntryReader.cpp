//
// Created by Partho on 25/3/22.
//

#include <fpdb/catalogue/local-fs/LocalFSCatalogueEntryReader.h>
#include <fpdb/catalogue/format/CSVFormat.h>
#include <fpdb/catalogue/format/ParquetFormat.h>
#include <fpdb/tuple/ColumnName.h>
#include <fpdb/tuple/FileReaderBuilder.h>
#include <fpdb/tuple/FileType.h>
#include <fpdb/util/Util.h>
#include <nlohmann/json.hpp>
#include <fmt/format.h>

using namespace fpdb::tuple;
using namespace fpdb::util;

namespace fpdb::catalogue::local_fs {

shared_ptr<LocalFSCatalogueEntry>
LocalFSCatalogueEntryReader::readLocalFSCatalogueEntry(const shared_ptr<Catalogue> &catalogue,
                                             const string &schemaName) {
  // read metadata files
  filesystem::path metadataPath = catalogue->getMetadataPath().append(schemaName);
  if (!filesystem::exists(metadataPath)) {
    throw runtime_error(fmt::format("Metadata not found for schema: {}", schemaName));
  }
  auto schemaJObj = json::parse(readFile(metadataPath.append("schema.json")));
  metadataPath = metadataPath.parent_path();
  auto statsJObj = json::parse(readFile(metadataPath.append("stats.json")));
  metadataPath = metadataPath.parent_path();
  auto zoneMapJObj = json::parse(readFile(metadataPath.append("zoneMap.json")));
  metadataPath = metadataPath.parent_path();
  string dataPath = metadataPath.append("data").string();

  // get all table names
  unordered_set<string> tableNames;
  for (const auto &tableSchemaJObj: schemaJObj["tables"].get<vector<json>>()) {
    tableNames.emplace(tableSchemaJObj["name"].get<string>());
  }

  // member variables to make LocalFSCatalogueEntry and LocalFSTable
  unordered_map<string, shared_ptr<format::Format>> formatMap;
  unordered_map<string, shared_ptr<arrow::Schema>> schemaMap;
  unordered_map<string, unordered_map<string, int>> apxColumnLengthMapMap;
  unordered_map<string, int> apxRowLengthMap;
  unordered_map<string, unordered_set<string>> zoneMapColumnNamesMap;
  unordered_map<string, vector<shared_ptr<LocalFSPartition>>> localFsPartitionsMap;

  // read schema
  readSchema(schemaJObj, dataPath, schemaMap, formatMap, localFsPartitionsMap);

  // read stats
  readStats(statsJObj, apxColumnLengthMapMap, apxRowLengthMap);

  // read zoneMap
  readZoneMap(zoneMapJObj, schemaMap, localFsPartitionsMap, zoneMapColumnNamesMap);

  // read partition size from local-fs object
  readPartitionSize(localFsPartitionsMap);

  // create an LocalFSCatalogueEntry
  shared_ptr<LocalFSCatalogueEntry> localFsCatalogueEntry = make_shared<LocalFSCatalogueEntry>(schemaName,
                                                                                catalogue);

  // make LocalFSTables
  for (const auto &tableName: tableNames) {
    shared_ptr<LocalFSTable> localFsTable = make_shared<LocalFSTable>(tableName,
                                                       schemaMap.find(tableName)->second,
                                                       formatMap.find(tableName)->second,
                                                       apxColumnLengthMapMap.find(tableName)->second,
                                                       apxRowLengthMap.find(tableName)->second,
                                                       zoneMapColumnNamesMap.find(tableName)->second,
                                                       localFsPartitionsMap.find(tableName)->second);
    localFsCatalogueEntry->addLocalFSTable(localFsTable);
  }

  return localFsCatalogueEntry;
}

void LocalFSCatalogueEntryReader::readSchema(const json &schemaJObj,
                                        const string &dataPath,
                                        unordered_map<string, shared_ptr<arrow::Schema>> &schemaMap,
                                        unordered_map<string, shared_ptr<format::Format>> &formatMap,
                                        unordered_map<string, vector<shared_ptr<LocalFSPartition>>> &localFsPartitionsMap) {
  // read schemas, formats and localFsPartitions
  for (const auto &tableSchemasJObj: schemaJObj["tables"].get<vector<json>>()) {
    const string &tableName = tableSchemasJObj["name"].get<string>();

    // formats
    const auto &formatJObj = tableSchemasJObj["format"];
    const string &formatStr = formatJObj["name"].get<string>();
    string localFsObjectSuffix;
    if (formatStr == "csv") {
      char fieldDelimiter = formatJObj["fieldDelimiter"].get<string>().c_str()[0];
      formatMap.emplace(tableName, make_shared<format::CSVFormat>(fieldDelimiter));
      localFsObjectSuffix = ".tbl";
    } else if (formatStr == "parquet") {
      formatMap.emplace(tableName, make_shared<format::ParquetFormat>());
      localFsObjectSuffix = ".parquet";
    } else {
      throw runtime_error(fmt::format("Unsupported data format: {}", formatStr));
    }

    // fields
    vector<shared_ptr<arrow::Field>> fields;
    for (const auto &fieldJObj: tableSchemasJObj["fields"].get<vector<json>>()) {
      const string &fieldName = ColumnName::canonicalize(fieldJObj["name"].get<string>());
      const string &fieldTypeStr = fieldJObj["type"].get<string>();
      const auto &fieldType = strToDataType(fieldTypeStr);
      auto field = make_shared<arrow::Field>(fieldName, fieldType);
      fields.emplace_back(field);
    }
    auto schema = make_shared<arrow::Schema>(fields);
    schemaMap.emplace(tableName, schema);

    // partitions
    vector<shared_ptr<LocalFSPartition>> localFsPartitions;
    int numPartitions = tableSchemasJObj["numPartitions"].get<int>();
    if (numPartitions == 1) {
      string localFsObject = fmt::format("{}/{}{}", dataPath, tableName, localFsObjectSuffix);
      localFsPartitions.emplace_back(make_shared<LocalFSPartition>(localFsObject));
    } else {
      string localFsObjectDir = fmt::format("{}/{}_sharded", dataPath, tableName);
      for (int i = 0; i < numPartitions; ++i) {
        string localFsObject = fmt::format("{}/{}{}.{}", localFsObjectDir, tableName, localFsObjectSuffix, to_string(i));
        localFsPartitions.emplace_back(make_shared<LocalFSPartition>(localFsObject));
      }
    }
    localFsPartitionsMap.emplace(tableName, localFsPartitions);
  }
}

void LocalFSCatalogueEntryReader::readStats(const json &statsJObj,
                                       unordered_map<string, unordered_map<string, int>> &apxColumnLengthMapMap,
                                       unordered_map<string, int> &apxRowLengthMap) {
  for (const auto &tableStatsJObj: statsJObj["tables"].get<vector<json>>()) {
    const string &tableName = tableStatsJObj["name"].get<string>();
    unordered_map<string, int> apxColumnLengthMap;
    int apxRowLength = 0;
    for (const auto &apxColumnLengthIt: tableStatsJObj["stats"]["apxColumnLength"].get<unordered_map<string, int>>()) {
      string columnName = ColumnName::canonicalize(apxColumnLengthIt.first);
      int apxColumnLength = apxColumnLengthIt.second;
      apxColumnLengthMap.emplace(columnName, apxColumnLength);
      apxRowLength += apxColumnLength;
    }
    apxColumnLengthMapMap.emplace(tableName, apxColumnLengthMap);
    apxRowLengthMap.emplace(tableName, apxRowLength);
  }
}

void LocalFSCatalogueEntryReader::readZoneMap(const json &zoneMapJObj,
                                         const unordered_map<string, shared_ptr<arrow::Schema>> &schemaMap,
                                         unordered_map<string, vector<shared_ptr<LocalFSPartition>>> &localFsPartitionsMap,
                                         unordered_map<string, unordered_set<string>> &zoneMapColumnNamesMap) {
  // read zoneMaps
  for (const auto &tableZoneMapsJObj: zoneMapJObj["tables"].get<vector<json>>()) {
    const string &tableName = tableZoneMapsJObj["name"].get<string>();
    const shared_ptr<arrow::Schema> &schema = schemaMap.find(tableName)->second;
    const vector<shared_ptr<LocalFSPartition>> &localFsPartitions = localFsPartitionsMap.find(tableName)->second;

    unordered_set<string> zoneMapColumnNames;
    for (const auto &tableZoneMapJObj: tableZoneMapsJObj["zoneMap"].get<vector<json>>()) {
      const string &fieldName = ColumnName::canonicalize(tableZoneMapJObj["field"].get<string>());
      zoneMapColumnNames.emplace(fieldName);
      const shared_ptr<arrow::DataType> fieldType = schema->GetFieldByName(fieldName)->type();
      const auto valuePairsJArr = tableZoneMapJObj["valuePairs"].get<vector<json>>();

      for (size_t i = 0; i < localFsPartitions.size(); ++i) {
        const auto &localFsPartition = localFsPartitions[i];
        const auto valuePairJObj = valuePairsJArr[i];
        localFsPartition->addMinMax(fieldName, jsonToMinMaxLiterals(valuePairJObj, fieldType));
      }
    }
    zoneMapColumnNamesMap.emplace(tableName, zoneMapColumnNames);
  }

  // fill zoneMapColumnNamesMap for no-zoneMap tables
  for (const auto &it: schemaMap) {
    const string &tableName = it.first;
    if (zoneMapColumnNamesMap.find(tableName) == zoneMapColumnNamesMap.end()) {
      zoneMapColumnNamesMap.emplace(tableName, unordered_set<string>{});
    }
  }
}

void LocalFSCatalogueEntryReader::readPartitionSize(unordered_map<string, vector<shared_ptr<LocalFSPartition>>> &localFsPartitionsMap) {
  // collect a map of localFsObject -> localFsPartition
  vector<shared_ptr<LocalFSPartition>> allLocalFSPartitions;
  for (const auto &it: localFsPartitionsMap) {
    allLocalFSPartitions.insert(allLocalFSPartitions.end(), it.second.begin(), it.second.end());
  }
  vector<string> allLocalFSObjects;
  unordered_map<string, shared_ptr<LocalFSPartition>> localFsObjectPartitionMap;
  for (const auto &localFsPartition: allLocalFSPartitions) {
    const auto &localFsObject = localFsPartition->getObject();
    allLocalFSObjects.emplace_back(localFsObject);
    localFsObjectPartitionMap.emplace(localFsObject, localFsPartition);
  }

  // list objects
  // auto s3ObjectSizeMap = S3Util::listObjects(s3Bucket, schemaName, allS3Objects, s3Client);
  
  // FIXME: Reading entire file is slow.
  auto localFsObjectSizeMap = std::unordered_map<std::string, long>();
  for (const auto &localFsObject: allLocalFSObjects) {
    auto reader = FileReaderBuilder::make(localFsObject, FileType::CSV);
    auto expectedBytes = reader->get_size();
    if (!expectedBytes.has_value()) {
      throw std::runtime_error(fmt::format("Failed to get size of {}", localFsObject));
    }
    int64_t numBytes = expectedBytes.value();
    localFsObjectSizeMap.emplace(localFsObject, numBytes);
  }

  // set partition size
  for (const auto &it: localFsObjectSizeMap) {
    const auto &localFsObject = it.first;
    long objectSize = it.second;
    if (localFsObjectPartitionMap.find(localFsObject) != localFsObjectPartitionMap.end()) {
      auto localFsPartition = localFsObjectPartitionMap.find(localFsObject)->second;
      localFsPartition->setNumBytes(objectSize);
    } else {
      printf("ERROR: localFsObject '%s' not found in localFsPartitionMap", localFsObject.c_str());
    }
  }
}

shared_ptr<arrow::DataType> LocalFSCatalogueEntryReader::strToDataType(const string &str) {
  if (str == "int32" || str == "int") {
    return arrow::int32();
  } else if (str == "int64" || str == "long") {
    return arrow::int64();
  } else if (str == "float64" || str == "double") {
    return arrow::float64();
  } else if (str == "utf8" || str == "string") {
    return arrow::utf8();
  } else if (str == "boolean" || str == "bool") {
    return arrow::boolean();
  } else if (str == "date") {
    return arrow::date64();
  } else {
    throw runtime_error(fmt::format("Unsupported data type: {}", str));
  }
}

pair<shared_ptr<Scalar>, shared_ptr<Scalar>>
LocalFSCatalogueEntryReader::jsonToMinMaxLiterals(const json &jObj, const shared_ptr<arrow::DataType> &datatype) {
  if (datatype->id() == arrow::int32()->id()) {
    return make_pair(Scalar::make(arrow::MakeScalar(arrow::int32(), jObj["min"].get<int>()).ValueOrDie()),
                     Scalar::make(arrow::MakeScalar(arrow::int32(), jObj["max"].get<int>()).ValueOrDie()));
  } else if (datatype->id() == arrow::int64()->id()) {
    return make_pair(Scalar::make(arrow::MakeScalar(arrow::int64(), jObj["min"].get<long>()).ValueOrDie()),
                     Scalar::make(arrow::MakeScalar(arrow::int64(), jObj["max"].get<long>()).ValueOrDie()));
  } else if (datatype->id() == arrow::float64()->id()) {
    return make_pair(Scalar::make(arrow::MakeScalar(arrow::float64(), jObj["min"].get<double>()).ValueOrDie()),
                     Scalar::make(arrow::MakeScalar(arrow::float64(), jObj["max"].get<double>()).ValueOrDie()));
  } else if (datatype->id() == arrow::utf8()->id()) {
    return make_pair(Scalar::make(arrow::MakeScalar(arrow::utf8(), jObj["min"].get<string>()).ValueOrDie()),
                     Scalar::make(arrow::MakeScalar(arrow::utf8(), jObj["max"].get<string>()).ValueOrDie()));
  } else {
    throw runtime_error(fmt::format("Unsupported data type: {}", datatype->name()));
  }
}

}
