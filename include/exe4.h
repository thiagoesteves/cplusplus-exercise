#ifndef EXE4_H
#define EXE4_H

#include <cstdint>
#include "exe_interface.h"
#include "macros.h"
#include "error.h"

namespace cplusplus_exercise {

class BaseClass {
 public:
  BaseClass() {
    std::cout << "# My Base constructor" << std::endl;
  };

//  ~BaseClass() {
//    std::cout << "# My Base destructor" << std::endl;
//  };
//
  virtual ~BaseClass() {
    std::cout << "# My Base destructor" << std::endl;
  };
};

class DerivedBaseClass : public BaseClass {
 public:
  DerivedBaseClass() : BaseClass() {
    std::cout << "# My Derived constructor" << std::endl;
  };

  ~DerivedBaseClass() {
    std::cout << "# My Derived destructor" << std::endl;
  };
};

class Exercise_4 : public ExeInterface {
 public:
  Exercise_4() {};
  ~Exercise_4() {};

  void description(void) {
    std::cout << "################################################################" << std::endl;
    std::cout << "# EXE4: Let's verify why we should use a virtual destructor    #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
  }

  void conclusion(void) {
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# Because we are using one pointer to the base class and using #" << std::endl;
    std::cout << "# a derived class if the destructor is not virtual, when we    #" << std::endl;
    std::cout << "# delete the pointer, the derived's destructor is not called   #" << std::endl;
    std::cout << "################################################################" << std::endl;
    std::cout << std::endl;
  }

  void execute(void) {
    BaseClass *ptr = new DerivedBaseClass();

    delete ptr;
  }

 private:
};

}  // cplusplus_exercise

#endif  // EXE4_H

