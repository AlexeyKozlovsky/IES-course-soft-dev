#ifndef MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSPOSTPONEDWRITEWRAPPER_MODBUSPOSTPONEDWRITEWRAPPER_H_
#define MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSPOSTPONEDWRITEWRAPPER_MODBUSPOSTPONEDWRITEWRAPPER_H_

#include <memory>

#include <utils/services/domain/regreaddivider.h>

#include "modbuswrappers/modbusasyncclientwrapper/abstractmodbusasyncclientwrapper.h"


class ModbusPostponedWriteWrapper: public ModbusWrapper {
 public:
  explicit ModbusPostponedWriteWrapper(const std::shared_ptr<AbstractModbusAsyncClientWrapper> &modbus_wrapper);

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
  int _holding_regs_count = 0;
  std::vector<uint16_t> _tmp_holding_regs;

  std::shared_ptr<AbstractModbusAsyncClientWrapper> _modbus_wrapper = nullptr;

  std::shared_ptr<RegReadDivider> _holding_regs_divider = nullptr;

  bool start_postponing = false;

  void updateTempHoldingRegs();
  bool validateRegNum(int reg_num);
};

#endif //MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSPOSTPONEDWRITEWRAPPER_MODBUSPOSTPONEDWRITEWRAPPER_H_
