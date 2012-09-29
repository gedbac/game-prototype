#include <iostream>
#include "../src/testing/assertion_exception.h"
#include "../src/testing/assert.h"

using namespace std;
using namespace raven::testing;

int main() {
  cout << "game prototype test version 1.0" << endl;
  cout << "copyright (c) 2012 gediminas backevicius" << endl;
  try {
    Assert::Fail();
  } catch (AssertionException& e) {
    cout << e.message() << endl;
  }
  return 0;
}
