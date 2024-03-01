#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPERFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPERFACTORY_H_

#include "modbuswrappers/modbuswrapperfactory.h"
//#include "modbuswrappers/modbuswrapper.h"


class ModbusAsyncClientWrapperFactory: public ModbusWrapperFactory {
 public:
  explicit ModbusAsyncClientWrapperFactory(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory);

  std::shared_ptr<ModbusWrapper> createModbusWrapper(const std::string &ip,
                                                     int port,
                                                     int modbus_id,
                                                     int holding_regs_count,
                                                     int input_regs_count) override;
  std::shared_ptr<ModbusWrapper> createBaseModbusWrapper(const std::string &ip, int port) override;

 private:
  /**
   * \warning ДЛЯ ИСПОЛЬЗОВАНИЯ КЛАССА НЕОБХОДИМ ОБЯЗАТЕЛЬНО БАЗОВЫЙ ОБЪЕКТ МОДБАС ПОДКЛЮЧЕНИЯ С MODBUSID декоратором
   */
  std::shared_ptr<ModbusWrapperFactory> _base_modbus_wrapper_factory = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPERFACTORY_H_
