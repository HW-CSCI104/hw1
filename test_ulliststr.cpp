#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("7");
  dat.pop_back();
  dat.pop_back();
  //std::cout << dat.get(0) << std::endl;
  //std::cout << dat.get(1) << std::endl;
  //std::cout << dat.get(2) << std::endl;
  // prints: 8 7 9
  //std::cout << dat.size() << std::endl;  // prints 3 since there are 3 strings stored
  //dat.printlist();
}
