#ifndef EXE7_H
#define EXE7_H

#include <cstdint>
#include <memory>
#include "exe_interface.h"
#include "macros.h"
#include "error.h"

namespace cplusplus_exercise {

struct Node {
   int data;
   std::shared_ptr<Node> next;

   Node(int n) { data = n; }
   /**
    * You really don't need this destructor, it is just to show when the
    * pointer is gone.
    */
   ~Node() { std::cout << "# I'm gone: " << this << std::endl; }
   void add_to_end(int n) {
      if (next.get()) {
         next->add_to_end(n);
      } else {
         next.reset(new Node(n));
      }
   }
   void print_pointer() {
     std::cout << " " << this;
     if (next.get()) {
       next->print_pointer();
     }
   }
};

class Exercise_7 : public ExeInterface {
 public:
  Exercise_7() {};
  ~Exercise_7() {};

  void description(void) {
    std::cout << "################################################################" << std::endl;
    std::cout << "# EXE7: Let's try a linked list with shared_pointer            #" << std::endl;
    std::cout << "#                                                              #" << std::endl;
  }

  void conclusion(void) {
    std::cout << "#                                                              #" << std::endl;
    std::cout << "#  After the root node goes out of scope, normally all the     #" << std::endl;
    std::cout << "# nodes would be deleted; but because spl points into this     #" << std::endl;
    std::cout << "# list and is still in scope, the node that spl points to      #" << std::endl;
    std::cout << "# isn't deleted. Instead, that target node and all the nodes   #" << std::endl;
    std::cout << "# to its right are preserved.                                  #" << std::endl;
    std::cout << "################################################################" << std::endl;
    std::cout << std::endl;
  }

  void execute(void) {
    std::shared_ptr<Node> spl;

    {
      Node root(10);
      root.add_to_end(20);
      root.add_to_end(30);
      root.add_to_end(100);

      std::cout << "# The linked list: ";
      root.print_pointer();
      std::cout << std::endl;
      spl = root.next->next;
    }  // root goes out of scope here.

    // But spl is still valid, the first two elements have gone
    std::cout << "# " << std::endl;
    std::cout << "# After the end of scope: " << std::endl;
    std::cout << "# The linked list: ";
    spl->print_pointer();
    std::cout << std::endl;
    std::cout << "# *spl = " << spl->data << std::endl;
  }

 private:
};

}  // cplusplus_exercise

#endif  // EXE7_H

