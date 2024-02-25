#include "fooimpl1.h"

#include <iostream>


void FooImpl1::fooMethod() {
  std::cout << "Foo method " << __func__ << std::endl;
}
