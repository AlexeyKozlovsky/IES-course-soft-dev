#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERFACTORY_H_

#include <memory>
#include <string>

#include "modbuswrappers/modbuswrapper.h"


class ModbusWrapperFactory {
 public:
  virtual std::shared_ptr<ModbusWrapper> createModbusWrapper(const std::string &ip,
                                                             int port,
                                                             int modbus_id,
                                                             int holding_regs_count,
                                                             int input_regs_count) = 0;
  virtual std::shared_ptr<ModbusWrapper> createBaseModbusWrapper(const std::string &ip, int port) = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERFACTORY_H_
