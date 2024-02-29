#ifndef CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_MODBUSCLIENTIDWRAPPER_MODBUSCLIENTIDWRAPPER_H_
#define CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_MODBUSCLIENTIDWRAPPER_MODBUSCLIENTIDWRAPPER_H_

#include "modbuswrappers/modbuswrapper.h"

class ModbusClientIDWrapper: public ModbusWrapper {
 public:
  explicit ModbusClientIDWrapper(const std::shared_ptr<ModbusWrapper> &modbus_client_wrapper,
                                 int modbus_id);

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
  int _modbus_id = 1;
  std::shared_ptr<ModbusWrapper> _modbus_client_wrapper = nullptr;
};

#endif //CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_MODBUSCLIENTIDWRAPPER_MODBUSCLIENTIDWRAPPER_H_
