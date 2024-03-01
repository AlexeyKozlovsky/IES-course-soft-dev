#include <iostream>

#include <modbus/modbus.h>

#include "device/device.h"


int main() {
  std::string ip = "192.168.127.2";
  int port = 4001;
  int modbus_id = 1;

  auto modbus_client = std::make_shared<ModbusClient>(ip, port);

  auto device = std::make_shared<Device>(modbus_client, modbus_id);
  bool is_connected = device->connect();
  if (is_connected) {
    auto period = device->getInnerStartPeriod();
    std::cout  << "Period is:\t" << period << std::endl;
  } else {
    std::cerr << "Error while connection" << std::endl;
  }
}
