#include "exception_tests.h"
#include "../src/testing/assert.h"
#include "../src/exception.h"

using namespace std;
using namespace raven;
using namespace raven::testing;

ExceptionTests::ExceptionTests()
    : TestFixture("exception tests") {
  AddTest("raise exception", (TestMethod)&ExceptionTests::RaiseException);
}

ExceptionTests::~ExceptionTests() {
}

void ExceptionTests::RaiseException() {
  bool raised = false;
  try {
    try {
      throw Exception("A inner exception has occured");
    } catch (Exception& e) {
      throw Exception("An exception has oaccured", e);
    }
  }
  catch (Exception& e) {
    Assert::IsNotEmpty(e.message());
    Assert::IsNotNull(e.inner_exception());
    Assert::IsNotEmpty(e.inner_exception()->message());
    raised = true;
  }
  Assert::IsTrue(raised);
}
