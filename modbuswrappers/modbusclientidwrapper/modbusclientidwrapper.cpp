#include "modbusclientidwrapper.h"

explicit ModbusClientIDWrapper::ModbusClientIDWrapper(const std::shared_ptr<ModbusWrapper> &modbus_client_wrapper,
                                                      int modbus_id) :
  _modbus_client_wrapper(modbus_client_wrapper), _modbus_id(modbus_id){

}

ErrorCode ModbusClientIDWrapper::connect() {
  ErrorCode error_code = OPERATION_INTERRUPTED;
  if (_modbus_client_wrapper != nullptr) {
    error_code = _modbus_client_wrapper->connect();
  }

  return error_code;
}

ErrorCode ModbusClientIDWrapper::disconnect() {
  return DEVICE_NOT_RESPONDING_LAN;
}

ErrorCode ModbusClientIDWrapper::isConnected(bool &is_connected) {
  return DEVICE_NOT_RESPONDING_LAN;
}

ErrorCode ModbusClientIDWrapper::readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) {
  auto error_code = OPERATION_INTERRUPTED;

  if (_modbus_client_wrapper != nullptr) {
    error_code = _modbus_client_wrapper->readHoldingRegister(reg_num, value, _modbus_id);
  }

  return error_code;
}

ErrorCode ModbusClientIDWrapper::readHoldingRegisters(int reg_num,
                                                      int reg_count,
                                                      std::vector<uint16_t> &values,
                                                      int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}

ErrorCode ModbusClientIDWrapper::writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}

ErrorCode ModbusClientIDWrapper::writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}

ErrorCode ModbusClientIDWrapper::readInputRegister(int reg_num, uint16_t &value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}

ErrorCode ModbusClientIDWrapper::readInputRegisters(int reg_num,
                                                    int reg_count,
                                                    std::vector<uint16_t> &values,
                                                    int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}

void ModbusClientIDWrapper::addConnectable(const std::shared_ptr<Connectable> &connectable) {
  ModbusWrapper::addConnectable(connectable);
}

void ModbusClientIDWrapper::sendConnectionStatus(bool connection_status) {
  ModbusWrapper::sendConnectionStatus(connection_status);
}

void ModbusClientIDWrapper::process() {
  ModbusWrapper::process();
}
