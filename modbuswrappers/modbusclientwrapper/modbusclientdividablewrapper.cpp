#include "modbuswrappers/modbusclientwrapper/modbusclientdividablewrapper.h"

static const int DEFAULT_INPUT_FIRST_REG_NUM = 0;
static const int DEFAULT_HOLDING_FIRST_REG_NUM = 0;

static const int DEFAULT_INPUT_REG_PER_REQUEST_COUNT = 30;
static const int DEFAULT_HOLDING_REG_PER_REQUEST_COUNT = 30;

// TODO: Добавить потом более правильную обработку ошибок в множественной записи


ModbusClientDividableWrapper::ModbusClientDividableWrapper(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                           int holding_regs_count,
                                                           int input_regs_count):
                                                           _modbus_wrapper(modbus_wrapper),
                                                           _holding_regs_count(holding_regs_count),
                                                           _input_regs_count(input_regs_count) {
  _input_regs_divider = std::make_shared<RegReadDivider>(DEFAULT_INPUT_FIRST_REG_NUM,
                                                         _input_regs_count,
                                                         DEFAULT_INPUT_REG_PER_REQUEST_COUNT);

  _holding_regs_divider = std::make_shared<RegReadDivider>(DEFAULT_HOLDING_FIRST_REG_NUM,
                                                           _holding_regs_count,
                                                           DEFAULT_HOLDING_REG_PER_REQUEST_COUNT);
}
ModbusClientDividableWrapper::ModbusClientDividableWrapper(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                           const std::shared_ptr<RegReadDivider> &holding_regs_divider,
                                                           const std::shared_ptr<RegReadDivider> &input_regs_divider):
                                                           _modbus_wrapper(modbus_wrapper),
                                                           _holding_regs_divider(holding_regs_divider),
                                                           _input_regs_divider(input_regs_divider) {
}

ErrorCode ModbusClientDividableWrapper::connect() {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr) {
    result = _modbus_wrapper->connect();
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::disconnect() {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr) {
    result = _modbus_wrapper->disconnect();
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::isConnected(bool &is_connected) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr) {
    result = _modbus_wrapper->isConnected(is_connected);
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr) {
    result = _modbus_wrapper->readHoldingRegister(reg_num, value, modbus_id);
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::readHoldingRegisters(int reg_num,
                                                             int reg_count,
                                                             std::vector<uint16_t> &values,
                                                             int modbus_id) {

  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr && _holding_regs_divider != nullptr) {
    std::vector<uint16_t> holding_regs(reg_count);
    _holding_regs_divider->setParams(reg_num, reg_count, _holding_regs_per_request);

    auto holding_regs_read_data = _holding_regs_divider->getRegReadData();
    std::vector<uint16_t> current_holding_reg_vector;
    std::for_each(std::begin(holding_regs_read_data), std::end(holding_regs_read_data), [&](const RegReadData &data) {
      current_holding_reg_vector.resize(data.reg_num);
      _modbus_wrapper->readHoldingRegisters(data.reg_num, data.reg_count, current_holding_reg_vector);

      for (int i = 0; i < current_holding_reg_vector.size(); i++) {
        auto holding_reg = data.reg_num + i;
        if (holding_reg < holding_regs.size())
          holding_regs[holding_reg] = current_holding_reg_vector[i];
      }

      std::cout << "REG READ DATA " << data.reg_num << " " << data.reg_count << std::endl;
    });

    values = std::move(holding_regs);
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr) {
    result = _modbus_wrapper->writeHoldingRegister(reg_num, value, modbus_id);
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::writeHoldingRegisters(int reg_num, std::vector<uint16_t> values, int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;

  int reg_count = values.size();

  if (_modbus_wrapper != nullptr && _holding_regs_divider != nullptr) {

    _holding_regs_divider->setParams(reg_num, reg_count, _holding_regs_per_request);
    auto holding_regs_read_data = _holding_regs_divider->getRegReadData();
    std::vector<uint16_t> current_holding_reg_vector;
    std::for_each(std::begin(holding_regs_read_data), std::end(holding_regs_read_data), [&](const RegReadData &data) {
      current_holding_reg_vector.resize(data.reg_num);

      std::cout << reg_num << "" << reg_count << "\t" << data.reg_num << " " << data.reg_count << "\t\tFOR READING\t" << __func__ << std::endl;
//      std::vector<uint16_t> current_vector_to_write;
//      current_vector_to_write.reserve(data.reg_count);
      int start_pos = data.reg_num - reg_num;
      int stop_pos = start_pos + data.reg_count;
//      std::copy(std::begin(values) + start_pos, std::end(values) + stop_pos, std::back_inserter(current_vector_to_write));

      std::vector<uint16_t> current_vector_to_write(std::begin(values) + start_pos, std::begin(values) + stop_pos);
      std::cout << "current vector to write " << current_vector_to_write.size() << std::endl;
      result = _modbus_wrapper->writeHoldingRegisters(data.reg_num, current_vector_to_write);

      std::cout << "REG READ DATA " << data.reg_num << " " << data.reg_count << std::endl;

      if (result != SUCCESS) {
        return result;
      }
    });
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::readInputRegister(int reg_num, uint16_t &value, int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr) {
    result = _modbus_wrapper->readInputRegister(reg_num, value, modbus_id);
  }

  return result;
}

ErrorCode ModbusClientDividableWrapper::readInputRegisters(int reg_num,
                                                           int reg_count,
                                                           std::vector<uint16_t> &values,
                                                           int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (_modbus_wrapper != nullptr && _input_regs_divider != nullptr) {
    std::vector<uint16_t> input_regs(reg_count);
    _input_regs_divider->setParams(reg_num, reg_count, _input_regs_per_request);

    auto input_regs_read_data = _input_regs_divider->getRegReadData();
    std::vector<uint16_t> current_input_reg_vector;
    std::for_each(std::begin(input_regs_read_data), std::end(input_regs_read_data), [&](const RegReadData &data) {
      current_input_reg_vector.resize(data.reg_num);
      result = _modbus_wrapper->readInputRegisters(data.reg_num, data.reg_count, current_input_reg_vector);

      if (result != SUCCESS) {
        return result;
      }

      for (int i = 0; i < current_input_reg_vector.size(); i++) {
        auto input_reg = data.reg_num + i;
        if (input_reg < input_regs.size())
          input_regs[input_reg] = current_input_reg_vector[i];
      }

      std::cout << "REG READ DATA " << data.reg_num << " " << data.reg_count << std::endl;
    });

    values = std::move(input_regs);
  }

  return result;
}

void ModbusClientDividableWrapper::addConnectable(const std::shared_ptr<Connectable> &connectable) {
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->addConnectable(connectable);
  }
}

void ModbusClientDividableWrapper::sendConnectionStatus(bool connection_status) {
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->sendConnectionStatus(connection_status);
  }
}

void ModbusClientDividableWrapper::process() {
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->process();
  }
}
