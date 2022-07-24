//
// Created by Yifei Yang on 11/10/21.
//

#ifndef FPDB_FPDB_AWS_INCLUDE_FPDB_AWS_AWSCONFIG_H
#define FPDB_FPDB_AWS_INCLUDE_FPDB_AWS_AWSCONFIG_H

#include <fpdb/aws/S3ClientType.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <memory>

using namespace std;

namespace fpdb::aws {

class AWSConfig {
public:
  AWSConfig(S3ClientType s3ClientType,
            const string &region,
            size_t networkLimit);

  static shared_ptr<AWSConfig> parseAWSConfig();

  S3ClientType getS3ClientType() const;
  size_t getNetworkLimit() const;
  const Aws::String &getRegion() const;

private:
  static S3ClientType parseS3ClientType(const string& stringToParse);

  S3ClientType s3ClientType_;
  Aws::String region_;
  size_t networkLimit_;
};

}


#endif //FPDB_FPDB_AWS_INCLUDE_FPDB_AWS_AWSCONFIG_H
