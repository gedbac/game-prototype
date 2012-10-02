#include "game_test_suite.h"
#include "exception_tests.h"

GameTestSuite::GameTestSuite() {
  AddTestFixture(new ExceptionTests());
}

GameTestSuite::~GameTestSuite() {
}
