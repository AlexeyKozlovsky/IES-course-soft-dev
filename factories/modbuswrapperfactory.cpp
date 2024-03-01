#include "modbuswrapperfactory.h"

#include <modbuswrappers/mocks/modbuswrappermockfactory.h>
#include <modbuswrappers/modbuswrappermodbusiddecorator/modbusclientmodbusiddecoratorfactory.h>
#include <modbuswrappers/modbusclientwrapper/modbusclientwrapperfactory.h>
#include <modbuswrappers/modbusasyncclientwrapper/modbusasyncclientwrapperfactory.h>


ModbusWrapperFactoryCreator::ModbusWrapperFactoryCreator(const std::shared_ptr<ModbusWrapperStorage> &modbus_wrapper_storage):
  _modbus_wrapper_storage(modbus_wrapper_storage) {

}

std::shared_ptr<ModbusWrapperFactory> ModbusWrapperFactoryCreator::createModbusWrapperFactory() {
  std::shared_ptr<ModbusWrapperFactory> modbus_wrapper_factory = nullptr;

  auto base_modbus_wrapper_factory = std::make_shared<ModbusClientWrapperFactory>();
//  auto base_modbus_wrapper_factory = std::make_shared<ModbusWrapperMockFactory>();
  auto modbus_id_decorator_factory = std::make_shared<ModbusClientModbusIDDecoratorFactory>(base_modbus_wrapper_factory,
                                                                                            _modbus_wrapper_storage);
  modbus_wrapper_factory = std::make_shared<ModbusAsyncClientWrapperFactory>(modbus_id_decorator_factory);
  return modbus_wrapper_factory;
}
