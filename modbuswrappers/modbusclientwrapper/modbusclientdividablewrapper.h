#ifndef MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTDIVIDABLEWRAPPER_H_
#define MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTDIVIDABLEWRAPPER_H_

#include "modbusclientwrapper.h"

#include <utils/services/domain/regreaddivider.h>


class ModbusClientDividableWrapper: public ModbusWrapper {
 public:
  explicit ModbusClientDividableWrapper(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                        int holding_regs_count,
                                        int input_regs_count);
  explicit ModbusClientDividableWrapper(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                        const std::shared_ptr<RegReadDivider> &holding_regs_divider,
                                        const std::shared_ptr<RegReadDivider> &input_regs_divider);

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
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;

  int _input_regs_count = 0;
  int _input_regs_per_request = 30;
  int _holding_regs_count = 0;
  int _holding_regs_per_request = 30;
  std::shared_ptr<RegReadDivider> _holding_regs_divider = nullptr;
  std::shared_ptr<RegReadDivider> _input_regs_divider = nullptr;
};


#endif //MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTDIVIDABLEWRAPPER_H_
