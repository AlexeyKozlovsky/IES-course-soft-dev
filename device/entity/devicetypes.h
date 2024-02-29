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

struct GetInnerStartPeriodRequest {
  bool cached = false;
};

struct GetInnerStartPeriodResponse {
  uint64_t result = 0;
  ErrorCode error_code = OPERATION_INTERRUPTED;
};



#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICETYPES_H_
