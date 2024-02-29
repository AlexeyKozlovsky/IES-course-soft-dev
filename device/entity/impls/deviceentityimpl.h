#ifndef CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYIMPL_H_
#define CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYIMPL_H_

#include <memory>
#include <map>

#include "device/entity/deviceentity.h"


class DeviceEntityImpl: public DeviceEntity {
 public:
  explicit DeviceEntityImpl(const std::shared_ptr<DeviceEntityDTO> &dto);

 private:
  std::string getDeviceName() override;
  void setDeviceName(const std::string &name) override;
  std::string getDeviceDescription() override;
  void setDeviceDescription(const std::string &name) override;
  DeviceState getDeviceState() override;
 public:

  void setConnectionStatus(bool connection_status) override;
  bool getConnectionStatus() override;
  ErrorCode connect() override;
  ErrorCode disconnect() override;

  void addState(const std::pair<DeviceState, std::shared_ptr<DeviceEntityState>> &state);
  void setRegCard(const std::shared_ptr<DeviceEntityRegCard> &reg_card);
  void changeState(DeviceState state);

  void process() override;

  GetInnerStartPeriodResponse getInnerStartPeriod(GetInnerStartPeriodRequest request) override;

  GetSyncModuleStatusesResponse getSyncModuleStatuses(GetSyncModuleStatusesRequest request) override;
  GetSFPParametersResponse getSFPParameters(GetSFPParametersRequest request) override;
  GetInnerStartWidthResponse getInnerStartWidth(GetInnerStartWidthRequest request) override;
  GetInnerStartEnabledStatusResponse getInnerStartEnabledStatus(GetInnerStartEnabledStatusRequest request) override;
  GetInnerStartInvertedStatusResponse getInnerStartInvertedStatus(GetInnerStartInvertedStatusRequest request) override;

  GetChannelNameResponse getChannelName(GetChannelNameRequest request) override;
  GetChannelDelayResponse getChannelsDelay(GetChannelDelayRequest request) override;
  GetChannelWidthResponse getChannelsWidth(GetChannelWidthRequest request) override;
  GetChannelEnabledStatusResponse getChannelsEnabledStatus(GetChannelEnabledStatusRequest request) override;
  GetChannelInvertedStatusResponse getChannelsInvertedStatus(GetChannelInvertedStatusRequest request) override;
  GetChannelStartModeResponse getChannelsStartMode(GetChannelStartModeRequest request) override;
  GetChannelStartSourceResponse getChannelsStartSource(GetChannelStartSourceRequest request) override;

  SetInnerStartPeriodResponse setInnerStartPeriod(SetInnerStartPeriodRequest request) override;
  SetInnerStartWidthResponse setInnerStartWidth(SetInnerStartWidthRequest request) override;
  SetInnerStartEnabledStatusResponse setInnerStartEnabledStatus(SetInnerStartEnabledStatusRequest request) override;
  SetInnerStartInvertedStatusResponse setInnerStartInvertedStatus(SetInnerStartInvertedStatusRequest request) override;

  SetChannelNameResponse setChannelName(SetChannelNameRequest request) override;

  SetChannelDelayResponse setChannelDelay(SetChannelDelayRequest request) override;
  SetChannelWidthResponse setChannelWidth(SetChannelWidthRequest request) override;
  SetChannelEnabledStatusResponse setChannelEnabledStatus(SetChannelEnabledStatusRequest request) override;
  SetChannelInvertedStatusResponse setChannelInvertedStatus(SetChannelInvertedStatusRequest request) override;
  SetChannelStartSourceResponse setChannelStartSource(SetChannelStartSourceRequest request) override;
  SetChannelStartModeResponse setChannelStartMode(SetChannelStartModeRequest request) override;

  int getChannelCount() override;

  ErrorCode loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) override;
  std::shared_ptr<DeviceEntityDTO> updateDeviceDTO() override;

  std::shared_ptr<DeviceEntityDTO> getDeviceDTO() override;

 private:
  std::shared_ptr<DeviceEntityDTO> _dto = nullptr;

  std::map<DeviceState, std::shared_ptr<DeviceEntityState>> _states;
  std::shared_ptr<DeviceEntityState> _current_state = nullptr;
  DeviceState _current_state_key = NOT_CONNECTED;
  std::shared_ptr<DeviceEntityRegCard> _reg_card = nullptr;
};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYIMPL_H_
