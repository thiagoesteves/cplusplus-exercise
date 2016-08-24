#ifndef EXE3_H
#define EXE3_H

#include <cstdint>
#include "exe_interface.h"
#include "macros.h"
#include "error.h"

namespace cplusplus_exercise {

class Exercise_3 : public ExeInterface {
 public:
  Exercise_3() {};
  ~Exercise_3() {};

  void description(void) {
    std::cout << "################################################################" << std::endl;
    std::cout << "# EXE3: Let's verify the power of the const qualifier          #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
  }

  void conclusion(void) {
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# The problem here is about which is const or not:             #" << std::endl;
    std::cout << "#  const int *ptr_1; The value is const , but the pointer not  #" << std::endl;
    std::cout << "#  int const *ptr_2; The value is const , but the pointer not  #" << std::endl;
    std::cout << "#  int * const ptr_3 The value isn't const ,the pointer is     #" << std::endl;
    std::cout << "################################################################" << std::endl;
    std::cout << std::endl;
  }

  void execute(void) {
    const int *ptr_1 = new int;
    int const *ptr_2 = new int;
    int * const ptr_3 = new int;

    //(*ptr_1)++;   // THIS WON'T COMPILE
    ptr_1++;
    ptr_1--;

    //(*ptr_2)++;   // THIS WON'T COMPILE
    ptr_2++;
    ptr_2--;

    (*ptr_3)++;
    //ptr_3++;      // THIS WON'T COMPILE

    delete ptr_1;
    delete ptr_2;
    delete ptr_3;
  }

 private:
};

}  // cplusplus_exercise

#endif  // EXE3_H

