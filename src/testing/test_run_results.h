#ifndef RAVEN_TESTING_TEST_RUN_RESULTS_H_
#define RAVEN_TESTING_TEST_RUN_RESULTS_H_

namespace raven {
namespace testing {

class TestRunResults {
  public:
    TestRunResults();
    ~TestRunResults();
    inline int total() const { return total_; };
    inline void set_total(int total) { total_ = total; };
    int failures() const { return failures_; };
    void set_failures(int failures) { failures_ = failures; };
    int errors() const { return errors_; };
    void set_errors(int errors) { errors_ = errors; }

  private:
    int total_;
    int failures_;
    int errors_;
};

}
}

#endif
