#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECALLBACKSUBSCRIPTIONS_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECALLBACKSUBSCRIPTIONS_H_

#include <QObject>


class CallbackSubscription: public QObject {
 Q_OBJECT
 public:
  explicit CallbackSubscription(QObject *parent = nullptr);

  virtual const QString &getAttrName() = 0;

  virtual bool subscribe() = 0;
  virtual bool unsubscribe() = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECALLBACKSUBSCRIPTIONS_H_
