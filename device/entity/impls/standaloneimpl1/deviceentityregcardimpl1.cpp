#include "deviceentityregcardimpl1.h"

#include <utils/modbusutils.h>

#include "device/entity/consts.h"


static const int SFP_TEMP_REG_NUM = 5;
static const int SFP_TX_VOLTAGE_REG_NUM = 6;
static const int SFP_TX_AMPERAGE_REG_NUM = 7;
static const int SFP_TX_POWER_REG_NUM = 8;
static const int SFP_RX_POWER_REG_NUM = 9;

static const int RX_LOSS_REG_NUM = 3;
static const int TX_FAULT_REG_NUM = 4;

static const int SYNC_BIT_NUM = 0;
static const int RF_BIT_NUM = 1;

static const int LOCK_MANAGEMENT_REG_NUM = 10;
static const int DES_LOCK_BIT_NUM = 0;
static const int OSC_LOCK_BIT_NUM = 1;

static const int INNER_START_PERIOD_FIRST_REG_NUM = 2;
static const int INNER_START_WIDTH_FIRST_REG_NUM = 4;
static const int INNER_START_MANAGEMENT_REG_NUM = 6;
static const int INNER_START_ENABLED_BIT_NUM = 0;
static const int INNER_START_INVERTED_BIT_NUM = 1;

static const std::vector<int> CHANNEL_DELAY_FIRST_REG_NUMS = {
    10, 15, 20, 25, 30, 35, 40, 45
};

static const std::vector<int> CHANNEL_WIDTH_FIRST_REG_NUMS = {
    12, 17, 22, 27, 32, 37, 42, 47
};

static const std::vector<int> CHANNEL_MANAGEMENT_REG_NUMS = {
    14, 19, 24, 29, 34, 39, 44, 49
};

static const int CHANNEL_ENABLED_BIT_NUM = 0;
static const int CHANNEL_INVERTED_BIT_NUM = 1;
static const int CHANNEL_START_SOURCE_FIRST_BIT_NUM = 2;
static const int CHANNEL_START_SOURCE_BITS_COUNT = 5;
static const int CHANNEL_START_MODE_BIT_NUM = 7;


