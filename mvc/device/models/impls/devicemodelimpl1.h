#ifndef CPP_PROJECT_TEMPLATE_MVC_DEVICE_MODELS_IMPLS_DEVICEMODELIMPL1_H_
#define CPP_PROJECT_TEMPLATE_MVC_DEVICE_MODELS_IMPLS_DEVICEMODELIMPL1_H_

#include "mvc/device/models/devicemodel.h"

class DeviceModelImpl1: public DeviceModel {
  Q_OBJECT
 public:
  explicit DeviceModelImpl1(QObject *parent = nullptr);

  void setPeriod(uint64_t period) override;
  uint64_t getPeriod() override;

 private:
  uint64_t _period = 0;
};

#endif //CPP_PROJECT_TEMPLATE_MVC_DEVICE_MODELS_IMPLS_DEVICEMODELIMPL1_H_
