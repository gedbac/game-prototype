#include "test_suite.h"
#include "test_run_results.h"
#include <iostream>

using namespace std;
using namespace raven::testing;

TestSuite::TestSuite() {
  test_fixtures_ = new vector<TestFixture*>();
}

TestSuite::~TestSuite() {
  if (test_fixtures_) {
    for (unsigned int i = 0; i < test_fixtures_->size(); ++i) {
      delete test_fixtures_->at(i);      
    }
  }
  delete test_fixtures_;
}

void TestSuite::AddTestFixture(TestFixture* test_fixture) {
  if (test_fixture) {
    test_fixtures_->push_back(test_fixture); 
  }
}

bool TestSuite::Run() {
  TestRunResults* results = new TestRunResults();
  if (test_fixtures_->size() > 0) {
    for (unsigned int i = 0; i < test_fixtures_->size(); ++i) {
      try {
        test_fixtures_->at(i)->Run(results); 
      } catch(...) {
        results->set_errors(results->errors() + 1); 
        cerr << test_fixtures_->at(i)->name() << ": error" << endl; 
      }
    }
  }
  cout << "\ntest run results: total " << results->total() << ", failures " 
    << results->failures() << ", errors " << results->errors() << endl; 
  bool passed = results->failures() == 0;
  delete results;
  return passed;
}
