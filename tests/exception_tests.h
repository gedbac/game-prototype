#ifndef EXCEPTION_TESTS_H_
#define EXCEPTION_TESTS_H_

#include "../src/testing/test_fixture.h"

class ExceptionTests : public raven::testing::TestFixture {
  public:
    ExceptionTests();
    ~ExceptionTests();
    void RaiseException();
};

#endif
