#ifndef EXE1_H
#define EXE1_H

#include <cstdint>
#include "exe_interface.h"
#include "macros.h"
#include "error.h"

namespace cplusplus_exercise {

class MyClass {
 public:
  MyClass() : i_(0), ptr_(new int) {}
  ~MyClass() { delete ptr_; };

  DISALLOW_COPY_AND_ASSIGN(MyClass);

  int i_;
  int *ptr_;
};

class Exercise_1 : public ExeInterface {
 public:
  Exercise_1() {};
  ~Exercise_1() {};

  void description(void) {
    std::cout << "################################################################" << std::endl;
    std::cout << "# EXE1: Let's verify the copy constructor passed by function:  #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
  }

  void conclusion(void) {
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# MyClass has a pointer ptr_, which is initialized by          #" << std::endl;
    std::cout << "# constructor, imagine that you could modify the sum function  #" << std::endl;
    std::cout << "# to work by copy constructor sum(MyClass myclass).            #" << std::endl;
    std::cout << "# It will occur an error if you do that, because the pointer   #" << std::endl;
    std::cout << "# was copied and deleted by the sum and you will try delete    #" << std::endl;
    std::cout << "# again in the destructor of my class.                         #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
    std::cout << "# The MACRO DISALLOW_COPY_AND_ASSIGN will define the copy      #" << std::endl;
    std::cout << "# constructor, but not implement it. This way you can avoid    #" << std::endl;
    std::cout << "# copy constructor.                                            #" << std::endl;
    std::cout << "################################################################" << std::endl;
    std::cout << std::endl;
  }

  void execute(void) {
    MyClass first;
    first.i_ = 2;
    *(first.ptr_) = 2;

    this->sum(first);
  }

  void sum(MyClass& myclass) {
    myclass.i_++;
    (*(myclass.ptr_))++;

    std::cout << "# The values here are: " << myclass.i_ << " and " << *(myclass.ptr_) << std::endl;
  }

 private:

};

}  // cplusplus_exercise

#endif

