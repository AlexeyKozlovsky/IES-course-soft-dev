#include "device.h"

Device::Device(const std::shared_ptr<ModbusClient> &modbus_client,
               int modbus_id):
               _modbus_client(modbus_client),
               _modbus_id(modbus_id) {

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
  uint64_t result = 0;

  if (_modbus_client != nullptr) {
    std::vector<uint16_t> reg_values(2);
    auto error_code = _modbus_client->readHoldingRegisters(2, 2, reg_values, _modbus_id);
    if (error_code != modbus::NO_MODBUS_ERROR) {
      std::cerr << "Error while reading holding registers " << __func__ << std::endl;
      return result;
    }

    uint32_t merged_value;
    modbus::fromMsbLsb(reg_values[0], reg_values[1], merged_value);

    result = merged_value * 25 + 100;
  }

  return result;
}
