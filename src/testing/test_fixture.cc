#include "test_fixture.h"
#include "assertion_exception.h"

using namespace std;
using namespace raven::testing;

TestFixture::TestFixture(string name) {
  name_ = name; 
  tests_  = new vector<TestMethod>(); 
  tests_names_ = new vector<string>();
}

TestFixture::~TestFixture() {
  delete tests_;
  delete tests_names_;
}

void TestFixture::AddTest(string name, TestMethod test) {
  if (!name.empty() && test) { 
    tests_names_->push_back(name);
    tests_->push_back(test);
  }
}

void TestFixture::TestFixtureSetup() {
}

void TestFixture::TestFixtureTearDown() {
}

void TestFixture::Setup() {
}

void TestFixture::TearDown() {
}

void TestFixture::Run(TestRunResults* results) {
  cout << "\n" << name() << ": \n------------------------" << endl;
  try {
    TestFixtureSetup();
    if (tests_) {
      for (unsigned int i = 0; i < tests_->size(); ++i) {
        results->set_total(results->total() + 1);
        try {
          Setup();
          try {   
            try {
              (this->*tests_->at(i))();
              cout << tests_names_->at(i) << ": passed" << endl;
            } catch (AssertionException& e) {
              results->set_failures(results->failures() + 1);
              cerr << tests_names_->at(i) << ": failed" << endl;
            }
          } catch (...) {
            results->set_errors(results->errors() + 1); 
            cerr << tests_names_->at(i) << ": error" << endl;
          }
        } catch (...) {
          cout << "Failed to setup a test: " << tests_names_->at(i) << endl;
          continue; 
        }
        try {
          TearDown();
        } catch (...) {
          cout << "Failed to teardown a test: " << tests_names_->at(i) << endl;
          continue; 
        }
      } 
    }
  } catch (...) {
    cerr << "Failed to setup a test fixture" << endl;
  }
  try {
    TestFixtureTearDown();
  } catch (...) {
    cerr << "Failed to tear down a test fixture" << endl;
  }
}
