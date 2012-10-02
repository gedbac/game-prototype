#ifndef RAVEN_TESTING_ASSERT_H_
#define RAVEN_TESTING_ASSERT_H_

#include <string>

namespace raven {
namespace testing {

class Assert {
  public:
    static void Fail(std::string message = "");
    static void IsTrue(bool condition, std::string message = "");
    static void IsFalse(bool condition, std::string message = "");
    static void AreEqual(int expected, int actual, std::string message = "");
    static void AreEqual(float expected, float actual, std::string message = "");
    static void AreEqual(const char* expected, const char* actual, 
      std::string message = "");
    static void AreEqual(std::string expected, std::string actual,
      std::string message = "");
    static void IsNull(void* object, std::string message = "");
    static void IsNotNull(void* object, std::string message = "");
    static void IsEmpty(std::string text, std::string message = "");
    static void IsNotEmpty(std::string text, std::string message = "");

  private:
    Assert();
    ~Assert();
};

}
}

#endif
