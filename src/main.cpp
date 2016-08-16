#include <iostream>
#include <thread>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <vector>

#include "exe_interface.h"
#include "exe1.h"
#include "exe2.h"
#include "exe3.h"
#include "exe4.h"

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

  vector<ExeInterface *> exercises;

  exercises.push_back(new Exercise_1());
  exercises.push_back(new Exercise_2());
  exercises.push_back(new Exercise_3());
  exercises.push_back(new Exercise_4());

  for (auto i=exercises.begin(); i != exercises.end(); i++) {
    (*i)->description();
    (*i)->execute();
    (*i)->conclusion();
  }

  for (auto i=exercises.begin(); i != exercises.end(); i++) {
    delete *i;
  }

  return 0;
}
