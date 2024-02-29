#ifndef MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPER2_H_
#define MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPER2_H_

#include <threadpooling/iprocessable.h>
#include <utils/services/domain/regreaddivider.h>

#include "abstractmodbusasyncclientwrapper.h"

class ModbusAsyncClientWrapper2: public AbstractModbusAsyncClientWrapper {
 public:
  explicit ModbusAsyncClientWrapper2(const std::shared_ptr<ModbusWrapper> &modbus_wrapper, int holding_regs_count, int input_regs_count);

  ErrorCode connect() override;
  ErrorCode disconnect() override;
  ErrorCode isConnected(bool &is_connected) override;
  ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id = 1) override;
  ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id = 1) override;
  ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id = 1) override;
  ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id = 1) override;
  ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id = 1) override;
  ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id = 1) override;

  void addConnectable(const std::shared_ptr<Connectable> &connectable) override;
  void sendConnectionStatus(bool connection_status) override;

  void process() override;

  const std::vector<uint16_t> &getHoldingRegs();
  const std::vector<uint16_t> &getInputRegs();

 private:
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;

  int _holding_regs_count = 1;
  int _input_regs_count = 1;

  std::vector<uint16_t> _holding_regs;
  std::vector<uint16_t> _input_regs;

  std::atomic<bool> _is_processed{false};
};
#endif //MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPER2_H_
