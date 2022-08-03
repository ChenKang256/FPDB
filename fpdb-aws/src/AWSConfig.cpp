//
// Created by Yifei Yang on 11/10/21.
//

#include <fpdb/aws/AWSConfig.h>
#include <fpdb/util/Util.h>
#include <fmt/format.h>
#include <unordered_map>
#include <string>

using namespace fpdb::util;

namespace fpdb::aws {

AWSConfig::AWSConfig(S3ClientType s3ClientType,
                     const string &region,
                     size_t networkLimit) :
  s3ClientType_(s3ClientType),
  region_(region),
  networkLimit_(networkLimit) {}

shared_ptr<AWSConfig> AWSConfig::parseAWSConfig() {
  unordered_map<string, string> configMap = readConfig("aws.conf");
  auto s3ClientType = parseS3ClientType(configMap["S3_CLIENT_TYPE"]);
  auto region = configMap["AWS_REGION"];
  auto networkLimit = stoul(configMap["NETWORK_LIMIT"]);
  return make_shared<AWSConfig>(s3ClientType, region, networkLimit);
}

S3ClientType AWSConfig::parseS3ClientType(const string &stringToParse) {
  if (stringToParse == "S3") {
    return S3;
  } else if (stringToParse == "AIRMETTLE") {
    return AIRMETTLE;
  } else if (stringToParse == "MINIO") {
    return MINIO;
  }
  throw runtime_error(fmt::format("Unknown S3 client type: {}", stringToParse));
}

S3ClientType AWSConfig::getS3ClientType() const {
  return s3ClientType_;
}

const Aws::String &AWSConfig::getRegion() const {
  return region_;
}

size_t AWSConfig::getNetworkLimit() const {
  return networkLimit_;
}

}
