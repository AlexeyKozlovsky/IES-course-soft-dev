#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTWRAPPERDISCONNECTEDSTATE_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTWRAPPERDISCONNECTEDSTATE_H_

#include <shared_mutex>

#include "modbuswrappers/modbuswrapper.h"
#include "modbusclientwrapper.h"

using modbus::ModbusClient;


class ModbusClientWrapperDisconnectedState: public ModbusWrapper {
 public:
  explicit ModbusClientWrapperDisconnectedState(const std::shared_ptr<ModbusClientWrapper> &state_machine,
      const std::shared_ptr<ModbusClient> &modbus_client,
      const std::shared_ptr<std::mutex> &modbus_client_mutex);

  ErrorCode connect() override;
  ErrorCode disconnect() override;
  ErrorCode isConnected(bool &is_connected) override;
  ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;
  ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) override;
  ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) override;
  ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;

 private:
  std::shared_ptr<ModbusClientWrapper> _state_machine = nullptr;

  std::shared_ptr<std::mutex> _modbus_client_mutex = nullptr;
  std::shared_ptr<ModbusClient> _modbus_client;

};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTWRAPPERDISCONNECTEDSTATE_H_
