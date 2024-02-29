#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MOCKS_MODBUSWRAPPERMOCK1_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MOCKS_MODBUSWRAPPERMOCK1_H_

#include "modbuswrappers/modbuswrapper.h"

class ModbusWrapperMock1: public ModbusWrapper {
 public:
  ErrorCode connect() override;
  ErrorCode disconnect() override;
  ErrorCode isConnected(bool &is_connected) override;

  ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;
  ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id = 1) override;
  ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) override;

  ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MOCKS_MODBUSWRAPPERMOCK1_H_
