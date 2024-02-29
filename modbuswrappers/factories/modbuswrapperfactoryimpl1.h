#ifndef CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_FACTORIES_MODBUSWRAPPERFACTORYIMPL1_H_
#define CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_FACTORIES_MODBUSWRAPPERFACTORYIMPL1_H_

#include "modbuswrappers/modbuswrapperfactory.h"


class ModbusWrapperFactoryImpl1: public ModbusWrapperFactory {
 public:
  std::shared_ptr<ModbusWrapper> createModbusWrapper(const std::string &ip,
                                                     int port,
                                                     int modbus_id,
                                                     int holding_regs_count,
                                                     int input_regs_count) override;
  std::shared_ptr<ModbusWrapper> createBaseModbusWrapper(const std::string &ip, int port) override;
};

#endif //CPP_PROJECT_TEMPLATE_MODBUSWRAPPERS_FACTORIES_MODBUSWRAPPERFACTORYIMPL1_H_
