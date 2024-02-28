#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_STANDALONEVALUECALLBACKS_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_STANDALONEVALUECALLBACKS_H_

#include "services/models/valuecallbacks.h"


class BoolValueStandaloneCallback: public BoolValueCallback {
  Q_OBJECT
 public:
  BoolValueStandaloneCallback(QObject *parent = nullptr);
};

class DoubleValueStandaloneCallback: public DoubleValueCallback {
 Q_OBJECT
 public:
  DoubleValueStandaloneCallback(QObject *parent = nullptr);
};


#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_STANDALONEVALUECALLBACKS_H_
