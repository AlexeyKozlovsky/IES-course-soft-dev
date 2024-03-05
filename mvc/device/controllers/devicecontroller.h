#ifndef CPP_PROJECT_TEMPLATE_MVC_DEVICE_CONTROLLERS_DEVICECONTROLLER_H_
#define CPP_PROJECT_TEMPLATE_MVC_DEVICE_CONTROLLERS_DEVICECONTROLLER_H_

#include <memory>

#include <QObject>

#include "mvc/device/views/deviceview.h"
#include "mvc/device/models/devicemodel.h"


class DeviceController: public QObject {
  Q_OBJECT
 public:
  explicit DeviceController(const std::shared_ptr<DeviceView> &device_view,
                            const std::shared_ptr<DeviceModel> &device_model,
                            QObject *parent = nullptr);

 private:
  std::shared_ptr<DeviceView> _device_view = nullptr;
  std::shared_ptr<DeviceModel> _device_model = nullptr;

  void setConnections();

 private slots:
  void periodChangedViewSlot(const QString &period);
  void periodChangedModelSlot(uint64_t period);
};

#endif //CPP_PROJECT_TEMPLATE_MVC_DEVICE_CONTROLLERS_DEVICECONTROLLER_H_
