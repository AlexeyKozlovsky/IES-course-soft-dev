#include <iostream>

#include <memory>

#include "services/testimpls/testimpl1.h"


int main() {
  auto test_impl = std::make_shared<TestImpl1>();
//  std::shared_ptr<Test> test_base = std::make_shared<Test>();

  std::cout << "---------------------" << std::endl;
  test_impl->someMethod();
  std::cout << "---------------------" << std::endl;
  test_impl->solve();
//  test_base->someMethod();
  return 0;
}
