#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_CALLBACKSUBSCRIPTIONFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_CALLBACKSUBSCRIPTIONFACTORY_H_

#include <memory>

#include <QString>

#include "valuecallbacks.h"
#include "valuecallbacksubscriptions.h"


class CallbackSubscriptionFactory {
 public:
  virtual std::shared_ptr<CallbackSubscription> createCallbackSubscription(const QString &attr_name,
                                                                           const std::shared_ptr<ValueCallback> &value_callback,
                                                                           QObject *parent = nullptr) = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_CALLBACKSUBSCRIPTIONFACTORY_H_
