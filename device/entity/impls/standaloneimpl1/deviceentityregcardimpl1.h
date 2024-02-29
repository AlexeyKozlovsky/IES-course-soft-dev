#ifndef CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYREGCARDIMPL1_H_
#define CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYREGCARDIMPL1_H_

#include <modbuswrappers/modbuswrapper.h>
#include <utils/services/domain/regreaddivider.h>
#include <utils/services/domain/valueconverter.h>
#include <modbuswrappers/modbuspostponedwritewrapper/modbuspostponedwritewrapper.h>

#include "device/entity/deviceentity.h"


class DeviceEntityRegCardImpl1: public DeviceEntityRegCard {
 public:
  explicit DeviceEntityRegCardImpl1(std::shared_ptr<ModbusWrapper> modbus_wrapper,
                                    const std::shared_ptr<DiscreteValueConverter<uint64_t>> &inner_start_period_converter,
                                    const std::shared_ptr<DiscreteValueConverter<uint64_t>> &inner_start_width_converter,
                                    const std::shared_ptr<DiscreteValueConverter<uint64_t>> &channel_delay_converter,
                                    const std::shared_ptr<DiscreteValueConverter<uint64_t>> &channel_width_converter);

  void setConnectionStatus(bool connection_status) override;
  bool getConnectionStatus() override;
  ErrorCode connect() override;
  ErrorCode disconnect() override;

  GetSyncModuleStatusesResponse getSyncModuleStatuses(GetSyncModuleStatusesRequest request) override;

  GetInnerStartPeriodResponse getInnerStartPeriod(GetInnerStartPeriodRequest request) override;
  GetChannelDelayResponse getChannelsDelay(GetChannelDelayRequest request) override;

  GetSFPParametersResponse getSFPParameters(GetSFPParametersRequest request) override;
  GetInnerStartWidthResponse getInnerStartWidth(GetInnerStartWidthRequest request) override;
  GetInnerStartEnabledStatusResponse getInnerStartEnabledStatus(GetInnerStartEnabledStatusRequest request) override;
  GetInnerStartInvertedStatusResponse getInnerStartInvertedStatus(GetInnerStartInvertedStatusRequest request) override;
  GetChannelWidthResponse getChannelsWidth(GetChannelWidthRequest request) override;
  GetChannelEnabledStatusResponse getChannelsEnabledStatus(GetChannelEnabledStatusRequest request) override;
  GetChannelInvertedStatusResponse getChannelsInvertedStatus(GetChannelInvertedStatusRequest request) override;
  GetChannelStartModeResponse getChannelsStartMode(GetChannelStartModeRequest request) override;
  GetChannelStartSourceResponse getChannelsStartSource(GetChannelStartSourceRequest request) override;

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

  int getChannelCount() override;

  void updateRegCard() override;
  ErrorCode loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) override;
  std::shared_ptr<DeviceEntityDTO> updateDeviceDTO() override;

 private:
  /**
   * Основной модбас враппер
   */
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;


  bool _connection_status = false;

  std::shared_ptr<RegReadDivider> _reg_read_divider = nullptr;

  std::shared_ptr<DiscreteValueConverter<uint64_t>> _inner_start_period_converter = nullptr;
  std::shared_ptr<DiscreteValueConverter<uint64_t>> _inner_start_width_converter = nullptr;
  std::shared_ptr<DiscreteValueConverter<uint64_t>> _channel_delay_converter = nullptr;
  std::shared_ptr<DiscreteValueConverter<uint64_t>> _channel_width_converter = nullptr;
};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYREGCARDIMPL1_H_
