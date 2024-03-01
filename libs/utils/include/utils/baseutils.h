#ifndef UTILSD_UTILS_BASEUTILS_H_
#define UTILSD_UTILS_BASEUTILS_H_

#include <variant>
#include <string>
#include <vector>

#define SCALAR_VARIANT__D \
std::variant<bool, uint8_t, int8_t, uint16_t, int16_t, uint32_t, int32_t, \
uint64_t, int64_t, float, double, std::string, char>

#define VARIANT__D \
std::variant<SCALAR_VARIANT__D, std::vector<SCALAR_VARIANT__D>>

// TODO: Пройтись по библиотеки и прописать все взаимодействия с кодом ошибки через макросы

#define IS_ERROR__D(error_code, instruction) if (error_code != nullptr && *error_code != ErrorCode::SUCCESS) { \
  std::cerr << "Error: " << *error_code << " " << __func__ << std::endl; \
  instruction;         \
}

#define IS_NOT_ERROR(error_code, instruction) if (error_code != nullptr && *error_code == ErrorCode::SUCCESS) { \
  instruction;                                                                                                            \
} else std::cerr << "Error: " << *error_code << " " << __func__ << std::endl;

#define SET_ERROR_CODE(error_code, error_code_value) if (error_code != nullptr) { \
  *error_code = error_code_value;                                                                                  \
}

#define SET_ERROR_CODE_SUCCESS(error_code) SET_ERROR_CODE(error_code, ErrorCode::SUCCESS);

enum DeviceState {
  CONNECTED,
  NOT_CONNECTED,
  DISCONNECTED,
  READ_ONLY,
  OPEN,
  CLOSE,
  INVALID,
  EMPTY
};

enum ErrorCode {
  SUCCESS = 0,
  MODBUS_ILLEGAL_FUNCTION = 1,
  MODBUS_ILLEGAL_DATA_ADDRESS = 2,
  MODBUS_ILLEGAL_DATA_VALUE = 3,
  MODBUS_SERVER_DEVICE_FAILURE = 4,
  MODBUS_ACKNOWLEDGE = 5,
  MODBUS_SERVER_DEVICE_BUSY = 6,
  MODBUS_NEGATIVE_ACKNOWLEDGE = 7,
  MODBUS_MEMORY_PARITY_ERROR = 8,
  MODBUS_GATEWAY_PATH_UNAVAILABLE = 10,
  MODBUS_GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND = 11,
  DEVICE_DOESNT_EXIST = 128,
  DEVICE_NOT_RESPONDING_TANGO = 129,
  DEVICE_TYPE_ERROR = 130,
  DEVICE_NOT_RESPONDING_LAN = 131,
  INVALID_RESPONSE = 252,
  INVALID_REQUEST = 251,
  CRC_ERROR = 250,
  OPERATION_INTERRUPTED = 255,

  DEVICE_DOESNT_HAVE_ATTRIBUTE = 132,
  DEVICE_ALREADY_EXISTS = 133,
  PROPERTY_OR_COMMAND_ALREADY_EXISTS = 134,
  UNABLE_TO_START_SERVER = 135,
  UNABLE_TO_STOP_SERVER = 136,
  DEVICE_NOT_INITIALIZED = 137,
  DEVICE_IS_READONLY_MODE = 138
};

#endif //UTILSD_UTILS_BASEUTILS_H_
