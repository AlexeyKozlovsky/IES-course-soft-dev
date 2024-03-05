#include "devicecontroller.h"

#include <QDebug>


DeviceController::DeviceController(const std::shared_ptr<DeviceView> &device_view,
                                   const std::shared_ptr<DeviceModel> &device_model,
                                   QObject *parent):
                                   QObject(parent),
                                   _device_view(device_view),
                                   _device_model(device_model) {
  setConnections();
}

void DeviceController::setConnections() {
  if (_device_view != nullptr) {
    QObject::connect(_device_view.get(), &DeviceView::periodChangedSignal,
                     this, &DeviceController::periodChangedViewSlot);
  }

  if (_device_model != nullptr) {
    QObject::connect(_device_model.get(), &DeviceModel::periodChangedSignal,
                     this, &DeviceController::periodChangedModelSlot);
  }
}

void DeviceController::periodChangedViewSlot(const QString &period) {
  if (_device_model != nullptr) {
    bool is_ok = false;
    uint64_t period_value = period.toULongLong(&is_ok);

    if (is_ok) {
      _device_model->setPeriod(period_value);
    } else {
      qCritical() << "PERIOD IS INVALID " << __func__;
    }
  }
}

void DeviceController::periodChangedModelSlot(uint64_t period) {
  if (_device_view != nullptr) {
    auto period_text = QString::number(period);
    _device_view->setPeriod(period_text);
  }
}
