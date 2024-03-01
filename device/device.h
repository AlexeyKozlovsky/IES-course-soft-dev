#ifndef CPP_PROJECT_TEMPLATE_DEVICE_DEVICE_H_
#define CPP_PROJECT_TEMPLATE_DEVICE_DEVICE_H_

#include <cstdint>

#include <modbus/modbus.h>

using modbus::ModbusClient;

class Device {
 public:
  explicit Device(const std::shared_ptr<ModbusClient> &modbus_client, int modbus_id);

  bool connect();
  void disconnect();

  uint64_t getInnerStartPeriod();

 private:
  uint64_t _inner_start_period = 0;
  int _modbus_id = 1;

  std::shared_ptr<ModbusClient> _modbus_client = nullptr;
};

#endif //CPP_PROJECT_TEMPLATE_DEVICE_DEVICE_H_
