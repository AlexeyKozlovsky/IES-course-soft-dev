#include "modbuswrappers/modbusclientwrapper/modbusclientwrapperdisconnectedstate.h"

ModbusClientWrapperDisconnectedState::ModbusClientWrapperDisconnectedState(const std::shared_ptr<ModbusClientWrapper> &state_machine,
                                                                           const std::shared_ptr<ModbusClient> &modbus_client,
                                                                           const std::shared_ptr<std::mutex> &modbus_client_mutex):
                                                                           _state_machine(state_machine),
                                                                           _modbus_client(modbus_client),
                                                                           _modbus_client_mutex(modbus_client_mutex) {

}

ErrorCode ModbusClientWrapperDisconnectedState::connect() {
  ErrorCode result = OPERATION_INTERRUPTED;
  if (_modbus_client_mutex != nullptr) {
    _modbus_client_mutex->lock();

    if (_modbus_client != nullptr) {
      bool connected = _modbus_client->connect();
      if (connected) {
        result = SUCCESS;
        if (_state_machine != nullptr) {
          _state_machine->changeState(CONNECTED);
        }
      }
    }

    _modbus_client_mutex->unlock();
  }
  return result;
}

ErrorCode ModbusClientWrapperDisconnectedState::disconnect() {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}

ErrorCode ModbusClientWrapperDisconnectedState::isConnected(bool &is_connected) {
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

ErrorCode ModbusClientWrapperDisconnectedState::readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}

ErrorCode ModbusClientWrapperDisconnectedState::readHoldingRegisters(int reg_num,
                                                                     int reg_count,
                                                                     std::vector<uint16_t> &values,
                                                                     int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}

ErrorCode ModbusClientWrapperDisconnectedState::writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}

ErrorCode ModbusClientWrapperDisconnectedState::writeHoldingRegisters(int reg_num,
                                                                      std::vector<uint16_t> value,
                                                                      int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}

ErrorCode ModbusClientWrapperDisconnectedState::readInputRegister(int reg_num, uint16_t &value, int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}

ErrorCode ModbusClientWrapperDisconnectedState::readInputRegisters(int reg_num,
                                                                   int reg_count,
                                                                   std::vector<uint16_t> &values,
                                                                   int modbus_id) {
  ErrorCode result = OPERATION_INTERRUPTED;
  return result;
}
