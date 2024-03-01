#ifndef CPP_PROJECT_TEMPLATE_DEVICE_DEVICE_H_
#define CPP_PROJECT_TEMPLATE_DEVICE_DEVICE_H_

#include <cstdint>

#include <modbuswrappers/modbuswrapper.h>

class Device {
 public:
  explicit Device(const std::shared_ptr<ModbusWrapper> &modbus_wrapper);

  bool connect();
  void disconnect();

  uint64_t getInnerStartPeriod();

 private:
  uint64_t _inner_start_period = 0;

  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;
};

#endif //CPP_PROJECT_TEMPLATE_DEVICE_DEVICE_H_
