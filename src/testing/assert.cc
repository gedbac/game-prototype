#include "assert.h"
#include "assertion_exception.h"
#include <string.h>

using namespace std;
using namespace raven::testing;

Assert::Assert() {
}

Assert::~Assert() {
}

void Assert::Fail(string message) {
  if (!message.empty()) {
    throw AssertionException(message);
  } else {
    throw AssertionException();
  }
}

void Assert::IsTrue(bool condition, string message) {
  if (condition != true) {
    Fail(message);  
  }
}

void Assert::IsFalse(bool condition, string message) {
  if (condition != false) {
    Fail(message);
  }
}

void Assert::AreEqual(const char* expected, const char* actual, string message) {
  if (strcmp(actual, expected) != 0) {
    Fail(message);
  }
}

void Assert::AreEqual(string expected, string actual, string message) {
  if (actual.compare(expected) != 0) {
    Fail(message);
  }
}
