#include <iostream>

#include <modbus/modbus.h>

#include "device/device.h"


int main() {
  std::string ip = "192.168.127.10";
  int port = 4001;
  int modbus_id = 1;

  auto modbus_client = std::make_shared<modbus::ModbusClient>(ip, port);
  auto device = std::make_shared<Device>(modbus_client, modbus_id);

  if (device != nullptr) {
    auto connect_result = device->connect();
    if (!connect_result) {
      std::cerr << "Failed to connect via MODBUS " << __func__ << std::endl;
      return EXIT_FAILURE;
    }

    auto result = device->getInnerStartPeriod();
    std::cout << "Result of getInnerStartPeriod:\t" << result << std::endl;
  }

  return EXIT_SUCCESS;
}
