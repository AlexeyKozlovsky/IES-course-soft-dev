#ifndef MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTDIVIDABLEWRAPPERFACTORY_H_
#define MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTDIVIDABLEWRAPPERFACTORY_H_


#include "modbuswrappers/modbuswrapperfactory.h"


class ModbusClientDividableWrapperFactory: public ModbusWrapperFactory {
 public:
  explicit ModbusClientDividableWrapperFactory(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory);
  explicit ModbusClientDividableWrapperFactory(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory,
                                               int holding_start_reg,
                                               int holding_regs_per_request,
                                               int input_start_reg,
                                               int input_regs_per_request);

  std::shared_ptr<ModbusWrapper> createModbusWrapper(const std::string &ip,
                                                     int port,
                                                     int modbus_id,
                                                     int holding_regs_count,
                                                     int input_regs_count) override;

  std::shared_ptr<ModbusWrapper> createBaseModbusWrapper(const std::string &ip, int port) override;

 private:
  int _holding_start_reg = 0;
  int _holding_regs_per_request = 30;
  int _input_start_reg = 0;
  int _input_regs_per_request = 30;
  std::shared_ptr<ModbusWrapperFactory> _modbus_wrapper_factory = nullptr;
};


#endif //MODBUSWRAPPERS_LIBMODBUSWRAPPER_INCLUDE_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTDIVIDABLEWRAPPERFACTORY_H_
