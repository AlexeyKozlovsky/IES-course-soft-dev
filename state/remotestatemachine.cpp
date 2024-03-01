#include "remotestatemachine.h"

RemoteStateMachine::RemoteStateMachine(const std::shared_ptr<Remote> &broken_state,
                                       const std::shared_ptr<Remote> &working_state):
    _broken_state(broken_state),
    _working_state(working_state) {

}

void RemoteStateMachine::onClick() {
  if (_current_state != nullptr) {
    _current_state->onClick();
  }
}

void RemoteStateMachine::changeState(const std::string &state_name) {
  if (state_name == "working") {
    _current_state = _working_state;
  } else if (state_name == "broken") {
    _current_state = _broken_state;
  }
}
