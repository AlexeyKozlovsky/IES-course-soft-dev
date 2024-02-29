#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERMODBUSIDDECORATOR_MODBUSCLIENTMODBUSIDDECORATOR_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERMODBUSIDDECORATOR_MODBUSCLIENTMODBUSIDDECORATOR_H_

#include <memory>
#include <vector>

#include "modbuswrappers/modbuswrapper.h"

class ModbusClientModbusIDDecorator: public ModbusWrapper {
 public:
  explicit ModbusClientModbusIDDecorator(const std::shared_ptr<ModbusWrapper> &modbus_wrapper, int modbus_id);

  ErrorCode connect() override;
  ErrorCode disconnect() override;
  ErrorCode isConnected(bool &is_connected) override;
  ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;
  ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id = 1) override;
  ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) override;
  ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;

  void addConnectable(const std::shared_ptr<Connectable> &connectable) override;
  void sendConnectionStatus(bool connection_status) override;

 private:
  int _modbus_id = 1;
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPERMODBUSIDDECORATOR_MODBUSCLIENTMODBUSIDDECORATOR_H_
