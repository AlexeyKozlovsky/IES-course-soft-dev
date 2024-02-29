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

 private:
  std::shared_ptr<DeviceEntityDTO> _dto = nullptr;

  std::map<DeviceState, std::shared_ptr<DeviceEntityState>> _states;
  std::shared_ptr<DeviceEntityState> _current_state = nullptr;
  DeviceState _current_state_key = NOT_CONNECTED;
  std::shared_ptr<DeviceEntityRegCard> _reg_card = nullptr;
};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYIMPL_H_
