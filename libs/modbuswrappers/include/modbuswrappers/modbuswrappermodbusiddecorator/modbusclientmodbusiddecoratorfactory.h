#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERMODBUSIDDECORATOR_MODBUSCLIENTMODBUSIDDECORATORFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERMODBUSIDDECORATOR_MODBUSCLIENTMODBUSIDDECORATORFACTORY_H_

#include "modbuswrappers/modbuswrapperfactory.h"
#include "modbuswrappers/modbuswrapperstorage.h"


class ModbusClientModbusIDDecoratorFactory: public ModbusWrapperFactory {
 public:
  explicit ModbusClientModbusIDDecoratorFactory(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory,
                                                const std::shared_ptr<ModbusWrapperStorage> &modbus_wrapper_storage);

  std::shared_ptr<ModbusWrapper> createModbusWrapper(const std::string &ip,
                                                     int port,
                                                     int modbus_id,
                                                     int holding_regs_count,
                                                     int input_regs_count) override;

  std::shared_ptr<ModbusWrapper> createBaseModbusWrapper(const std::string &ip, int port) override;

 private:
  std::shared_ptr<ModbusWrapperStorage> _modbus_wrapper_storage = nullptr;
  std::shared_ptr<ModbusWrapperFactory> _base_modbus_wrapper_factory = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERMODBUSIDDECORATOR_MODBUSCLIENTMODBUSIDDECORATORFACTORY_H_
