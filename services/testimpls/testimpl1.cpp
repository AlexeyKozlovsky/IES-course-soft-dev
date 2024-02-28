#include "testimpl1.h"

#include <iostream>


void TestImpl1::someMethod() {
  std::cout << "impl1. before" << std::endl;

  std::cout << "impl1. after" << std::endl;
}

void TestImpl1::solve() {
  std::cout << "solve" << std::endl;
}
