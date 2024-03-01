#ifndef CPP_PROJECT_TEMPLATE_STATE_REMOTESTATEMACHINE_H_
#define CPP_PROJECT_TEMPLATE_STATE_REMOTESTATEMACHINE_H_

#include <memory>
#include <string>

#include "remote.h"


class RemoteStateMachine: public Remote {
 public:
  explicit RemoteStateMachine(const std::shared_ptr<Remote> &broken_state,
                              const std::shared_ptr<Remote> &working_state);

  void onClick() override;

  void changeState(const std::string &state_name);

 private:
  std::shared_ptr<Remote> _broken_state = nullptr;
  std::shared_ptr<Remote> _working_state = nullptr;

  std::shared_ptr<Remote> _current_state = nullptr;
};

#endif //CPP_PROJECT_TEMPLATE_STATE_REMOTESTATEMACHINE_H_
