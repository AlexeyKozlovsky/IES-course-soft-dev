#include <memory>
#include <mutex>


#include "modbuswrappers/modbusclientwrapper/modbusclientwrapper.h"
#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperconnectedstate.h"
#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperdisconnectedstate.h"
#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperfactory.h"

using modbus::ModbusClient;


std::shared_ptr<ModbusWrapper> ModbusClientWrapperFactory::createModbusWrapper(const std::string &ip,
                                                                               int port,
                                                                               int modbus_id,
                                                                               int holding_regs_count,
                                                                               int input_regs_count) {
  std::cerr << "MODBUS WRAPPER WITH MODBUS ID CANNOT BE CREATED VIA THIS FACTORY " << __func__ << std::endl;
  return nullptr;
}

std::shared_ptr<ModbusWrapper> ModbusClientWrapperFactory::createBaseModbusWrapper(const std::string &ip, int port) {
  std::shared_ptr<ModbusWrapper> result = nullptr;
  auto modbus_client = std::make_shared<ModbusClient>(ip, port);
  auto modbus_client_mutex = std::make_shared<std::mutex>();

  auto modbus_wrapper = std::make_shared<ModbusClientWrapper>();
  auto modbus_wrapper_connected_state = std::make_shared<ModbusClientWrapperConnectedState>(modbus_wrapper, modbus_client, modbus_client_mutex);
  auto modbus_wrapper_disconnected_state = std::make_shared<ModbusClientWrapperDisconnectedState>(modbus_wrapper, modbus_client, modbus_client_mutex);

  modbus_wrapper->addState({CONNECTED, modbus_wrapper_connected_state});
  modbus_wrapper->addState({DISCONNECTED, modbus_wrapper_disconnected_state});
  modbus_wrapper->changeState(DISCONNECTED);

  result = modbus_wrapper;

//
//  // TODO: УБРАААААААААААААААть !
//  modbus_client->connect();
//  modbus_wrapper->connect();


//  result = std::make_shared<ModbusClientWrapper>(modbus_client);
  return result;
}
