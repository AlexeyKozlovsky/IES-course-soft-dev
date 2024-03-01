#include "device.h"

Device::Device(const std::shared_ptr<ModbusWrapper> &modbus_wrapper):
  _modbus_wrapper(modbus_wrapper) {

}

bool Device::connect() {
  bool result = false;
  if (_modbus_wrapper != nullptr) {
    result = _modbus_wrapper->connect();
  }

  return result;
}

void Device::disconnect() {
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->disconnect();
  }
}

uint64_t Device::getInnerStartPeriod() {
  uint64_t result = 0;

  if (_modbus_wrapper != nullptr) {
    std::vector<uint16_t> reg_values(2);
    auto error_code = _modbus_wrapper->readHoldingRegisters(2, 2, reg_values);
    if (error_code != SUCCESS) {
      std::cerr << "Error while reading holding registers " << __func__ << std::endl;
      return result;
    }

    uint32_t merged_value;
    modbus::fromMsbLsb(reg_values[0], reg_values[1], merged_value);

    result = merged_value * 25 + 100;
  }

  return result;
}
