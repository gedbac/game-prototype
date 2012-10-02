#include "test_run_results.h"

using namespace raven::testing;

TestRunResults::TestRunResults()
    : total_(0),
      failures_(0),
      errors_(0) {
}

TestRunResults::~TestRunResults() {
}
