#ifndef UTILSD_UTILS_DEVICEUTILS_H_
#define UTILSD_UTILS_DEVICEUTILS_H_


#define REQUEST_PREPROCESS(request_handling, return_value, error_code) try {request_handling} \
catch (...) {                                                                   \
  SET_ERROR_CODE(error_code, ErrorCode::INVALID_REQUEST)                      \
  return return_value;\
}

#define CREATE_DEVICE_ADD_PROPERTY(property, device, error_code) device->addProperty(property, error_code); \
IS_ERROR__D(                                                                                                    \
  error_code,                                                                                                \
  return nullptr; \
);

#define CREATE_DEVICE_ADD_COMMAND(command, device, error_code) device->addCommand(command, error_code);\
IS_ERROR__D(                                                                                               \
  error_code,                                                                                           \
  return nullptr; \
);

#define CHECK_DEVICE_INIT(error_code, device, return_value) if (!device->inited) { \
  SET_ERROR_CODE(error_code, ErrorCode::DEVICE_NOT_INITIALIZED);     \
  return return_value; \
}

#define MODBUS_RW_DEVICE_ERROR_HANDLE(condition, positive_instruction, negative_instruction, error_code) {modbus::ModbusResult error_status; \
MODBUS_RW_ERROR_HANDLE( \
    condition, \
    SET_ERROR_CODE_SUCCESS(error_code)                                                                                                                                        \
    positive_instruction;, \
        if (error_status == modbus::NO_SOCKET_CONNECTION || error_status == modbus::TCP_TIMEOUT_ERROR) \
          device->changeState(DeviceState::CLOSE);     \
        negative_instruction;, \
    error_status \
) SET_ERROR_CODE(error_code, device::toErrorCode(error_status));}


#endif //UTILSD_UTILS_DEVICEUTILS_H_
