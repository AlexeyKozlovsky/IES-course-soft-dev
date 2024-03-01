#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL3_THREADPOOLDEVICETASKFACTORYIMPL3_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL3_THREADPOOLDEVICETASKFACTORYIMPL3_H_

#include "services/models/impls/standaloneimpl/background/threadpooldevicetaskfactory.h"


class ThreadPoolDeviceTaskFactoryImpl3: public ThreadPoolDeviceTaskFactory {
 public:
  std::shared_ptr<IProcessable> createTask(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                           const std::shared_ptr<IProcessable> &base_device_entity) override;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL3_THREADPOOLDEVICETASKFACTORYIMPL3_H_
