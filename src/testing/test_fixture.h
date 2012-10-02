#ifndef RAVEN_TESTING_TEST_FIXTURE_H_
#define RAVEN_TESTING_TEST_FIXTURE_H_

#include <vector>
#include <string>
#include <iostream>
#include "test_run_results.h"

namespace raven {
namespace testing {

class TestFixture {
  public:
    TestFixture(std::string name);
    ~TestFixture();
    void Run(TestRunResults* results);
    inline const std::string name() const { return name_; };
    
  protected:
    typedef void (TestFixture::*TestMethod)();
    inline void set_name(std::string name) { name_ = name; };
    virtual void TestFixtureSetup();
    virtual void TestFixtureTearDown();
    virtual void Setup();
    virtual void TearDown();
    void AddTest(std::string name, TestMethod test);

  private:
    std::string name_;
    std::vector<TestMethod>* tests_;
    std::vector<std::string>* tests_names_;
};

}
}

#endif
