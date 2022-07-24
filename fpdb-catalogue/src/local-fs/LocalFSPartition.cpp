//
// Created by matt on 15/4/20.
//

#include <fpdb/catalogue/local-fs/LocalFSPartition.h>
#include <utility>

namespace fpdb::catalogue::local_fs {
  
LocalFSPartition::LocalFSPartition(const string &path) :
  path_(path) {}

const string &LocalFSPartition::getPath() const {
  return path_;
}

const string &LocalFSPartition::getObject() {
  return path_;
}

const string LocalFSPartition::getObjectName() {
  return path_.substr(path_.find_last_of("/\\") + 1);
}

string LocalFSPartition::toString() {
  return "file://" + path_;
}

size_t LocalFSPartition::hash() {
  return std::hash<string>()("file://" + path_);
}

bool LocalFSPartition::equalTo(shared_ptr<Partition> other) {
  auto typedOther = static_pointer_cast<const LocalFSPartition>(other);
  if(!typedOther){
	return false;
  }
  else{
	return this->operator==(*typedOther);
  }
}

CatalogueEntryType LocalFSPartition::getCatalogueEntryType() {
  return LOCAL_FS;
}

bool LocalFSPartition::operator==(const LocalFSPartition &other) {
  return path_ == other.path_;
}

}
