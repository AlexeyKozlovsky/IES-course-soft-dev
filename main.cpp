#include <iostream>

#include "state/states/brokenremote.h"
#include "state/states/workingremote.h"
#include "state/remotestatemachine.h"


int main() {

  auto broken_state = std::make_shared<BrokenRemote>();
  auto working_state = std::make_shared<WorkingRemote>();
  auto remote_state_machine = std::make_shared<RemoteStateMachine>(broken_state, working_state);

  remote_state_machine->changeState("working");
  remote_state_machine->onClick();

  remote_state_machine->changeState("broken");
  remote_state_machine->onClick();

  return EXIT_SUCCESS;
}
