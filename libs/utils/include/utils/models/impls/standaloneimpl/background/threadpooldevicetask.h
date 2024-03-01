#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL1_THREADPOOLDEVICETASK_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL1_THREADPOOLDEVICETASK_H_

#include <memory>

#include "threadpooling/iprocessable.h"


class ThreadPoolDeviceTask: public IProcessable {
 public:
  explicit ThreadPoolDeviceTask(const std::shared_ptr<IProcessable> &modbus_wrapper_device_task,
                                const std::shared_ptr<IProcessable> &device_task);
  void process() override;

 private:
  std::shared_ptr<IProcessable> _modbus_wrapper_device_task = nullptr;
  std::shared_ptr<IProcessable> _device_task = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_IMPL1_THREADPOOLDEVICETASK_H_
