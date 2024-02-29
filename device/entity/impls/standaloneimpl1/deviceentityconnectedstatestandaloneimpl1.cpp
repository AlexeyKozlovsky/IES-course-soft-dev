#include "deviceentityconnectedstatestandaloneimpl1.h"
#include "device/entity/consts.h"

#include <iostream>


DeviceEntityConnectedStateStandaloneImpl1::DeviceEntityConnectedStateStandaloneImpl1(const std::shared_ptr<DeviceEntity> &device_entity,
                                                                                     const std::shared_ptr<DeviceEntityRegCard> &reg_card,
                                                                                     const std::shared_ptr<DeviceEntityRegCard> &postponed_reg_card):
 _reg_card(reg_card),
 _postponed_reg_card(postponed_reg_card),
 _device_entity(device_entity) {

}

GetInnerStartPeriodResponse DeviceEntityConnectedStateStandaloneImpl1::getInnerStartPeriod(GetInnerStartPeriodRequest request) {
  GetInnerStartPeriodResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getInnerStartPeriod(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }


  return response;
}
