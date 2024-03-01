#include <iostream>

#include <modbuswrappers/storages/modbuswrapperstorageimpl1.h>

#include "device/device.h"
#include "factories/modbuswrapperfactory.h"

int main() {
 // БЛОК, КОТОРЫЙ ГДЕ-ТО БУДЕТ
  auto modbus_wrapper_storage = std::make_shared<ModbusWrapperStorageImpl1>();
  auto modbus_wrapper_factory_creator = std::make_shared<ModbusWrapperFactoryCreator>(modbus_wrapper_storage);

  auto modbus_wrapper_factory = modbus_wrapper_factory_creator->createModbusWrapperFactory();

  // БЛОК, где мы просто используем фабрику

  std::string ip = "192.168.127.10";
  int port = 4001;
  int modbus_id = 1;
  int holding_regs_count = 30;
  int input_regs_count = 14;

  if (modbus_wrapper_factory != nullptr) {
    auto modbus_wrapper = modbus_wrapper_factory->createModbusWrapper(ip,
                                                                      port,
                                                                      modbus_id,
                                                                      holding_regs_count,
                                                                      input_regs_count);

    auto device = std::make_shared<Device>(modbus_wrapper);
    if (device != nullptr) {
      auto connect_result = device->connect();
      if (connect_result != SUCCESS) {
        std::cerr << "Failed to connect via MODBUS " << __func__ << std::endl;
        return EXIT_FAILURE;
      }

      auto result = device->getInnerStartPeriod();
      std::cout << "Result of getInnerStartPeriod:\t" << result << std::endl;
    }
  } else {
    std::cerr << "Modbus wrapper factory is nullptr " << __func__ << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
