#include <iostream>

#include "modbuswrappers/mocks/modbuswrappermockfactory.h"


int main() {
  auto modbus_wrapper_factory = std::make_unique<ModbusWrapperMockFactory>();

  std::string ip = "192.168.127.2";
  int port = 4001;
  int modbus_id = 1;

  auto modbus_wrapper = modbus_wrapper_factory->createBaseModbusWrapper(ip, port);
  if (modbus_wrapper != nullptr) {
    auto error_code = modbus_wrapper->connect();
    if (error_code != SUCCESS) {
      std::cerr << "Error while connection attempt:\t" << error_code << std::endl;
      return EXIT_FAILURE;
    }

    uint16_t reg_num = 0;
    uint16_t reg_value;
    error_code = modbus_wrapper->readHoldingRegister(reg_num, reg_value, modbus_id);
    if (error_code != SUCCESS) {
      std::cerr << "Error while reading holding register:\t" << error_code << std::endl;
      modbus_wrapper->disconnect();
      return EXIT_FAILURE;
    } else {
      std::cout << "Successfully read holding register: " << reg_value << std::endl;
    };
  }

  return EXIT_SUCCESS;
}
