#include "modbuswrappers/mocks/modbuswrappermock1.h"

#include <utils/baseutils.h>


ErrorCode ModbusWrapperMock1::connect() {
  std::cout << "TEST CONNECT MOCK " << __func__ << std::endl;
  return SUCCESS;
}

ErrorCode ModbusWrapperMock1::disconnect() {
  std::cout << "TEST DISCONNECT MOCK "  << __func__ << std::endl;
  return SUCCESS;
}

ErrorCode ModbusWrapperMock1::isConnected(bool &is_connected) {
  std::cout << "IS CONNECTED MOCK "  << __func__ << std::endl;
  is_connected = false;
  return SUCCESS;
}

ErrorCode ModbusWrapperMock1::readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) {
  std::cout << "READ HOLDING REGSITER MOCK " << reg_num << " " << unsigned(value)  << __func__ << std::endl;
  return SUCCESS;
}


ErrorCode ModbusWrapperMock1::readHoldingRegisters(int reg_num,
                                                   int reg_count,
                                                   std::vector<uint16_t> &values,
                                                   int modbus_id) {
  std::cout << "READ HOLDING REGSITERS! MOCK " << reg_num << " " << reg_count  << __func__ << std::endl;
  return SUCCESS;
}

ErrorCode ModbusWrapperMock1::writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) {
  std::cout << "TEST WRITE HOLDING REGSITER MOCK " << reg_num << " " << unsigned (value) << " " << __func__ << std::endl;
  return SUCCESS;
}

ErrorCode ModbusWrapperMock1::writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) {
  std::cout << "WRITE HOLDING REGSITERS! MOCK " << reg_num << " " << value.size()  << __func__ << std::endl;
  return SUCCESS;
}

ErrorCode ModbusWrapperMock1::readInputRegister(int reg_num, uint16_t &value, int modbus_id) {
  std::cout << "READ INPUT REGSITER MOCK " << reg_num << " " << value << __func__ << std::endl;
  return SUCCESS;
}

ErrorCode ModbusWrapperMock1::readInputRegisters(int reg_num,
                                                 int reg_count,
                                                 std::vector<uint16_t> &values,
                                                 int modbus_id) {
  std::cout << "READ INPUT REGSITERS! MOCK " << reg_num << " " << reg_count  << __func__ << std::endl;
  return SUCCESS;
}
