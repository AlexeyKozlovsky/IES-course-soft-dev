#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_

#include <string>
#include <memory>

#include <modbuswrappers/connectable.h>
#include <threadpooling/iprocessable.h>

#include "device/basedevice.h"


#include "devicetypes.h"


class DeviceEntityState {
 public:
  virtual GetInnerStartPeriodResponse getInnerStartPeriod(GetInnerStartPeriodRequest request) = 0;
};

class DeviceEntityRegCard: public DeviceEntityState, public Connectable {
 public:
  virtual void updateRegCard() = 0;
};

class DeviceEntity: public BaseDevice, public DeviceEntityState, public Connectable, public IProcessable {

};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_
