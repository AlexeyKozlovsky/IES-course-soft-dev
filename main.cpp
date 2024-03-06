#include <iostream>

#include "command/helloworldcommand.h"
#include "command/someclass.h"


int main(int argc, char *argv[]) {
  auto hello_world_command = std::make_shared<HelloWorldCommand>();

  auto some_class = std::make_shared<SomeClass>(hello_world_command);
  some_class->print();

  return 0;
}
