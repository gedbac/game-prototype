#ifndef SERVER_TEST_SUITE_H_
#define SERVER_TEST_SUITE_H_

#include "../src/testing/test_suite.h"

class GameTestSuite : public raven::testing::TestSuite {
  public:
    GameTestSuite();
    ~GameTestSuite();
};

#endif
