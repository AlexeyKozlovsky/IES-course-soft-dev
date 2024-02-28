#include <iostream>

#include "modbus/modbus.h"


int main() {
  std::string ip = "10.10.110.26";
  int port = 4001;
  int modbus_id = 1;
  modbus::ModbusClient modbus_client(ip, port);

  modbus_client.connect();

  bool is_connected = modbus_client.isConnected();
  if (is_connected) {
    std::cout << "Successfully connected" << std::endl;

    uint16_t reg_num = 10;
    uint16_t reg_value;

    auto error_code = modbus_client.readHoldingRegister(reg_num, reg_value, modbus_id);
    if (error_code == modbus::NO_MODBUS_ERROR) {
      std::cout << "Successfully read holding register " << reg_value << std::endl;
    } else {

      std::cerr << "Error while reading holding register:\t" << error_code << std::endl;

      modbus_client.disconnect();
      return EXIT_FAILURE;
    }

  } else {
    std::cerr << "Cannot connect " << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Hello, World!" << std::endl;
  return EXIT_SUCCESS;
}
