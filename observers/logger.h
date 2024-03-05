#ifndef CPP_PROJECT_TEMPLATE_OBSERVERS_LOGGER_H_
#define CPP_PROJECT_TEMPLATE_OBSERVERS_LOGGER_H_

#include "observer.h"

class Logger: public Observer {
 public:
  void printLog();

  void update() override;
};

#endif //CPP_PROJECT_TEMPLATE_OBSERVERS_LOGGER_H_
