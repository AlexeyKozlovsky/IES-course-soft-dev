#include "threadpooldevicetaskfactoryimpl3.h"

#include "services/models/impls/standaloneimpl/background/threadpooldevicetask.h"


std::shared_ptr<IProcessable> ThreadPoolDeviceTaskFactoryImpl3::createTask(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                                           const std::shared_ptr<IProcessable> &base_device_entity) {
  std::shared_ptr<IProcessable> result = nullptr;
  if (modbus_wrapper == nullptr) {
    return result;
  }

  if (base_device_entity == nullptr) {
    return result;
  }

  result = std::make_shared<ThreadPoolDeviceTask>(modbus_wrapper, base_device_entity);
  return result;
}
