#ifndef EXE_INTERFACE_H
#define EXE_INTERFACE_H

#include <cstdint>
#include "error.h"

namespace cplusplus_exercise {

class ExeInterface {
 public:
  ExeInterface() {}
  virtual ~ExeInterface() {};

  virtual void description(void) = 0;
  virtual void execute(void) = 0;
  virtual void conclusion(void) = 0;
};

}  // cplusplus_exercise

#endif  // EXE_INTERFACE_H