DeviceEntityRegCardImpl1::DeviceEntityRegCardImpl1(std::shared_ptr<ModbusWrapper> modbus_wrapper,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &inner_start_period_converter,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &inner_start_width_converter,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &channel_delay_converter,
                                                   const std::shared_ptr<DiscreteValueConverter<uint64_t>> &channel_width_converter) :
    _modbus_wrapper(modbus_wrapper),
    _inner_start_period_converter(inner_start_period_converter),
    _inner_start_width_converter(inner_start_width_converter),
    _channel_delay_converter(channel_delay_converter),
    _channel_width_converter(channel_width_converter) {

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

int DeviceEntityRegCardImpl1::getChannelCount() {
  return CHANNEL_COUNT;
}

GetSyncModuleStatusesResponse DeviceEntityRegCardImpl1::getSyncModuleStatuses(GetSyncModuleStatusesRequest request) {
  GetSyncModuleStatusesResponse response{};

  if (_modbus_wrapper != nullptr) {
    uint16_t rx_loss_reg_value;
    uint16_t tx_fault_reg_value;
    uint16_t pll_statuses_reg_value;

    auto error_code = _modbus_wrapper->readInputRegister(RX_LOSS_REG_NUM, rx_loss_reg_value);
    error_code = _modbus_wrapper->readInputRegister(TX_FAULT_REG_NUM, tx_fault_reg_value);
    error_code = _modbus_wrapper->readInputRegister(LOCK_MANAGEMENT_REG_NUM, pll_statuses_reg_value);

    bool rx_loss = modbus::readByteValue(SYNC_BIT_NUM, 1, rx_loss_reg_value);
    bool tx_fault = modbus::readByteValue(SYNC_BIT_NUM, 1, tx_fault_reg_value);
    bool des_lock = modbus::readByteValue(DES_LOCK_BIT_NUM, 1, pll_statuses_reg_value);
    bool osc_lock = modbus::readByteValue(OSC_LOCK_BIT_NUM, 1, pll_statuses_reg_value);

    response.rx_loss = rx_loss;
    response.tx_fault = tx_fault;
    response.des_lock = des_lock;
    response.osc_lock = osc_lock;


    response.error_code = SUCCESS;
  }

  return response;
}

GetSFPParametersResponse DeviceEntityRegCardImpl1::getSFPParameters(GetSFPParametersRequest request) {
  GetSFPParametersResponse response{};

  if (_modbus_wrapper != nullptr) {
    SFPParameters sfp_params;

    uint16_t temp_value;
    uint16_t tx_voltage_value;
    uint16_t tx_amperage_value;
    uint16_t tx_power_value;
    uint16_t rx_power_value;

    _modbus_wrapper->readInputRegister(SFP_TEMP_REG_NUM, temp_value);
    _modbus_wrapper->readInputRegister(SFP_TX_VOLTAGE_REG_NUM, tx_voltage_value);
    _modbus_wrapper->readInputRegister(SFP_TX_AMPERAGE_REG_NUM, tx_amperage_value);
    _modbus_wrapper->readInputRegister(SFP_TX_POWER_REG_NUM, tx_power_value);
    _modbus_wrapper->readInputRegister(SFP_RX_POWER_REG_NUM, rx_power_value);

    auto temperature = temp_value / 256.;
    if (temperature >= 128) temperature += 128;

    auto voltage = tx_voltage_value * 0.1;
    auto amperage = tx_amperage_value * 2;
    auto optical_power = tx_power_value * 0.1;
    auto rx_power = rx_power_value * 0.1;

    sfp_params.temperature = temperature;
    sfp_params.voltage = voltage;
    sfp_params.tx_amperage_shift = amperage;
    sfp_params.tx_optical_power = optical_power;
    sfp_params.rx_power = rx_power;

    response.result = sfp_params;
    response.error_code = SUCCESS;
  }

  return response;
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


GetInnerStartWidthResponse DeviceEntityRegCardImpl1::getInnerStartWidth(GetInnerStartWidthRequest request) {
  GetInnerStartWidthResponse response{};

  if (_modbus_wrapper != nullptr) {
    std::vector<uint16_t> values(2);
    auto modbus_wrapper_error = _modbus_wrapper->readHoldingRegisters(INNER_START_WIDTH_FIRST_REG_NUM, 2, values);
    if (modbus_wrapper_error != SUCCESS) {
      response.error_code = modbus_wrapper_error;
      return response;
    }

    uint32_t value;
    modbus::fromMsbLsb(values[0], values[1], value);

    if (_inner_start_width_converter != nullptr) {
      auto result = _inner_start_width_converter->toValue(value);
      response.result = result;
      response.error_code = SUCCESS;
    } else {
      std::cerr << "Value converter is nullptr " << __func__ << std::endl;
    }
  }

  return response;
}

GetInnerStartEnabledStatusResponse DeviceEntityRegCardImpl1::getInnerStartEnabledStatus(
    GetInnerStartEnabledStatusRequest request) {
  GetInnerStartEnabledStatusResponse response{};

  if (_modbus_wrapper != nullptr) {
    uint16_t value;
    _modbus_wrapper->readHoldingRegister(INNER_START_MANAGEMENT_REG_NUM, value);

    bool enabled = modbus::readByteValue(INNER_START_ENABLED_BIT_NUM, 1, value);
    response.result = enabled;
    response.error_code = SUCCESS;
  }

  return response;
}

GetInnerStartInvertedStatusResponse DeviceEntityRegCardImpl1::getInnerStartInvertedStatus(
    GetInnerStartInvertedStatusRequest request) {
  GetInnerStartInvertedStatusResponse response{};

  if (_modbus_wrapper != nullptr) {
    uint16_t value;
    _modbus_wrapper->readHoldingRegister(INNER_START_MANAGEMENT_REG_NUM, value);

    bool inverted = modbus::readByteValue(INNER_START_INVERTED_BIT_NUM, 1, value);
    response.result = inverted;
    response.error_code = SUCCESS;
  }

  return response;
}

GetChannelDelayResponse DeviceEntityRegCardImpl1::getChannelsDelay(GetChannelDelayRequest request) {
  GetChannelDelayResponse response{};

  auto channel_num = request.channel_num;
  bool cached = request.cached;

  if (channel_num >= CHANNEL_COUNT) {
    response.error_code = INVALID_REQUEST;
    return response;
  }

  if (_modbus_wrapper != nullptr) {
    int reg_num = CHANNEL_DELAY_FIRST_REG_NUMS[channel_num];

    std::vector<uint16_t> values(2);
    _modbus_wrapper->readHoldingRegisters(reg_num, 2, values);

    uint32_t value;
    modbus::fromMsbLsb(values[0], values[1], value);

    if (_channel_delay_converter != nullptr) {
      auto result = _channel_delay_converter->toValue(value);
      response.result = result;
      response.error_code = SUCCESS;
    } else {
      std::cerr << "Value converter is nullptr " << __func__ << std::endl;
    }

  }

  return response;
}

GetChannelWidthResponse DeviceEntityRegCardImpl1::getChannelsWidth(GetChannelWidthRequest request) {
  GetChannelWidthResponse response{};

  auto channel_num = request.channel_num;
  bool cached = request.cached;

  if (channel_num >= CHANNEL_COUNT) {
    response.error_code = INVALID_REQUEST;
    return response;
  }

  if (_modbus_wrapper != nullptr) {
    int reg_num = CHANNEL_WIDTH_FIRST_REG_NUMS[channel_num];

    std::vector<uint16_t> values(2);
    _modbus_wrapper->readHoldingRegisters(reg_num, 2, values);

    uint32_t value;
    modbus::fromMsbLsb(values[0], values[1], value);

    if (_channel_width_converter != nullptr) {
      auto result = _channel_width_converter->toValue(value);
      response.result = result;
      response.error_code = SUCCESS;
    } else {
      std::cerr << "Value converter is nullptr " << __func__ << std::endl;
    }

  }

  return response;
}

GetChannelEnabledStatusResponse DeviceEntityRegCardImpl1::getChannelsEnabledStatus(GetChannelEnabledStatusRequest request) {
  GetChannelEnabledStatusResponse response{};

  int channel_num = request.channel_num;

  if (channel_num < 0 || channel_num >= CHANNEL_COUNT) {
    response.error_code = INVALID_REQUEST;
    return response;
  }

  if (_modbus_wrapper != nullptr) {
    uint16_t value;

    if (channel_num >= CHANNEL_MANAGEMENT_REG_NUMS.size()) {
      response.error_code = INVALID_REQUEST;
      return response;
    }

    _modbus_wrapper->readHoldingRegister(CHANNEL_MANAGEMENT_REG_NUMS[channel_num], value);

    bool enabled = modbus::readByteValue(CHANNEL_ENABLED_BIT_NUM, 1, value);
    response.result = enabled;
    response.error_code = SUCCESS;
  }

  return response;
}

GetChannelInvertedStatusResponse DeviceEntityRegCardImpl1::getChannelsInvertedStatus(GetChannelInvertedStatusRequest request) {
  GetChannelInvertedStatusResponse response{};

  int channel_num = request.channel_num;

  if (channel_num < 0 || channel_num >= CHANNEL_COUNT) {
    response.error_code = INVALID_REQUEST;
    return response;
  }

  if (_modbus_wrapper != nullptr) {
    uint16_t value;

    if (channel_num >= CHANNEL_MANAGEMENT_REG_NUMS.size()) {
      response.error_code = INVALID_REQUEST;
      return response;
    }

    _modbus_wrapper->readHoldingRegister(CHANNEL_MANAGEMENT_REG_NUMS[channel_num], value);

    bool enabled = modbus::readByteValue(CHANNEL_INVERTED_BIT_NUM, 1, value);
    response.result = enabled;
    response.error_code = SUCCESS;
  }

  return response;
}

GetChannelStartModeResponse DeviceEntityRegCardImpl1::getChannelsStartMode(GetChannelStartModeRequest request) {
  GetChannelStartModeResponse response{};

  int channel_num = request.channel_num;

  if (channel_num < 0 || channel_num >= CHANNEL_COUNT) {
    response.error_code = INVALID_REQUEST;
    return response;
  }

  if (_modbus_wrapper != nullptr) {
    uint16_t value;

    if (channel_num >= CHANNEL_MANAGEMENT_REG_NUMS.size()) {
      response.error_code = INVALID_REQUEST;
      return response;
    }

    _modbus_wrapper->readHoldingRegister(CHANNEL_MANAGEMENT_REG_NUMS[channel_num], value);

    int start_mode_value = modbus::readByteValue(CHANNEL_START_MODE_BIT_NUM, 1, value);
    ChannelMode start_mode = static_cast<ChannelMode>(start_mode_value);
    response.result = start_mode;
    response.error_code = SUCCESS;
  }

  return response;
}

GetChannelStartSourceResponse DeviceEntityRegCardImpl1::getChannelsStartSource(GetChannelStartSourceRequest request) {
  GetChannelStartSourceResponse response{};

  int channel_num = request.channel_num;

  if (channel_num < 0 || channel_num >= CHANNEL_COUNT) {
    response.error_code = INVALID_REQUEST;
    return response;
  }

  if (_modbus_wrapper != nullptr) {
    uint16_t value;

    if (channel_num >= CHANNEL_MANAGEMENT_REG_NUMS.size()) {
      response.error_code = INVALID_REQUEST;
      return response;
    }

    _modbus_wrapper->readHoldingRegister(CHANNEL_MANAGEMENT_REG_NUMS[channel_num], value);

    int start_source = modbus::readByteValue(CHANNEL_START_SOURCE_FIRST_BIT_NUM, 5, value);
    response.result = start_source;
    response.error_code = SUCCESS;
  }

  return response;
}

SetInnerStartPeriodResponse DeviceEntityRegCardImpl1::setInnerStartPeriod(SetInnerStartPeriodRequest request) {
  SetInnerStartPeriodResponse response{};

  uint64_t value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (_inner_start_period_converter != nullptr) {
      uint32_t discrete_value = _inner_start_period_converter->toDiscretes(value);

      std::vector<uint16_t> values_to_write(2);
      modbus::toMsbLsb(discrete_value, values_to_write[0], values_to_write[1]);

      auto error_code = _modbus_wrapper->writeHoldingRegisters(INNER_START_PERIOD_FIRST_REG_NUM, values_to_write);
      response.error_code = error_code;

      if (error_code == SUCCESS) {
        response.value = value;
      }
    }
  }

  return response;
}

SetInnerStartWidthResponse DeviceEntityRegCardImpl1::setInnerStartWidth(SetInnerStartWidthRequest request) {
  SetInnerStartWidthResponse response{};

  uint64_t value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (_inner_start_width_converter != nullptr) {
      uint32_t discrete_value = _inner_start_width_converter->toDiscretes(value);

      std::vector<uint16_t> values_to_write(2);
      modbus::toMsbLsb(discrete_value, values_to_write[0], values_to_write[1]);

      auto error_code = _modbus_wrapper->writeHoldingRegisters(INNER_START_WIDTH_FIRST_REG_NUM, values_to_write);
      response.error_code = error_code;

      if (error_code == SUCCESS) {
        response.value = value;
      }
    }
  }

  return response;
}

