#include <iostream>

#include "src/impls/fooimpl1.h"


int main() {
  auto foo = new FooImpl1();

  if (foo != nullptr) {
    foo->fooMethod();
  }

  return 0;
}
