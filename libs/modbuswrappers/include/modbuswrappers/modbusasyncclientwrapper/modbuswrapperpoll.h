#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_DEVICES_MODBUSWRAPPERPOLL_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_DEVICES_MODBUSWRAPPERPOLL_H_

#include <memory>

#include <threadpooling/iprocessable.h>

#include "modbusasyncclientwrapper.h"


class ModbusWrapperPoll: public IProcessable {
 public:
  explicit ModbusWrapperPoll(const std::shared_ptr<ModbusAsyncClientWrapper> &modbus_client_wrapper);

  void process() override;

 private:
  std::shared_ptr<ModbusAsyncClientWrapper> _modbus_async_client_wrapper = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_DEVICES_MODBUSWRAPPERPOLL_H_
