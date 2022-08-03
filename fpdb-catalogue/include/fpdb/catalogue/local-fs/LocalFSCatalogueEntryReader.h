//
// Created by Partho on 25/3/22.
//

#ifndef FPDB_FPDB_CATALOGUE_INCLUDE_FPDB_CATALOGUE_Local_FS_LOCALFSCATALOGUEENTRYREADER_H
#define FPDB_FPDB_CATALOGUE_INCLUDE_FPDB_CATALOGUE_Local_FS_LOCALFSCATALOGUEENTRYREADER_H

#include <fpdb/catalogue/local-fs/LocalFSCatalogueEntry.h>
#include <fpdb/catalogue/Catalogue.h>
#include <fpdb/catalogue/format/Format.h>
#include <fpdb/tuple/Scalar.h>
#include <nlohmann/json.hpp>

using namespace fpdb::tuple;
using namespace std;
using json = nlohmann::json;

namespace fpdb::catalogue::local_fs {

class LocalFSCatalogueEntryReader {
public:
  static shared_ptr<LocalFSCatalogueEntry> readLocalFSCatalogueEntry(const shared_ptr<Catalogue> &catalogue,
                                                           const string &schemaName);

private:
  static void readSchema(const json &schemaJObj,
                         const string &dataPath,
                         unordered_map<string, shared_ptr<arrow::Schema>> &schemaMap,
                         unordered_map<string, shared_ptr<format::Format>> &formatMap,
                         unordered_map<string, vector<shared_ptr<LocalFSPartition>>> &localFsPartitionsMap);
  static void readStats(const json &statsJObj,
                        unordered_map<string, unordered_map<string, int>> &apxColumnLengthMapMap,
                        unordered_map<string, int> &apxRowLengthMap);
  static void readZoneMap(const json &zonemapJObj,
                          const unordered_map<string, shared_ptr<arrow::Schema>> &schemaMap,
                          unordered_map<string, vector<shared_ptr<LocalFSPartition>>> &localFsPartitionsMap,
                          unordered_map<string, unordered_set<string>> &zonemapColumnNamesMap);
  static void readPartitionSize(unordered_map<string, vector<shared_ptr<LocalFSPartition>>> &localFsPartitionsMap);

  static shared_ptr<arrow::DataType> strToDataType(const string &str);
  static pair<shared_ptr<Scalar>, shared_ptr<Scalar>>
    jsonToMinMaxLiterals(const json &jObj, const shared_ptr<arrow::DataType> &datatype);
};

}


#endif //FPDB_FPDB_CATALOGUE_INCLUDE_FPDB_CATALOGUE_Local_FS_LOCALFSCATALOGUEENTRYREADER_H
