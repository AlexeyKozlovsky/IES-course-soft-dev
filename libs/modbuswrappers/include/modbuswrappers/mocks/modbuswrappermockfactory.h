#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MOCKS_MODBUSWRAPPERMOCKFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MOCKS_MODBUSWRAPPERMOCKFACTORY_H_

#include "modbuswrappers/modbuswrapperfactory.h"


class ModbusWrapperMockFactory: public ModbusWrapperFactory {
 public:
  std::shared_ptr<ModbusWrapper> createModbusWrapper(const std::string &ip,
                                                     int port,
                                                     int modbus_id,
                                                     int holding_regs_count,
                                                     int input_regs_count) override;
  std::shared_ptr<ModbusWrapper> createBaseModbusWrapper(const std::string &ip, int port) override;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MOCKS_MODBUSWRAPPERMOCKFACTORY_H_
