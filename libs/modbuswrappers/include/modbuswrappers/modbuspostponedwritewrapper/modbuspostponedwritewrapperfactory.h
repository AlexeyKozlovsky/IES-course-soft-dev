#ifndef MODBUSWRAPPERS_LIBMODBUSWRAPPER_SRC_MODBUSWRAPPERS_MODBUSPOSTPONEDWRITEWRAPPER_MODBUSPOSTPONEDWRITEWRAPPERFACTORY_H_
#define MODBUSWRAPPERS_LIBMODBUSWRAPPER_SRC_MODBUSWRAPPERS_MODBUSPOSTPONEDWRITEWRAPPER_MODBUSPOSTPONEDWRITEWRAPPERFACTORY_H_

#include "modbuswrappers/modbuswrapperfactory.h"


class ModbusPostponedWriteWrapperFactory: public ModbusWrapperFactory {
 public:
  explicit ModbusPostponedWriteWrapperFactory(const std::shared_ptr<ModbusWrapperFactory> &base_modbus_wrapper_factory);

  std::shared_ptr<ModbusWrapper> createModbusWrapper(const std::string &ip,
                                                     int port,
                                                     int modbus_id,
                                                     int holding_regs_count,
                                                     int input_regs_count) override;
  std::shared_ptr<ModbusWrapper> createBaseModbusWrapper(const std::string &ip, int port) override;

 private:
  std::shared_ptr<ModbusWrapperFactory> _base_modbus_wrapper_factory = nullptr;
};

#endif //MODBUSWRAPPERS_LIBMODBUSWRAPPER_SRC_MODBUSWRAPPERS_MODBUSPOSTPONEDWRITEWRAPPER_MODBUSPOSTPONEDWRITEWRAPPERFACTORY_H_
