#include "modbuswrapperfactoryimpl1.h"

#include <modbus/modbus.h>

#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperconnectedstate.h"
#include "modbuswrappers/modbusclientidwrapper/modbusclientidwrapper.h"
#include "modbuswrappers/modbusdividableclientwrapper/modbusdividableclientwrapper.h"
#include "modbuswrappers/modbusasyncclientwrapper/modbusasyncclientwrapper.h"

using modbus::ModbusClient;


std::shared_ptr<ModbusWrapper> ModbusWrapperFactoryImpl1::createModbusWrapper(const std::string &ip,
                                                                              int port,
                                                                              int modbus_id,
                                                                              int holding_regs_count,
                                                                              int input_regs_count) {
  auto modbus_client = std::make_shared<ModbusClient>();

  auto modbus_client_wrapper = std::make_shared<ModbusClientWrapperConnectedState>(nullptr, modbus_client, nullptr);
  auto modbus_id_client_wrapper = std::make_shared<ModbusClientIDWrapper>(modbus_client_wrapper, modbus_id);
  auto modbus_div_client_wrapper = std::make_shared<ModbusDividableClientWrapper>(modbus_id_client_wrapper);
  auto modbus_async_client_wrapper = std::make_shared<ModbusAsyncClientWrapper>(modbus_div_client_wrapper,
                                                                                0, holding_regs_count,
                                                                                0, input_regs_count);

  return modbus_async_client_wrapper;
}

std::shared_ptr<ModbusWrapper> ModbusWrapperFactoryImpl1::createBaseModbusWrapper(const std::string &ip, int port) {
  return std::shared_ptr<ModbusWrapper>();
}
