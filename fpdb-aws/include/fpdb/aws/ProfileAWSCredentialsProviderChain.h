//
// Created by matt on 2/2/22.
//

#ifndef FPDB_FPDB_AWS_INCLUDE_FPDB_AWS_PROFILEAWSCREDENTIALSPROVIDERCHAIN_H
#define FPDB_FPDB_AWS_INCLUDE_FPDB_AWS_PROFILEAWSCREDENTIALSPROVIDERCHAIN_H

#include <aws/core/auth/AWSCredentialsProviderChain.h>
#include <aws/core/auth/AWSCredentialsProvider.h>

namespace fpdb::aws {

using namespace Aws::Auth;

/**
 * For the most part this is just a duplicate of DefaultAWSCredentialsProviderChain but allows a profile
 * name to be supplied for the ProfileConfigFileAWSCredentialsProvider. This allows multiple profiles to
 * be present in the local machine's .aws/credentials file, and one used instead of the default profile.
 */
class ProfileAWSCredentialsProviderChain : public AWSCredentialsProviderChain {
public:
  explicit ProfileAWSCredentialsProviderChain(const char *profile, long refreshRateMs = REFRESH_THRESHOLD);
};

}


#endif //FPDB_FPDB_AWS_INCLUDE_FPDB_AWS_PROFILEAWSCREDENTIALSPROVIDERCHAIN_H
