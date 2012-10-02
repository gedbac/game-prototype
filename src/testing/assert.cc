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

void Assert::AreEqual(int expected, int actual, string message) {
  if (expected != actual) {
    Fail(message);
  }
}

void Assert::AreEqual(float expected, float actual, string message) {
  if (expected != actual) {
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

void Assert::IsNull(void* object, string message) {
  if (object != NULL) {
    Fail(message);
  }
}

void Assert::IsNotNull(void* object, string message) {
  if (object == NULL) {
    Fail(message);
  }
}

void Assert::IsEmpty(std::string text, std::string message) {
  if (!text.empty()) {
    Fail(message);
  }
}

void Assert::IsNotEmpty(std::string text, std::string message) {
  if (text.empty()) {
    Fail(message);
  }
}
