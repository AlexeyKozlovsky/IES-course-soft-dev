#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_CONNECTABLE_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_CONNECTABLE_H_

#include <utils/baseutils.h>


class Connectable {
 public:
  virtual void setConnectionStatus(bool connection_status) = 0;

  virtual bool getConnectionStatus() = 0;

  virtual ErrorCode connect() = 0;
  virtual ErrorCode disconnect() = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_CONNECTABLE_H_
