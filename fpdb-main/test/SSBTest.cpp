#include <doctest/doctest.h>
#include "TestUtil.h"

namespace fpdb::main::test {

#define SKIP_SUITE false

TEST_SUITE ("ssb-sf1-distributed" * doctest::skip(SKIP_SUITE)) {

int parallelDegreeSSB = 4;

TEST_CASE ("ssb-sf1-distributed-original-select" * doctest::skip(false || SKIP_SUITE)) {
  cout << "input the path of sql instrs:" << endl;
  string s;
  ::std::cin >> s;
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {s},
                                            parallelDegreeSSB,
                                            true));
}

/*
TEST_CASE ("ssb-sf1-distributed-original-1.1" * doctest::skip(false || SKIP_SUITE)) {
  cout << "input the path of sql instrs:" << endl;
  string s;
  ::std::cin >> s;
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/1.1.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-1.2" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/1.2.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-1.3" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/1.3.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-2.1" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/2.1.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-2.2" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/2.2.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-2.3" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/2.3.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-3.1" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/3.1.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-3.2" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/3.2.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-3.3" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/3.3.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-3.4" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/3.4.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-4.1" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/4.1.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-4.2" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/4.2.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-original-4.3" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/original/4.3.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-generated-1" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/generated/1.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-generated-2" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/generated/2.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-generated-3" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/generated/3.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-generated-4" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/generated/4.sql"},
                                            parallelDegreeSSB,
                                            true));
}

TEST_CASE ("ssb-sf1-distributed-generated-5" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf1-sortlineorder/csv/",
                                            {"ssb/generated/5.sql"},
                                            parallelDegreeSSB,
                                            true));
}*/
}

TEST_SUITE ("ssb-sf10-distributed" * doctest::skip(SKIP_SUITE)) {

int parallelDegreeSSB = 4;

TEST_CASE ("ssb-sf10-distributed-original-select" * doctest::skip(false || SKIP_SUITE)) {
  cout << "input the path of sql instrs:" << endl;
  string s;
  ::std::cin >> s;
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                            {s},
                                            parallelDegreeSSB,
                                            true));
}

/*
 TEST_CASE ("ssb-sf10-distributed-original-1.1" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/1.1.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-1.2" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/1.2.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-1.3" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/1.3.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-2.1" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/2.1.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-2.2" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/2.2.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-2.3" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/2.3.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-3.1" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/3.1.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-3.2" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/3.2.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-3.3" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/3.3.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-3.4" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/3.4.sql"},
                                             parallelDegreeSSB,
                                             true));
 }


 TEST_CASE ("ssb-sf10-distributed-original-4.1" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/4.1.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-4.2" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/4.2.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-original-4.3" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/original/4.3.sql"},
                                             parallelDegreeSSB,
                                             true));
 }


  TEST_CASE ("ssb-sf10-distributed-generated-1" * doctest::skip(false || SKIP_SUITE)) {
    REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                              {"ssb/generated/1.sql"},
                                              parallelDegreeSSB,
                                              true));
 }

 TEST_CASE ("ssb-sf10-distributed-generated-2" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                           {"ssb/generated/2.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

TEST_CASE ("ssb-sf10-distributed-generated-3" * doctest::skip(false || SKIP_SUITE)) {
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                            {"ssb/generated/3.sql"},
                                            parallelDegreeSSB,
                                            true));
}

 TEST_CASE ("ssb-sf10-distributed-generated-4" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/generated/4.sql"},
                                             parallelDegreeSSB,
                                             true));
 }

 TEST_CASE ("ssb-sf10-distributed-generated-5" * doctest::skip(false || SKIP_SUITE)) {
   REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf10-sortlineorder/csv/",
                                             {"ssb/generated/5.sql"},
                                             parallelDegreeSSB,
                                             true));
 }*/
 
}


TEST_SUITE ("ssb-sf20-distributed" * doctest::skip(SKIP_SUITE)) {

int parallelDegreeSSB = 4;

TEST_CASE ("ssb-sf20-distributed-original-select" * doctest::skip(false || SKIP_SUITE)) {
  cout << "input the path of sql instrs:" << endl;
  string s;
  ::std::cin >> s;
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf20-sortlineorder/csv/",
                                            {s},
                                            parallelDegreeSSB,
                                            true));
}
}

TEST_SUITE ("ssb-sf30-distributed" * doctest::skip(SKIP_SUITE)) {

int parallelDegreeSSB = 4;

TEST_CASE ("ssb-sf30-distributed-original-select" * doctest::skip(false || SKIP_SUITE)) {
  cout << "input the path of sql instrs:" << endl;
  string s;
  ::std::cin >> s;
  REQUIRE(TestUtil::e2eNoStartCalciteServer("ssb-sf30-sortlineorder/csv/",
                                            {s},
                                            parallelDegreeSSB,
                                            true));
}
}
}

