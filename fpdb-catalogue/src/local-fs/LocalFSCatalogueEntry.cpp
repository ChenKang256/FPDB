//
// Created by matt on 27/3/20.
//

#include <fpdb/catalogue/local-fs/LocalFSCatalogueEntry.h>
#include <fpdb/catalogue/CatalogueEntryType.h>
#include <fmt/format.h>
#include <utility>

namespace fpdb::catalogue::local_fs {

LocalFSCatalogueEntry::LocalFSCatalogueEntry(string schemaName,
                                             shared_ptr<Catalogue> catalogue) :
  CatalogueEntry(LOCAL_FS,
                 move(schemaName),
                 move(catalogue)) {}

const shared_ptr<LocalFSTable> &LocalFSCatalogueEntry::getLocalFSTable(const string& tableName) const {
  const auto &it = localFsTables_.find(tableName);
  if (it == localFsTables_.end()) {
    throw runtime_error(fmt::format("LocalFS table not found: {}", tableName));
  }
  return it->second;
}

string LocalFSCatalogueEntry::getTypeName() const {
  return "LocalFSCatalogueEntry";
}

void LocalFSCatalogueEntry::addLocalFSTable(const shared_ptr<LocalFSTable> &localFsTable) {
  localFsTables_.emplace(localFsTable->getName(), localFsTable);
}

string LocalFSCatalogueEntry::getName() const {
  return fmt::format("local-fs://{}", getSchemaName());
}

}
