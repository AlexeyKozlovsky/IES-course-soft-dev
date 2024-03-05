#ifndef CPP_PROJECT_TEMPLATE_MVC_DEVICE_MODELS_DEVICEMODEL_H_
#define CPP_PROJECT_TEMPLATE_MVC_DEVICE_MODELS_DEVICEMODEL_H_

#include <QObject>

class DeviceModel: public QObject {
  Q_OBJECT
 public:
  explicit DeviceModel(QObject *parent = nullptr);

  virtual void setPeriod(uint64_t period) = 0;
  virtual uint64_t getPeriod() = 0;

 signals:
  void periodChangedSignal(uint64_t period);
};

#endif //CPP_PROJECT_TEMPLATE_MVC_DEVICE_MODELS_DEVICEMODEL_H_
