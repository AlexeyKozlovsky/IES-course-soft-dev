#include "testclass.h"

#include <iostream>


TestClass::TestClass(int a) {
  _a = a;
}

void TestClass::printSomething() {
  std::cout << "Print something" << std::endl;
  someLogic();
}

void TestClass::someLogic() {
  std::cout << "some logic" << std::endl;
}
