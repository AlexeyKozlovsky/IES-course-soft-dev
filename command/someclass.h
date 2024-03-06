#ifndef CPP_PROJECT_TEMPLATE_COMMAND_SOMECLASS_H_
#define CPP_PROJECT_TEMPLATE_COMMAND_SOMECLASS_H_

#include <memory>

#include "command.h"


class SomeClass {
 public:
  explicit SomeClass(const std::shared_ptr<Command> &command);

  void print();

 private:
  std::shared_ptr<Command> _command;
};

#endif //CPP_PROJECT_TEMPLATE_COMMAND_SOMECLASS_H_
