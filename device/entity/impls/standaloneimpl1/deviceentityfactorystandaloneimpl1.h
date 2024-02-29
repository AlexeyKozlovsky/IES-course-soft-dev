#ifndef CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYFACTORYSTANDALONEIMPL1_H_
#define CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYFACTORYSTANDALONEIMPL1_H_

#include <memory>
#include <modbuswrappers/modbuswrapper.h>

#include "device/entity/deviceentityfactory.h"


class DeviceEntityFactoryStandaloneImpl1: public DeviceEntityFactory {
 public:

  std::shared_ptr<DeviceEntity> createDeviceEntity(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                   const std::shared_ptr<DeviceEntityDTO> &dto) override;


};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYFACTORYSTANDALONEIMPL1_H_
