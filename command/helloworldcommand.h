#ifndef CPP_PROJECT_TEMPLATE_COMMAND_HELLOWORLDCOMMAND_H_
#define CPP_PROJECT_TEMPLATE_COMMAND_HELLOWORLDCOMMAND_H_

#include "command.h"

class HelloWorldCommand: public Command {
 public:
  void execute() override;
};

#endif //CPP_PROJECT_TEMPLATE_COMMAND_HELLOWORLDCOMMAND_H_
