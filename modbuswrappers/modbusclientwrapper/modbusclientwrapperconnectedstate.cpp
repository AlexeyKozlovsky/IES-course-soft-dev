#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperconnectedstate.h"

#include <utils/enumconverter.h>


ModbusClientWrapperConnectedState::ModbusClientWrapperConnectedState(const std::shared_ptr<ModbusClientWrapper> &state_machine,
                                                                     const std::shared_ptr<ModbusClient> &modbus_client,
                                                                     const std::shared_ptr<std::mutex> &modbus_client_mutex):
                                                                     _state_machine(state_machine),
                                                                     _modbus_client(modbus_client),
                                                                     _modbus_client_mutex(modbus_client_mutex) {

}

ErrorCode ModbusClientWrapperConnectedState::connect() {
  auto result = OPERATION_INTERRUPTED;
//  if (_modbus_client != nullptr) {
//    bool modbus_result = _modbus_client->connect();
//    if (modbus_result) {
//      result = SUCCESS;
//    } else {
//      result = ErrorCode::DEVICE_NOT_RESPONDING_LAN;
//    }
//  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::disconnect() {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    _modbus_client->disconnect();
    result = SUCCESS;

    if (_state_machine != nullptr) {
      _state_machine->changeState(DISCONNECTED);
    }
  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::isConnected(bool &is_connected) {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    // TODO: Пересобрать библиотеку modbus client с тем, чтобы можно было коннект проверять в соответствие с modbus id
    if (_modbus_client_mutex != nullptr) {
      _modbus_client_mutex->lock();
      is_connected = _modbus_client->isConnected();
      _modbus_client_mutex->unlock();

      if (_state_machine != nullptr) {
        if (is_connected) {
          _state_machine->changeState(CONNECTED);
        } else {
          _state_machine->changeState(DISCONNECTED);
        }
      }

      result = SUCCESS;
    }

  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    _modbus_client_mutex->lock();
    auto modbus_result = _modbus_client->readHoldingRegister(reg_num, value, modbus_id);
    result = toErrorCode(modbus_result);
    _modbus_client_mutex->unlock();
    checkConnectionStatusByResponse(modbus_result);
  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::readHoldingRegisters(int reg_num,
                                                    int reg_count,
                                                    std::vector<uint16_t> &values,
                                                    int modbus_id) {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    _modbus_client_mutex->lock();
    auto modbus_result = _modbus_client->readHoldingRegisters(reg_num, reg_count, values, modbus_id);
    result = toErrorCode(modbus_result);
    _modbus_client_mutex->unlock();
    checkConnectionStatusByResponse(modbus_result);
  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    _modbus_client_mutex->lock();
    auto modbus_result = _modbus_client->writeHoldingRegister(reg_num, value, modbus_id);
    result = toErrorCode(modbus_result);
    _modbus_client_mutex->unlock();
    checkConnectionStatusByResponse(modbus_result);
  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    _modbus_client_mutex->lock();
    auto modbus_result = _modbus_client->writeHoldingRegisters(reg_num, value, modbus_id);
    result = toErrorCode(modbus_result);
    _modbus_client_mutex->unlock();
    checkConnectionStatusByResponse(modbus_result);
  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::readInputRegister(int reg_num, uint16_t &value, int modbus_id) {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    _modbus_client_mutex->lock();
    auto modbus_result = _modbus_client->readInputRegister(reg_num, value, modbus_id);
    result = toErrorCode(modbus_result);
    _modbus_client_mutex->unlock();
    checkConnectionStatusByResponse(modbus_result);
  }

  return result;
}

ErrorCode ModbusClientWrapperConnectedState::readInputRegisters(int reg_num,
                                                  int reg_count,
                                                  std::vector<uint16_t> &values,
                                                  int modbus_id) {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_client != nullptr) {
    _modbus_client_mutex->lock();
    auto modbus_result = _modbus_client->readInputRegisters(reg_num, reg_count, values, modbus_id);
    result = toErrorCode(modbus_result);
    _modbus_client_mutex->unlock();

    checkConnectionStatusByResponse(modbus_result);
  }

  return result;
}

void ModbusClientWrapperConnectedState::checkConnectionStatusByResponse(modbus::ModbusResult result) {
  if (_state_machine != nullptr) {
    _state_machine->checkConnectionStatusByResponse(result);
  }
}
