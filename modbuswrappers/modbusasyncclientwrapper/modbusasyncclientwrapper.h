#ifndef CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPER_H_
#define CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPER_H_

#include "modbuswrappers/modbuswrapper.h"


class ModbusAsyncClientWrapper: public ModbusWrapper {
 public:
  explicit ModbusAsyncClientWrapper(std::shared_ptr<ModbusDividableClientWrapper> modbus_wrapper,
                                    int holding_begin_reg_num,
                                    int holding_regs_count,
                                    int input_begin_reg_num,
                                    int input_regs_count);

  ErrorCode connect() override;
  ErrorCode disconnect() override;
  ErrorCode isConnected(bool &is_connected) override;
  ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;
  ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) override;
  ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) override;
  ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;
  void addConnectable(const std::shared_ptr<Connectable> &connectable) override;
  void sendConnectionStatus(bool connection_status) override;
  void process() override;

 private:
  int _holding_begin_reg_num = 0;
  int _holding_regs_count = 200;
  std::vector<uint16_t> _holding_registers;

  int _input_begin_reg_num = 0;
  int _input_regs_count = 10;
  std::vector<uint16_t> _input_registers;

  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;
};

#endif //CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_MODBUSASYNCCLIENTWRAPPER_MODBUSASYNCCLIENTWRAPPER_H_