SetInnerStartEnabledStatusResponse DeviceEntityRegCardImpl1::setInnerStartEnabledStatus(
    SetInnerStartEnabledStatusRequest request) {
  SetInnerStartEnabledStatusResponse response{};

  bool value = request.value;

  if (_modbus_wrapper != nullptr) {
    uint16_t value_in_reg;
    uint16_t value_value = value ? 1: 0;

    auto error_code = _modbus_wrapper->readHoldingRegister(INNER_START_MANAGEMENT_REG_NUM, value_in_reg);
    response.error_code = error_code;
    if (error_code == SUCCESS) {

      uint16_t value_to_write;
      modbus::writeByteValue(INNER_START_ENABLED_BIT_NUM, 1, value_value, value_to_write);

      error_code = _modbus_wrapper->writeHoldingRegister(INNER_START_MANAGEMENT_REG_NUM, value_to_write);
      response.error_code = error_code;

      if (error_code == SUCCESS) {
        response.value = value;
      }
    }
  }

  return response;
}

SetInnerStartInvertedStatusResponse DeviceEntityRegCardImpl1::setInnerStartInvertedStatus(
    SetInnerStartInvertedStatusRequest request) {
  SetInnerStartInvertedStatusResponse response{};

  bool value = request.value;

  if (_modbus_wrapper != nullptr) {
    uint16_t value_in_reg;
    uint16_t value_value = value ? 1: 0;

    auto error_code = _modbus_wrapper->readHoldingRegister(INNER_START_MANAGEMENT_REG_NUM, value_in_reg);
    response.error_code = error_code;
    if (error_code == SUCCESS) {

      uint16_t value_to_write;
      modbus::writeByteValue(INNER_START_INVERTED_BIT_NUM, 1, value_value, value_to_write);

      error_code = _modbus_wrapper->writeHoldingRegister(INNER_START_MANAGEMENT_REG_NUM, value_to_write);
      response.error_code = error_code;

      if (error_code == SUCCESS) {
        response.value = value;
      }
    }
  }

  return response;
}

SetChannelDelayResponse DeviceEntityRegCardImpl1::setChannelDelay(SetChannelDelayRequest request) {
  SetChannelDelayResponse response{};

  int channel_num = request.channel_num;
  uint64_t value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (channel_num >= 0 && channel_num < CHANNEL_COUNT) {
      if (_channel_delay_converter != nullptr) {
        uint16_t reg_num = CHANNEL_DELAY_FIRST_REG_NUMS[channel_num];

        uint32_t discrete_value = _channel_delay_converter->toDiscretes(value);

        std::vector<uint16_t> values_to_write(2);
        modbus::toMsbLsb(discrete_value, values_to_write[0], values_to_write[1]);

        auto error_code = _modbus_wrapper->writeHoldingRegisters(reg_num, values_to_write);
        response.error_code = error_code;

        if (error_code == SUCCESS) {
          response.value = value;
        }
      }
    }
  }

  return response;
}

SetChannelWidthResponse DeviceEntityRegCardImpl1::setChannelWidth(SetChannelWidthRequest request) {
  SetChannelWidthResponse response{};

  int channel_num = request.channel_num;
  uint64_t value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (channel_num >= 0 && channel_num < CHANNEL_COUNT) {
      if (_channel_width_converter != nullptr) {
        uint16_t reg_num = CHANNEL_WIDTH_FIRST_REG_NUMS[channel_num];

        uint32_t discrete_value = _channel_width_converter->toDiscretes(value);

        std::vector<uint16_t> values_to_write(2);
        modbus::toMsbLsb(discrete_value, values_to_write[0], values_to_write[1]);

        auto error_code = _modbus_wrapper->writeHoldingRegisters(reg_num, values_to_write);
        response.error_code = error_code;

        if (error_code == SUCCESS) {
          response.value = value;
        }
      }
    }
  }

  return response;
}

