#ifndef CPP_PROJECT_TEMPLATE_STATE_STATES_WORKINGREMOTE_H_
#define CPP_PROJECT_TEMPLATE_STATE_STATES_WORKINGREMOTE_H_

#include "state/remote.h"


class WorkingRemote: public Remote {
 public:
  void onClick() override;
};

#endif //CPP_PROJECT_TEMPLATE_STATE_STATES_WORKINGREMOTE_H_
