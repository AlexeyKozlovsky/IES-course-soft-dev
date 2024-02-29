#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICETYPES_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICETYPES_H_

#include <string>

#include <utils/baseutils.h>

#include "device/entity/consts.h"


enum ChannelMode {
  START,
  PROXY
};

struct SFPParameters {
    double temperature;
    double voltage;
    double tx_amperage_shift;
    double tx_optical_power;
    double rx_power;
};

struct ChannelDTO {
  std::string channel_name;

  uint64_t channel_delay = 0;
  uint64_t channel_width = 0;

  bool channel_enabled = false;
  bool channel_inverted = false;

  int channel_start_source = 0;
  ChannelMode channel_mode = START;
};

struct DeviceEntityDTO {
  std::string name;
  std::string description;

  std::string ip;
  int port = 4001;
  int modbus_id = 1;
  int poll_period = 500;

  bool des_lock = false;
  bool osc_lock = false;
  bool rx_loss = false;
  bool tx_fault = false;
  SFPParameters sfp_params;


  uint64_t inner_start_period = 0;
  uint64_t inner_start_width = 0;
  bool inner_start_enabled = false;
  bool inner_start_inverted = false;

  std::vector<ChannelDTO> channels = std::vector<ChannelDTO>(CHANNEL_COUNT);
};


struct GetSyncModuleStatusesRequest {
  bool cached = false;
};

struct GetSyncModuleStatusesResponse {
  bool des_lock = false;
  bool osc_lock = false;
  bool rx_loss = false;
  bool tx_fault = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetSFPParametersRequest {
  bool cached = false;
};

struct GetSFPParametersResponse {
  SFPParameters result;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetInnerStartPeriodRequest {
  bool cached = false;
};

struct GetInnerStartPeriodResponse {
  uint64_t result = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetInnerStartWidthRequest {
  bool cached = false;
};

struct GetInnerStartWidthResponse {
  uint64_t result = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetInnerStartEnabledStatusRequest {
  bool cached = false;
};

struct GetInnerStartEnabledStatusResponse {
  bool result = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetInnerStartInvertedStatusRequest {
  bool cached = false;
};

struct GetInnerStartInvertedStatusResponse {
  bool result = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};


struct GetChannelNameRequest {
  int channel_num = 0;
  bool cached = false;
};

struct GetChannelNameResponse {
  std::string result;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetChannelDelayRequest {
  int channel_num = 0;
  bool cached = false;
};

struct GetChannelDelayResponse {
  uint64_t result = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetChannelWidthRequest {
  int channel_num = 0;
  bool cached = false;
};

struct GetChannelWidthResponse {
  uint64_t result = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetChannelEnabledStatusRequest {
  int channel_num = 0;
  bool cached = false;
};

struct GetChannelEnabledStatusResponse {
  bool result = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetChannelInvertedStatusRequest {
  int channel_num = 0;
  bool cached = false;
};

struct GetChannelInvertedStatusResponse {
  bool result = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetChannelStartModeRequest {
  int channel_num = 0;
  bool cached = false;
};

struct GetChannelStartModeResponse {
  ChannelMode result = PROXY;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct GetChannelStartSourceRequest {
  int channel_num = 0;
  bool cached = false;
};

struct GetChannelStartSourceResponse {
  int result = -1;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};


struct SetInnerStartPeriodRequest {
  uint64_t value;
};

struct SetInnerStartPeriodResponse {
  uint64_t value = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetInnerStartWidthRequest {
  uint64_t value;
};

struct SetInnerStartWidthResponse {
  uint64_t value = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetInnerStartEnabledStatusRequest {
  bool value;
};

struct SetInnerStartEnabledStatusResponse {
  bool value = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetInnerStartInvertedStatusRequest {
  bool value;
};

struct SetInnerStartInvertedStatusResponse {
  bool value = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetChannelNameRequest {
  int channel_num = 0;
  std::string value;
};

struct SetChannelNameResponse {
  std::string result;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetChannelDelayRequest {
  int channel_num = -1;
  uint64_t value = 0;
};

struct SetChannelDelayResponse {
  uint64_t value = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetChannelWidthRequest {
  int channel_num = -1;
  uint64_t value = 0;
};

struct SetChannelWidthResponse {
  uint64_t value = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetChannelEnabledStatusRequest {
  int channel_num = -1;
  bool value;
};

struct SetChannelEnabledStatusResponse {
  bool value = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetChannelInvertedStatusRequest {
  int channel_num = -1;
  bool value = 0;
};

struct SetChannelInvertedStatusResponse {
  bool value = false;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetChannelStartSourceRequest {
  int channel_num = -1;
  int value = -1;
};

struct SetChannelStartSourceResponse {
  int value = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};

struct SetChannelStartModeRequest {
  int channel_num = -1;
  ChannelMode value = PROXY;
};

struct SetChannelStartModeResponse {
  ChannelMode value = PROXY;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};


#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICETYPES_H_