SetChannelEnabledStatusResponse DeviceEntityRegCardImpl1::setChannelEnabledStatus(SetChannelEnabledStatusRequest request) {
  SetChannelEnabledStatusResponse response{};

  int channel_num = request.channel_num;
  bool value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (channel_num >= 0 && channel_num < CHANNEL_COUNT) {
      int reg_num = CHANNEL_MANAGEMENT_REG_NUMS[channel_num];

      uint16_t reg_value;
      auto error_code = _modbus_wrapper->readHoldingRegister(reg_num, reg_value);

      response.error_code = error_code;

      if (error_code == SUCCESS) {
        uint16_t value_to_write = value ? 1 : 0;
        modbus::writeByteValue(CHANNEL_ENABLED_BIT_NUM, 1, value_to_write, reg_value);
        error_code = _modbus_wrapper->writeHoldingRegister(reg_num, reg_value);
        response.error_code = error_code;
        if (error_code == SUCCESS) {
          response.value = value;
        }
      }
    }
  }

  return response;
}

SetChannelInvertedStatusResponse DeviceEntityRegCardImpl1::setChannelInvertedStatus(SetChannelInvertedStatusRequest request) {
  SetChannelInvertedStatusResponse response{};

  int channel_num = request.channel_num;
  bool value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (channel_num >= 0 && channel_num < CHANNEL_COUNT) {
      int reg_num = CHANNEL_MANAGEMENT_REG_NUMS[channel_num];

      uint16_t reg_value;
      auto error_code = _modbus_wrapper->readHoldingRegister(reg_num, reg_value);

      response.error_code = error_code;
      if (error_code == SUCCESS) {
        uint16_t value_to_write = value ? 1 : 0;
        modbus::writeByteValue(CHANNEL_INVERTED_BIT_NUM, 1, value_to_write, reg_value);
        error_code = _modbus_wrapper->writeHoldingRegister(reg_num, reg_value);
        response.error_code = error_code;
        if (error_code == SUCCESS) {
          response.value = value;
        }
      }
    }
  }

  return response;
}

