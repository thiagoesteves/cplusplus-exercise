#ifndef EXE2_H
#define EXE2_H

#include <cstdint>
#include "exe_interface.h"
#include "macros.h"
#include "error.h"

namespace cplusplus_exercise {

class SimpleClass {
 public:
  SimpleClass() : i(0) {
    std::cout << "# My constructor" << std::endl;
  };
  ~SimpleClass() {
    std::cout << "# My destructor" << std::endl;
  };
 private:
  int i;
};

class Exercise_2 : public ExeInterface {
 public:
  Exercise_2() : size_(3) {};
  ~Exercise_2() {};

  void description(void) {
    std::cout << "################################################################" << std::endl;
    std::cout << "# EXE2: Let's verify one array of class and its destructor     #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
  }

  void conclusion(void) {
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# The problem here is when you declare the following array:    #" << std::endl;
    std::cout << "#   SimpleClass *ptr = new SimpleClass[10];                    #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# Try to do the code above and you will get an error in the    #" << std::endl;
    std::cout << "# delete function, because you have created an array and there #" << std::endl;
    std::cout << "# is only one pointer. The correct is to delete []             #" << std::endl;
    std::cout << "################################################################" << std::endl;
    std::cout << std::endl;
  }

  void execute(void) {
    /**
     * @brief This code is OK
     */
    SimpleClass *ptr = new SimpleClass;
    delete ptr;

    /**
     * @brief This code is NOT OK
     */
    //SimpleClass *ptr = new SimpleClass[size_];
    //delete ptr;

    /**
     * @brief This code is OK
     */
    //SimpleClass *ptr = new SimpleClass[size_];
    //delete[] ptr;
  }

 private:
  const int size_;
};

}  // cplusplus_exercise

#endif  // EXE2_H

