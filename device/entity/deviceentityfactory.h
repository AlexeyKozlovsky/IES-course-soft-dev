#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITYFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITYFACTORY_H_

#include "deviceentity.h"
#include "devicetypes.h"

class DeviceEntityFactory {
 public:
  virtual std::shared_ptr<DeviceEntity> createDeviceEntity(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                           const std::shared_ptr<DeviceEntityDTO> &dto) = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITYFACTORY_H_
