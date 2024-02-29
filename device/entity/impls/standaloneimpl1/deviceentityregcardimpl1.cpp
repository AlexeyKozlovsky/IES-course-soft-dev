#include "deviceentityregcardimpl1.h"

#include <utils/modbusutils.h>

#include "device/entity/consts.h"


static const int INNER_START_PERIOD_FIRST_REG_NUM = 2;


DeviceEntityRegCardImpl1::DeviceEntityRegCardImpl1(std::shared_ptr<ModbusWrapper> modbus_wrapper,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &inner_start_period_converter,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &inner_start_width_converter,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &channel_delay_converter,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &channel_width_converter) :
    _modbus_wrapper(modbus_wrapper),
    _inner_start_period_converter(inner_start_period_converter) {

}

void DeviceEntityRegCardImpl1::setConnectionStatus(bool connection_status) {
  _connection_status = connection_status;
}

bool DeviceEntityRegCardImpl1::getConnectionStatus() {
  return _connection_status;
}

ErrorCode DeviceEntityRegCardImpl1::connect() {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_wrapper != nullptr) {
    bool connection_result = _modbus_wrapper->connect();
    _modbus_wrapper->isConnected(connection_result);
    setConnectionStatus(connection_result);
    if (connection_result) {
      result = SUCCESS;
    }
  }
  return result;
}

ErrorCode DeviceEntityRegCardImpl1::disconnect() {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->disconnect();
    setConnectionStatus(false);
    result = SUCCESS;
  }
  return result;
}

void DeviceEntityRegCardImpl1::updateRegCard() {
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->process();
  }
}

GetInnerStartPeriodResponse DeviceEntityRegCardImpl1::getInnerStartPeriod(GetInnerStartPeriodRequest request) {
  GetInnerStartPeriodResponse response{};

  if (_modbus_wrapper != nullptr) {
    std::vector<uint16_t> values(2);
    auto modbus_wrapper_error = _modbus_wrapper->readHoldingRegisters(INNER_START_PERIOD_FIRST_REG_NUM, 2, values);
    if (modbus_wrapper_error != SUCCESS) {
      response.error_code = modbus_wrapper_error;
      return response;
    }

    uint32_t value;
    modbus::fromMsbLsb(values[0], values[1], value);

    if (_inner_start_period_converter != nullptr) {
      auto result = _inner_start_period_converter->toValue(value);
      response.result = result;
      response.error_code = SUCCESS;
    } else {
      std::cerr << "Value converter is nullptr " << __func__ << std::endl;
    }
  }

  return response;
}
