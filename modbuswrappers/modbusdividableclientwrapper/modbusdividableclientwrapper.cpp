#include "modbusdividableclientwrapper.h"

ModbusDividableClientWrapper::ModbusDividableClientWrapper(const std::shared_ptr<ModbusWrapper> &modbus_wrapper):
  _modbus_wrapper(modbus_wrapper){

}

ErrorCode ModbusDividableClientWrapper::connect() {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::disconnect() {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::isConnected(bool &is_connected) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::readHoldingRegisters(int reg_num,
                                                             int reg_count,
                                                             std::vector<uint16_t> &values,
                                                             int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) {
  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::readInputRegister(int reg_num, uint16_t &value, int modbus_id) {

  return DEVICE_NOT_RESPONDING_LAN;
}
ErrorCode ModbusDividableClientWrapper::readInputRegisters(int reg_num,
                                                           int reg_count,
                                                           std::vector<uint16_t> &values,
                                                           int modbus_id) {

  // ВОТ ТУТ ЛОГИКА РАЗБИЕНИЯ НА НЕСКОЛЬКО ЗАПРОСОВ, ЕСЛИ ТРЕБУЕТСЯ!
  return DEVICE_NOT_RESPONDING_LAN;
}
void ModbusDividableClientWrapper::addConnectable(const std::shared_ptr<Connectable> &connectable) {
  ModbusWrapper::addConnectable(connectable);
}
void ModbusDividableClientWrapper::sendConnectionStatus(bool connection_status) {
  ModbusWrapper::sendConnectionStatus(connection_status);
}
void ModbusDividableClientWrapper::process() {
  ModbusWrapper::process();
}
