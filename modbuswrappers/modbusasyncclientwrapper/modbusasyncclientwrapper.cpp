#include "modbusasyncclientwrapper.h"

ModbusAsyncClientWrapper::ModbusAsyncClientWrapper(std::shared_ptr<ModbusDividableClientWrapper> modbus_wrapper,
                                                   int holding_begin_reg_num,
                                                   int holding_regs_count,
                                                   int input_begin_reg_num,
                                                   int input_regs_count) :
  _modbus_wrapper(modbus_wrapper),
  _holding_begin_reg_num(holding_begin_reg_num),
  _holding_regs_count(holding_regs_count),
  _input_begin_reg_num(input_begin_reg_num),
  _input_regs_count(input_regs_count) {

}

ErrorCode ModbusAsyncClientWrapper::connect() {
  return DEVICE_NOT_RESPONDING_LAN;
}

ErrorCode ModbusAsyncClientWrapper::disconnect() {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusAsyncClientWrapper::isConnected(bool &is_connected) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusAsyncClientWrapper::readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) {
  auto error_code = OPERATION_INTERRUPTED;

  if (reg_num >= 0 && reg_num < _holding_registers.size()) {
    value = _holding_registers[reg_num];
    error_code = SUCCESS;
  }

  return error_code;
}

ErrorCode ModbusAsyncClientWrapper::readHoldingRegisters(int reg_num,
                                                         int reg_count,
                                                         std::vector<uint16_t> &values,
                                                         int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusAsyncClientWrapper::writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) {
  auto error_code = OPERATION_INTERRUPTED;
  if (_modbus_wrapper != nullptr) {
    error_code = _modbus_wrapper->writeHoldingRegister(reg_num, value, modbus_id);
  }

  return error_code;
}

ErrorCode ModbusAsyncClientWrapper::writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusAsyncClientWrapper::readInputRegister(int reg_num, uint16_t &value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusAsyncClientWrapper::readInputRegisters(int reg_num,
                                                       int reg_count,
                                                       std::vector<uint16_t> &values,
                                                       int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
void ModbusAsyncClientWrapper::addConnectable(const std::shared_ptr<Connectable> &connectable) {
  ModbusWrapper::addConnectable(connectable);
}
void ModbusAsyncClientWrapper::sendConnectionStatus(bool connection_status) {
  ModbusWrapper::sendConnectionStatus(connection_status);
}
void ModbusAsyncClientWrapper::process() {
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->readHoldingRegisters(_holding_begin_reg_num, _holding_regs_count, _holding_registers);
    _modbus_wrapper->readInputRegisters(_input_begin_reg_num, _input_regs_count, _input_registers);
  }
}
