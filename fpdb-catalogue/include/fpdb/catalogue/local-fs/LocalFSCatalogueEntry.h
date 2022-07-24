//
// Created by matt on 27/3/20.
//

#ifndef FPDB_FPDB_CATALOGUE_INCLUDE_FPDB_CATALOGUE_LOCAL_FS_LOCALFSCATALOGUEENTRY_H
#define FPDB_FPDB_CATALOGUE_INCLUDE_FPDB_CATALOGUE_LOCAL_FS_LOCALFSCATALOGUEENTRY_H

#include <fpdb/catalogue/CatalogueEntry.h>
#include <fpdb/catalogue/Catalogue.h>
#include <fpdb/catalogue/local-fs/LocalFSTable.h>

#include <string>

using namespace fpdb::catalogue;
using namespace std;

namespace fpdb::catalogue::local_fs {

class LocalFSCatalogueEntry : public CatalogueEntry {

public:
  LocalFSCatalogueEntry(string schemaName,
                        shared_ptr<Catalogue> catalogue);
  ~LocalFSCatalogueEntry() override = default;

  const shared_ptr<LocalFSTable> &getLocalFSTable(const string& tableName) const;
  string getTypeName() const override;
  string getName() const override;
  
  void addLocalFSTable(const shared_ptr<LocalFSTable> &localFsTable);

private:
  unordered_map<string, shared_ptr<LocalFSTable>> localFsTables_;

};

}

#endif //FPDB_FPDB_CATALOGUE_INCLUDE_FPDB_CATALOGUE_LOCAL_FS_LOCALFSCATALOGUEENTRY_H
