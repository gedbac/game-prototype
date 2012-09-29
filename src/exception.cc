#include "exception.h"

using namespace std;
using namespace raven;

Exception::Exception() 
    : message_("An exception has occurred"),
      inner_exception_(NULL) {
}

Exception::Exception(string message)
    : message_(message),
      inner_exception_(NULL) {
}

Exception::Exception(string message, Exception& exception)
    : message_(message),
      inner_exception_(NULL) {
  set_inner_exception(exception.Clone());
}

Exception::Exception(const Exception& exception) 
    : inner_exception_(NULL) {
  set_message(exception.message());
  if (exception.inner_exception() != NULL) {
    set_inner_exception(exception.inner_exception()->Clone());
  }
}

Exception* Exception::Clone() const { 
  return new Exception(*this); 
}

Exception::~Exception() {
  delete inner_exception_;
}
