#ifndef CPP_PROJECT_TEMPLATE_FACTORIES_MODBUSWRAPPERFACTORY_H_
#define CPP_PROJECT_TEMPLATE_FACTORIES_MODBUSWRAPPERFACTORY_H_

#include <modbuswrappers/modbuswrapperstorage.h>
#include <modbuswrappers/modbuswrapperfactory.h>


class ModbusWrapperFactoryCreator {
 public:
  explicit ModbusWrapperFactoryCreator(const std::shared_ptr<ModbusWrapperStorage> &modbus_wrapper_storage);

  std::shared_ptr<ModbusWrapperFactory> createModbusWrapperFactory();

 private:
  std::shared_ptr<ModbusWrapperStorage> _modbus_wrapper_storage = nullptr;
};

#endif //CPP_PROJECT_TEMPLATE_FACTORIES_MODBUSWRAPPERFACTORY_H_
