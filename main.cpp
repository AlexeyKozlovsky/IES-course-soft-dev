#include <iostream>

#include "command/helloworldcommand.h"
#include "command/someclass.h"


int main(int argc, char *argv[]) {
  auto hello_world_command = std::make_shared<HelloWorldCommand>();


  return 0;
}
