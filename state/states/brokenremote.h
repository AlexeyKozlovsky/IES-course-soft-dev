#ifndef CPP_PROJECT_TEMPLATE_STATE_STATES_BROKENREMOTE_H_
#define CPP_PROJECT_TEMPLATE_STATE_STATES_BROKENREMOTE_H_

#include "state/remote.h"

class BrokenRemote: public Remote {
 public:
  void onClick() override;
};

#endif //CPP_PROJECT_TEMPLATE_STATE_STATES_BROKENREMOTE_H_
