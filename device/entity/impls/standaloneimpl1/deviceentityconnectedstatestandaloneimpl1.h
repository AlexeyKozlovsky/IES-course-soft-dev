#ifndef CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYCONNECTEDSTATESTANDALONEIMPL1_H_
#define CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYCONNECTEDSTATESTANDALONEIMPL1_H_

#include <memory>

#include "device/entity/deviceentity.h"


class DeviceEntityConnectedStateStandaloneImpl1: public DeviceEntityState {
 public:
  explicit DeviceEntityConnectedStateStandaloneImpl1(const std::shared_ptr<DeviceEntity> &device_entity,
                                                     const std::shared_ptr<DeviceEntityRegCard> &reg_card,
                                                     const std::shared_ptr<DeviceEntityRegCard> &postponed_reg_card);

  GetInnerStartPeriodResponse getInnerStartPeriod(GetInnerStartPeriodRequest request) override;
  GetSyncModuleStatusesResponse getSyncModuleStatuses(GetSyncModuleStatusesRequest request) override;
  GetSFPParametersResponse getSFPParameters(GetSFPParametersRequest request) override;
  GetInnerStartWidthResponse getInnerStartWidth(GetInnerStartWidthRequest request) override;
  GetInnerStartEnabledStatusResponse getInnerStartEnabledStatus(GetInnerStartEnabledStatusRequest request) override;
  GetInnerStartInvertedStatusResponse getInnerStartInvertedStatus(GetInnerStartInvertedStatusRequest request) override;
  GetChannelWidthResponse getChannelsWidth(GetChannelWidthRequest request) override;
  GetChannelEnabledStatusResponse getChannelsEnabledStatus(GetChannelEnabledStatusRequest request) override;
  GetChannelInvertedStatusResponse getChannelsInvertedStatus(GetChannelInvertedStatusRequest request) override;
  GetChannelStartModeResponse getChannelsStartMode(GetChannelStartModeRequest request) override;
  GetChannelStartSourceResponse getChannelsStartSource(GetChannelStartSourceRequest request) override;

  GetChannelDelayResponse getChannelsDelay(GetChannelDelayRequest request) override;
  int getChannelCount() override;

  SetInnerStartPeriodResponse setInnerStartPeriod(SetInnerStartPeriodRequest request) override;
  SetInnerStartWidthResponse setInnerStartWidth(SetInnerStartWidthRequest request) override;
  SetInnerStartEnabledStatusResponse setInnerStartEnabledStatus(SetInnerStartEnabledStatusRequest request) override;
  SetInnerStartInvertedStatusResponse setInnerStartInvertedStatus(SetInnerStartInvertedStatusRequest request) override;
  SetChannelDelayResponse setChannelDelay(SetChannelDelayRequest request) override;
  SetChannelWidthResponse setChannelWidth(SetChannelWidthRequest request) override;
  SetChannelEnabledStatusResponse setChannelEnabledStatus(SetChannelEnabledStatusRequest request) override;
  SetChannelInvertedStatusResponse setChannelInvertedStatus(SetChannelInvertedStatusRequest request) override;
  SetChannelStartSourceResponse setChannelStartSource(SetChannelStartSourceRequest request) override;
  SetChannelStartModeResponse setChannelStartMode(SetChannelStartModeRequest request) override;

  ErrorCode loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) override;
  std::shared_ptr<DeviceEntityDTO> updateDeviceDTO() override;

 private:
  std::shared_ptr<DeviceEntityRegCard> _reg_card = nullptr;
  std::shared_ptr<DeviceEntityRegCard> _postponed_reg_card = nullptr;
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYCONNECTEDSTATESTANDALONEIMPL1_H_
