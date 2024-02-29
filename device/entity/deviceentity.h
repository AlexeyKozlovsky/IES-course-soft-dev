#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_

#include <string>
#include <memory>

#include <modbuswrappers/connectable.h>
#include <threadpooling/iprocessable.h>

#include "device/basedevice.h"


#include "devicetypes.h"


class DeviceEntityState {
 public:
  virtual GetSyncModuleStatusesResponse getSyncModuleStatuses(GetSyncModuleStatusesRequest request) = 0;

  virtual GetSFPParametersResponse getSFPParameters(GetSFPParametersRequest request) = 0;

  virtual GetInnerStartPeriodResponse getInnerStartPeriod(GetInnerStartPeriodRequest request) = 0;
  virtual GetInnerStartWidthResponse getInnerStartWidth(GetInnerStartWidthRequest request) = 0;
  virtual GetInnerStartEnabledStatusResponse getInnerStartEnabledStatus(GetInnerStartEnabledStatusRequest request) = 0;
  virtual GetInnerStartInvertedStatusResponse getInnerStartInvertedStatus(GetInnerStartInvertedStatusRequest request) = 0;

  virtual GetChannelDelayResponse getChannelsDelay(GetChannelDelayRequest request) = 0;
  virtual GetChannelWidthResponse getChannelsWidth(GetChannelWidthRequest request) = 0;
  virtual GetChannelEnabledStatusResponse getChannelsEnabledStatus(GetChannelEnabledStatusRequest request) = 0;
  virtual GetChannelInvertedStatusResponse getChannelsInvertedStatus(GetChannelInvertedStatusRequest request) = 0;
  virtual GetChannelStartModeResponse getChannelsStartMode(GetChannelStartModeRequest request) = 0;
  virtual GetChannelStartSourceResponse getChannelsStartSource(GetChannelStartSourceRequest request) = 0;

  virtual SetInnerStartPeriodResponse setInnerStartPeriod(SetInnerStartPeriodRequest request) = 0;
  virtual SetInnerStartWidthResponse setInnerStartWidth(SetInnerStartWidthRequest request) = 0;
  virtual SetInnerStartEnabledStatusResponse setInnerStartEnabledStatus(SetInnerStartEnabledStatusRequest request) = 0;
  virtual SetInnerStartInvertedStatusResponse setInnerStartInvertedStatus(SetInnerStartInvertedStatusRequest request) = 0;

  virtual SetChannelDelayResponse setChannelDelay(SetChannelDelayRequest request) = 0;
  virtual SetChannelWidthResponse setChannelWidth(SetChannelWidthRequest request) = 0;
  virtual SetChannelEnabledStatusResponse setChannelEnabledStatus(SetChannelEnabledStatusRequest request) = 0;
  virtual SetChannelInvertedStatusResponse setChannelInvertedStatus(SetChannelInvertedStatusRequest request) = 0;
  virtual SetChannelStartSourceResponse setChannelStartSource(SetChannelStartSourceRequest request) = 0;
  virtual SetChannelStartModeResponse setChannelStartMode(SetChannelStartModeRequest request) = 0;

  virtual int getChannelCount() = 0;

  /**
   * Метод, который позволяет на основании ДТО обновить девайс
   * @param dto
   * @return код ошибки, который является SUCCESS только в том случае, когда аппаратный девайс полностью обновился в соответствие с DTO
   */
  virtual ErrorCode loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {return OPERATION_INTERRUPTED;};


  /**
   * Метод, который позволяет сформироват  ь DTO по актуальным настройками аппаратного девайса
   * @return ДТО
   */
  virtual std::shared_ptr<DeviceEntityDTO> updateDeviceDTO() {return nullptr;};
};

class DeviceEntityRegCard: public DeviceEntityState, public Connectable {
 public:
  virtual void updateRegCard() = 0;
};

class DeviceEntity: public BaseDevice, public DeviceEntityState, public Connectable, public IProcessable {
 public:
  virtual GetChannelNameResponse getChannelName(GetChannelNameRequest request) = 0;
  virtual SetChannelNameResponse setChannelName(SetChannelNameRequest request) = 0;

  virtual std::shared_ptr<DeviceEntityDTO> getDeviceDTO() = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_
