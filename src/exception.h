#ifndef RAVEN_EXCEPTION_H_
#define RAVEN_EXCEPTION_H_

#include <string>
#include "iclonable.h"

namespace raven {

class Exception : IClonable {
  public:
    Exception();
    Exception(std::string message);
    Exception(std::string message, Exception& exception);
    Exception(const Exception& exception);
    ~Exception();
    inline std::string message() const { return message_; };
    inline Exception* inner_exception() const { return inner_exception_; }
    virtual Exception* Clone() const;
    
  protected:
    inline void set_message(std::string message) { message_ = message; };
    inline void set_inner_exception(Exception* exception) { 
      inner_exception_ = exception; 
    };

  private:
    std::string message_;
    Exception* inner_exception_;
};

}

#endif
