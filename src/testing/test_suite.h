#ifndef RAVEN_TESTING_TEST_SUITE_H_
#define RAVEN_TESTING_TEST_SUITE_H_

#include <vector>
#include <string.h>
#include "test_fixture.h"

namespace raven {
namespace testing {

class TestSuite {
  public:
    TestSuite();
    ~TestSuite();
    void AddTestFixture(TestFixture* test_fixture);
    bool Run();

  private:
    std::vector<TestFixture*>* test_fixtures_;
};

}
}

#endif
