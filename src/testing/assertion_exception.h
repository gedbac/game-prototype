#ifndef RAVEN_TESTING_ASSERTION_EXCEPTION_H_
#define RAVEN_TESTING_ASSERTION_EXCEPTION_H_

#include <string>

namespace raven {
namespace testing {

class AssertionException {
  public:
    AssertionException();
    AssertionException(std::string message);
    ~AssertionException();
    inline const std::string message() const { return message_; };
    
  protected:
    void set_message(std::string message) { message_ = message; };

  private:
    std::string message_;
};

}
}

#endif
