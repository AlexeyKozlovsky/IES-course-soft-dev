#include "someclass.h"

SomeClass::SomeClass(const std::shared_ptr<Command> &command): _command(command) {

}


void SomeClass::print() {
  if (_command != nullptr) {}
  _command->execute();
}
