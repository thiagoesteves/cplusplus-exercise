#ifndef EXE6_H
#define EXE6_H

#include <cstdint>
#include <memory>
#include "exe_interface.h"
#include "macros.h"
#include "error.h"

namespace cplusplus_exercise {

class SharedPointerClass2 {
 public:
  SharedPointerClass2() {
    std::cout << "# My Base constructor" << std::endl;
  };



  virtual ~SharedPointerClass2() {
    std::cout << "# The destructor was called automatically" << std::endl;
  };
};

class Exercise_6 : public ExeInterface {
 public:
  Exercise_6() {};
  ~Exercise_6() {};

  void description(void) {
    std::cout << "################################################################" << std::endl;
    std::cout << "# EXE6: Let's verify the behavior of smart pointer+factory     #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
  }

  void conclusion(void) {
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# We can see that before the creation of element the pointer   #" << std::endl;
    std::cout << "# is empty. After the factory function, we have the object and #" << std::endl;
    std::cout << "# the destructor will be called only after the context of the  #" << std::endl;
    std::cout << "# first smart pointer.                                         #" << std::endl;
    std::cout << "################################################################" << std::endl;
    std::cout << std::endl;
  }

  void FactoryOfSomething(std::shared_ptr<SharedPointerClass1>* ptr) {
    (*ptr).reset(new SharedPointerClass1());

    if ((*ptr).get()) {
      std::cout << "# The pointer is NOT NULL ptr.get():                " << (*ptr).get() << std::endl;
      std::cout << "#                         ptr.use_count():          " << (*ptr).use_count() << std::endl;
    } else {
      std::cout << "# The pointer is NOT OK " << std::endl;
    }
    std::cout << "# End of function" << std::endl;
  }

  void execute(void) {
    std::shared_ptr<SharedPointerClass1> ptr;

    std::cout << "# After new:              ptr.get():                " << ptr.get() << std::endl;
    std::cout << "#                         ptr.use_count():          " << ptr.use_count() << std::endl;
    std::cout << "# " << std::endl;
    this->FactoryOfSomething(&ptr);
    std::cout << "# " << std::endl;
    std::cout << "# After function:         ptr.get():                " << ptr.get() << std::endl;
    std::cout << "#                         ptr.use_count():          " << ptr.use_count() << std::endl;
    std::cout << "# " << std::endl;
    std::cout << "# End of function" << std::endl;
  }

 private:
};

}  // cplusplus_exercise

#endif  // EXE6_H

