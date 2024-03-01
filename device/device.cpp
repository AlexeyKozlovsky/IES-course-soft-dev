#include "device.h"

Device::Device(const std::shared_ptr<ModbusClient> &modbus_client, int modbus_id) :
  _modbus_client(modbus_client), _modbus_id(modbus_id) {

}

bool Device::connect() {
  bool result = false;
  if (_modbus_client != nullptr) {
    result = _modbus_client->connect();
  }

  return result;
}

void Device::disconnect() {
  if (_modbus_client != nullptr) {
     _modbus_client->disconnect();
  }
}

uint64_t Device::getInnerStartPeriod() {
  uint64_t period = 0;
  if (_modbus_client != nullptr) {
    std::vector<uint16_t> register_values;

    auto error_code = _modbus_client->readHoldingRegisters(2, 2, register_values, _modbus_id);
    if (error_code != modbus::NO_MODBUS_ERROR) {
      std::cerr << "ERROR";
      return period;
    }

    uint32_t merged_reg_value;
    modbus::fromMsbLsb(register_values[0], register_values[1], merged_reg_value);

    period = (uint64_t) merged_reg_value * 25 + 100;
  }

  return period;
}
