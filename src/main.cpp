#include <iostream>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include "exe_interface.h"
#include "exe1.h"

using namespace std;
using namespace cplusplus_exercise;

/**
 * @brief You journey starts HERE
 */
int main(int argc, char** argv) {

  cout << "################################################################" << endl;
  cout << "# This Environment is just to test a few exercises that I have #" << endl;
  cout << "# seen during some interview questions and information from my #" << endl;
  cout << "# co-workers. Keep in mind that solving these exercises does   #" << endl;
  cout << "# not mean that you are a Senior and not a lot of interviewers #" << endl;
  cout << "# are able to see it.                                          #" << endl;
  cout << "#                                                              #" << endl;
  cout << "# When you were in the college, were you able to project       #" << endl;
  cout << "# something after the final programming test? Think about it.. #" << endl;
  cout << "#                                                              #" << endl;
  cout << "# The language is not so important                             #" << endl;
  cout << "################################################################" << endl;

  cout << endl;

  ExeInterface *exercises = new Exercise_1();

  exercises->description();
  exercises->execute();
  exercises->conclusion();

  delete exercises;

  return 0;
}
