#include "assertion_exception.h"

using namespace std;
using namespace raven::testing;

AssertionException::AssertionException() 
    : message_("An assertion exception has occurred") {
}

AssertionException::AssertionException(string message)
    : message_(message) {
}

AssertionException::~AssertionException() {
}
