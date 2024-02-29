#include "modbuswrappers/modbusclientwrapper/modbusclientdividablewrapperfactory.h"

#include <memory>
#include <mutex>
#include <utils/services/domain/regreaddivider.h>

#include "modbuswrappers/modbusclientwrapper/modbusclientwrapper.h"
#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperconnectedstate.h"
#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperdisconnectedstate.h"
#include "modbuswrappers/modbusclientwrapper/modbusclientdividablewrapper.h"

using modbus::ModbusClient;


static const int DEFAULT_HOLDING_START_REG = 0;
static const int DEFAULT_HOLDING_REGS_PER_REQUEST = 30;

static const int DEFAULT_INPUT_START_REG = 0;
static const int DEFAULT_INPUT_REGS_PER_REQUEST = 30;

ModbusClientDividableWrapperFactory::ModbusClientDividableWrapperFactory(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory):
 _modbus_wrapper_factory(modbus_wrapper_factory),
 _holding_start_reg(DEFAULT_HOLDING_START_REG),
 _holding_regs_per_request(DEFAULT_HOLDING_REGS_PER_REQUEST),
 _input_start_reg(DEFAULT_INPUT_START_REG),
 _input_regs_per_request(DEFAULT_INPUT_REGS_PER_REQUEST) {

}

ModbusClientDividableWrapperFactory::ModbusClientDividableWrapperFactory(const std::shared_ptr<ModbusWrapperFactory> &modbus_wrapper_factory,
                                                                         int holding_start_reg,
                                                                         int holding_regs_per_request,
                                                                         int input_start_reg,
                                                                         int input_regs_per_request):
                                                                         _modbus_wrapper_factory(modbus_wrapper_factory),
                                                                         _holding_start_reg(holding_start_reg),
                                                                         _holding_regs_per_request(holding_regs_per_request),
                                                                         _input_start_reg(input_start_reg),
                                                                         _input_regs_per_request(input_regs_per_request) {

}

std::shared_ptr<ModbusWrapper> ModbusClientDividableWrapperFactory::createModbusWrapper(const std::string &ip,
                                                                               int port,
                                                                               int modbus_id,
                                                                               int holding_regs_count,
                                                                               int input_regs_count) {
  std::shared_ptr<ModbusWrapper> result = nullptr;

  auto holding_reg_req_divider = std::make_shared<RegReadDivider>(_holding_start_reg,
                                                                  holding_regs_count,
                                                                  _holding_regs_per_request);
  auto input_reg_req_divider = std::make_shared<RegReadDivider>(_input_start_reg,
                                                                input_regs_count,
                                                                _input_regs_per_request);

  if (_modbus_wrapper_factory != nullptr) {
    auto base_modbus_wrapper = _modbus_wrapper_factory->createModbusWrapper(ip, port, modbus_id, holding_regs_count, input_regs_count);
    if (base_modbus_wrapper != nullptr) {
      result = std::make_shared<ModbusClientDividableWrapper>(base_modbus_wrapper,
                                                              holding_reg_req_divider,
                                                              input_reg_req_divider);
    }
  }

  return result;
}

std::shared_ptr<ModbusWrapper> ModbusClientDividableWrapperFactory::createBaseModbusWrapper(const std::string &ip, int port) {
  std::cerr << "MODBUS WRAPPER BASE BE CREATED VIA THIS FACTORY " << __func__ << std::endl;
  return nullptr;
}
