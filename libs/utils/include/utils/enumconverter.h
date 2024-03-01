#ifndef UTILSD__ENUMCONVERTER_H_
#define UTILSD__ENUMCONVERTER_H_

#include "modbusutils.h"
#include "deviceutils.h"
#include "baseutils.h"

inline ErrorCode toErrorCode(modbus::ModbusResult input_code) {
  switch (input_code) {
    case modbus::NO_MODBUS_ERROR:
      return ErrorCode::SUCCESS;
    case modbus::ILLEGAL_FUNCTION:
      return ErrorCode::MODBUS_ILLEGAL_FUNCTION;
    case modbus::ILLEGAL_DATA_ADDRESS:
      return ErrorCode::MODBUS_ILLEGAL_DATA_ADDRESS;
    case modbus::ILLEGAL_DATA_VALUE:
      return ErrorCode::MODBUS_ILLEGAL_DATA_VALUE;
    case modbus::SERVER_DEVICE_FAILURE:
      return ErrorCode::MODBUS_SERVER_DEVICE_FAILURE;
    case modbus::ACKNOWLEDGE:
      return ErrorCode::MODBUS_ACKNOWLEDGE;
    case modbus::SERVER_DEVICE_BUSY:
      return ErrorCode::MODBUS_SERVER_DEVICE_BUSY;
    case modbus::NEGATIVE_ACKNOWLEDGE:
      return ErrorCode::MODBUS_NEGATIVE_ACKNOWLEDGE;
    case modbus::MEMORY_PARITY_ERROR:
      return ErrorCode::MODBUS_MEMORY_PARITY_ERROR;
    case modbus::GATEWAY_PATH_UNAVAILABLE:
      return ErrorCode::MODBUS_GATEWAY_PATH_UNAVAILABLE;
    case modbus::GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND:
      return ErrorCode::MODBUS_GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND;
    case modbus::UNHANDLED_ERROR:
      return ErrorCode::OPERATION_INTERRUPTED;
    case modbus::NO_SOCKET_CONNECTION:
      return ErrorCode::DEVICE_NOT_RESPONDING_LAN;
    case modbus::TCP_TIMEOUT_ERROR:
      return ErrorCode::DEVICE_NOT_RESPONDING_LAN;
    case modbus::INVALID_RESPONSE:
      return ErrorCode::INVALID_RESPONSE;
    case modbus::INVALID_REQUEST:
      return ErrorCode::INVALID_REQUEST;
    case modbus::CRC_ERROR:
      return ErrorCode::CRC_ERROR;
    default:
      return ErrorCode::OPERATION_INTERRUPTED;
  }
}



#endif //UTILSD__ENUMCONVERTER_H_
