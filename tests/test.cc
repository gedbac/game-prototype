#include <iostream>
#include "game_test_suite.h"

using namespace std;
using namespace raven::testing;

#include "game_test_suite.h"

int main() {
  cout << "game prototype test version 1.0" << endl;
  cout << "copyright (c) 2012 gediminas backevicius" << endl;
  GameTestSuite* suite = new GameTestSuite(); 
  bool passed = suite->Run();
  delete suite;
  return passed ? 0 : 1;
}
