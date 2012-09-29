#ifndef RAVEN_ICLONABLE_H_
#define RAVEN_ICLONABLE_H_

namespace raven {

class IClonable {
  public:
    virtual IClonable* Clone() const = 0; 
};

}

#endif
