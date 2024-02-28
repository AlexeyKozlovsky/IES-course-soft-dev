#include <iostream>

#include <memory>

#include "services/testclass.h"


int main() {
  double param = 1.;
  auto test = std::make_shared<TestClass>(param);
//  test->printSomething();
  return 0;
}
