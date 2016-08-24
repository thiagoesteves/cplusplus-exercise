#ifndef EXE5_H
#define EXE5_H

#include <cstdint>
#include <memory>
#include "exe_interface.h"
#include "macros.h"
#include "error.h"

namespace cplusplus_exercise {

class SharedPointerClass1 {
 public:
  SharedPointerClass1() {
    std::cout << "# My Base constructor" << std::endl;
  };



  virtual ~SharedPointerClass1() {
    std::cout << "# The destructor was called automatically" << std::endl;
  };
};

class Exercise_5 : public ExeInterface {
 public:
  Exercise_5() {};
  ~Exercise_5() {};

  void description(void) {
    std::cout << "################################################################" << std::endl;
    std::cout << "# EXE5: Let's verify some smart pointers concepts              #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
  }

  void conclusion(void) {
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# In this example we are just using the smart pointer and we   #" << std::endl;
    std::cout << "# can verify that as soon as the pointer is passed to functions#" << std::endl;
    std::cout << "# the counter is incremented and it is decremented when returns#" << std::endl;
    std::cout << "################################################################" << std::endl;
    std::cout << std::endl;
  }

  void VerifySharedPointer(std::shared_ptr<SharedPointerClass1> ptr) {

    if (ptr.get()) {
      std::cout << "# The pointer is NOT NULL ptr.get():                " << ptr.get() << std::endl;
      std::cout << "#                         ptr.use_count():          " << ptr.use_count() << std::endl;
    } else {
      std::cout << "# The pointer is NOT OK " << std::endl;
    }
    ptr.reset();
    std::cout << "# End of function" << std::endl;
  }

  void execute(void) {
    std::shared_ptr<SharedPointerClass1> ptr(new SharedPointerClass1());

    std::cout << "# After new:              ptr.get():                " << ptr.get() << std::endl;
    std::cout << "#                         ptr.use_count():          " << ptr.use_count() << std::endl;
    std::cout << "# " << std::endl;
    this->VerifySharedPointer(ptr);
    std::cout << "# " << std::endl;
    std::cout << "# After function:         ptr.get():                " << ptr.get() << std::endl;
    std::cout << "#                         ptr.use_count():          " << ptr.use_count() << std::endl;
    std::cout << "# " << std::endl;
    std::cout << "# End of function" << std::endl;
  }

 private:
};

}  // cplusplus_exercise

#endif  // EXE5_H

