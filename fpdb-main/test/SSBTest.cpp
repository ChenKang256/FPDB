//
// Created by Yifei Yang on 11/30/21.
//

#include <doctest/doctest.h>
#include "TestUtil.h"

namespace fpdb::main::test {

#define SKIP_SUITE false

TEST_SUITE ("ssb-sf1-single_node-no-parallel" * doctest::skip(SKIP_SUITE)) {

  int SSBparallelDegreeDist = 10;

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-1.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/1.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-1.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/1.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-1.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/1.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-2.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/2.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-2.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/2.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-2.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/2.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-3.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/3.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-3.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/3.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-3.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/3.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-3.4" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/3.4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-4.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/4.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-4.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/4.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-original-4.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/original/4.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-generated-1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/generated/1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-generated-2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/generated/2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-generated-3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/generated/3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-generated-4" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/generated/4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf1-single_node-no-parallel-generated-5" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
//                                             {"ssb/generated/5.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }
}

TEST_SUITE ("ssb-sf10-single_node-no-parallel-all" * doctest::skip(SKIP_SUITE)) {

  int SSBparallelDegreeDist = 10;

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-1.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/1.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-1.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/1.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-1.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/1.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-2.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/2.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-2.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/2.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-2.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/2.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-3.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-3.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-3.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-3.4" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-4.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/4.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-4.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/4.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-original-4.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/4.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-generated-1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-generated-2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-generated-3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-generated-4" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf10-single_node-no-parallel-all-generated-5" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/5.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }
}

//Single testcase
// TEST_SUITE ("ssb-special" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-special-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/1.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-1.2" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-1.2-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/1.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-1.3" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-1.3-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/1.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-2.1" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-2.1-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/2.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-2.2" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-2.2-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/2.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-2.3" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-2.3-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/2.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-3.1" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-3.1-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-3.2" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-3.2-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-3.3" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-3.3-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-3.4" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-3.4-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/3.4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-4.1" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-4.1-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/4.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-4.2" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-4.2-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/4.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-original-4.3" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-original-4.3-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/original/4.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

TEST_SUITE ("ssb-sf10-single_node-no-parallel-generated-1" * doctest::skip(SKIP_SUITE)) {
  int SSBparallelDegreeDist = 10;
  TEST_CASE ("ssb-sf10-single_node-no-parallel-generated-1-TEST" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                            {"ssb/generated/1.sql"},
                                            SSBparallelDegreeDist,
                                            true));
  }
}

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-generated-2" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-generated-2-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-generated-3" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-generated-3-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-generated-4" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-generated-4-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf10-single_node-no-parallel-generated-5" * doctest::skip(SKIP_SUITE)) {
//   int SSBparallelDegreeDist = 10;
//   TEST_CASE ("ssb-sf10-single_node-no-parallel-generated-5-TEST" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
//                                             {"ssb/generated/5.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
//   }
// }

// TEST_SUITE ("ssb-sf20-single_node-no-parallel" * doctest::skip(SKIP_SUITE)) {

//   int SSBparallelDegreeDist = 10;

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-1.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/1.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-1.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/1.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-1.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/1.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-2.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/2.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-2.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/2.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-2.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/2.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-3.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/3.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-3.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/3.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-3.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/3.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-3.4" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/3.4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-4.1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/4.1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-4.2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/4.2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-original-4.3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/original/4.3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-generated-1" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/generated/1.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-generated-2" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/generated/2.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-generated-3" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/generated/3.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-generated-4" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/generated/4.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }

// TEST_CASE ("ssb-sf20-single_node-no-parallel-generated-5" * doctest::skip(false || SKIP_SUITE)) {
//   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
//                                             {"ssb/generated/5.sql"},
//                                             SSBparallelDegreeDist,
//                                             true));
// }
// }

}
