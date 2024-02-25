#include "oopexample.h"


int ExampleClass::foo(int param) {
  return _example_struct.x + _example_struct.y + param;
}

int ExampleClass::someMethod() {
  return 0;
}