SetChannelStartSourceResponse DeviceEntityRegCardImpl1::setChannelStartSource(SetChannelStartSourceRequest request) {
  SetChannelStartSourceResponse response{};

  int channel_num = request.channel_num;
  uint16_t value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (channel_num >= 0 && channel_num < CHANNEL_COUNT) {
      int reg_num = CHANNEL_MANAGEMENT_REG_NUMS[channel_num];

      uint16_t reg_value;
      auto error_code = _modbus_wrapper->readHoldingRegister(reg_num, reg_value);
      response.error_code = error_code;
      if (error_code == SUCCESS) {
        modbus::writeByteValue(CHANNEL_START_SOURCE_FIRST_BIT_NUM, CHANNEL_START_SOURCE_BITS_COUNT, value, reg_value);
        error_code = _modbus_wrapper->writeHoldingRegister(reg_num, reg_value);
        response.error_code = error_code;
        if (error_code == SUCCESS) {
          response.value = value;
        }
      }
    }
  }

  return response;
}

SetChannelStartModeResponse DeviceEntityRegCardImpl1::setChannelStartMode(SetChannelStartModeRequest request) {
  SetChannelStartModeResponse response{};

  int channel_num = request.channel_num;
  uint16_t value = request.value;

  if (_modbus_wrapper != nullptr) {
    if (channel_num >= 0 && channel_num < CHANNEL_COUNT) {
      int reg_num = CHANNEL_MANAGEMENT_REG_NUMS[channel_num];

      uint16_t reg_value;
      auto error_code = _modbus_wrapper->readHoldingRegister(reg_num, reg_value);
      response.error_code = error_code;
      if (error_code == SUCCESS) {
        modbus::writeByteValue(CHANNEL_START_MODE_BIT_NUM, 1, value, reg_value);
        error_code = _modbus_wrapper->writeHoldingRegister(reg_num, reg_value);
        response.error_code = error_code;
        if (error_code == SUCCESS) {
          response.value = static_cast<ChannelMode>(value);
        }
      }
    }
  }

  return response;
}

ErrorCode DeviceEntityRegCardImpl1::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  ErrorCode result = OPERATION_INTERRUPTED;

  return result;
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityRegCardImpl1::updateDeviceDTO() {
  return DeviceEntityState::updateDeviceDTO();
}
