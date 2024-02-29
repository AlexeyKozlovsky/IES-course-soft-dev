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

GetChannelDelayResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsDelay(GetChannelDelayRequest request) {
  GetChannelDelayResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsDelay(request);
  }

  return response;
}

int DeviceEntityConnectedStateStandaloneImpl1::getChannelCount() {
  return CHANNEL_COUNT;
}

GetSyncModuleStatusesResponse DeviceEntityConnectedStateStandaloneImpl1::getSyncModuleStatuses(
    GetSyncModuleStatusesRequest request) {
  GetSyncModuleStatusesResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getSyncModuleStatuses(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }


  return response;
}

GetSFPParametersResponse DeviceEntityConnectedStateStandaloneImpl1::getSFPParameters(GetSFPParametersRequest request) {
  GetSFPParametersResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getSFPParameters(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }


  return response;
}

GetInnerStartWidthResponse DeviceEntityConnectedStateStandaloneImpl1::getInnerStartWidth(GetInnerStartWidthRequest request) {
  GetInnerStartWidthResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getInnerStartWidth(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }


  return response;
}

GetInnerStartEnabledStatusResponse DeviceEntityConnectedStateStandaloneImpl1::getInnerStartEnabledStatus(
    GetInnerStartEnabledStatusRequest request) {
  GetInnerStartEnabledStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getInnerStartEnabledStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }


  return response;
}

GetInnerStartInvertedStatusResponse DeviceEntityConnectedStateStandaloneImpl1::getInnerStartInvertedStatus(
    GetInnerStartInvertedStatusRequest request) {
  GetInnerStartInvertedStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getInnerStartInvertedStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }


  return response;
}

GetChannelWidthResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsWidth(GetChannelWidthRequest request) {
  GetChannelWidthResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsWidth(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }


  return response;
}

GetChannelEnabledStatusResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsEnabledStatus(
    GetChannelEnabledStatusRequest request) {
  GetChannelEnabledStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsEnabledStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}

GetChannelInvertedStatusResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsInvertedStatus(
    GetChannelInvertedStatusRequest request) {
  GetChannelInvertedStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsInvertedStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}

GetChannelStartModeResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsStartMode(GetChannelStartModeRequest request) {
  GetChannelStartModeResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsStartMode(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}

GetChannelStartSourceResponse DeviceEntityConnectedStateStandaloneImpl1::getChannelsStartSource(
    GetChannelStartSourceRequest request) {
  GetChannelStartSourceResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->getChannelsStartSource(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}

SetInnerStartPeriodResponse DeviceEntityConnectedStateStandaloneImpl1::setInnerStartPeriod(SetInnerStartPeriodRequest request) {
  SetInnerStartPeriodResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setInnerStartPeriod(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}

SetInnerStartWidthResponse DeviceEntityConnectedStateStandaloneImpl1::setInnerStartWidth(SetInnerStartWidthRequest request) {
  SetInnerStartWidthResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setInnerStartWidth(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}
SetInnerStartEnabledStatusResponse DeviceEntityConnectedStateStandaloneImpl1::setInnerStartEnabledStatus(
    SetInnerStartEnabledStatusRequest request) {
  SetInnerStartEnabledStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setInnerStartEnabledStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}
SetInnerStartInvertedStatusResponse DeviceEntityConnectedStateStandaloneImpl1::setInnerStartInvertedStatus(
    SetInnerStartInvertedStatusRequest request) {
  SetInnerStartInvertedStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setInnerStartInvertedStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}
SetChannelDelayResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelDelay(SetChannelDelayRequest request) {
  SetChannelDelayResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelDelay(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}
SetChannelWidthResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelWidth(SetChannelWidthRequest request) {
  return SetChannelWidthResponse();
}
SetChannelEnabledStatusResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelEnabledStatus(
    SetChannelEnabledStatusRequest request) {
  SetChannelEnabledStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelEnabledStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}
SetChannelInvertedStatusResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelInvertedStatus(
    SetChannelInvertedStatusRequest request) {
  SetChannelInvertedStatusResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelInvertedStatus(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}
SetChannelStartSourceResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelStartSource(
    SetChannelStartSourceRequest request) {
  SetChannelStartSourceResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelStartSource(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}

SetChannelStartModeResponse DeviceEntityConnectedStateStandaloneImpl1::setChannelStartMode(SetChannelStartModeRequest request) {
  SetChannelStartModeResponse response{};

  if (_reg_card != nullptr) {
    response = _reg_card->setChannelStartMode(request);
  } else {
    std::cerr << "Reg card is nullptr " << __func__ << std::endl;
  }

  return response;
}

ErrorCode DeviceEntityConnectedStateStandaloneImpl1::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  // TODO: В мобдас враппере добавить функционал отложенной множественной записи. Чтобы можно было писать много регистров за раз из массива, который заполняется постепенно
  //  Как вариант, можно написать ещё одну обертку modbus, где это будет реализовано

  ErrorCode result = OPERATION_INTERRUPTED;
  std::cout << "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" << std::endl;
  if (dto != nullptr && _postponed_reg_card != nullptr && _device_entity != nullptr) {
    auto device_name = dto->name;
    _device_entity->setDeviceName(device_name);

    auto device_description = dto->description;
    _device_entity->setDeviceDescription(device_description);

    auto set_inner_start_period_response = _postponed_reg_card->setInnerStartPeriod({dto->inner_start_period});
    result = set_inner_start_period_response.error_code;
//    if (result != SUCCESS) return result;

    auto set_inner_start_width_response = _postponed_reg_card->setInnerStartWidth({dto->inner_start_width});
    result = set_inner_start_width_response.error_code;
//    if (result != SUCCESS) return result;

    auto set_inner_start_enabled_response = _postponed_reg_card->setInnerStartEnabledStatus({dto->inner_start_enabled});
    result = set_inner_start_enabled_response.error_code;
//    if (result != SUCCESS) return result;

    auto set_inner_start_inverted_response = _postponed_reg_card->setInnerStartInvertedStatus({dto->inner_start_inverted});
    result = set_inner_start_inverted_response.error_code;
//    if (result != SUCCESS) return result;


    auto &channels_data = dto->channels;
    for (int i = 0; i < channels_data.size(); i++) {
      auto set_channel_name_response = _device_entity->setChannelName({i, channels_data[i].channel_name});
      result = set_channel_name_response.error_code;

     auto set_channel_delay_response = _postponed_reg_card->setChannelDelay({i, channels_data[i].channel_delay});
     result = set_channel_delay_response.error_code;
//     if (result != SUCCESS) return result;

//     auto set_channel_width_response = setChannelWidth({i, channels_data[i].channel_width});
//     result = set_channel_width_response.error_code;
//     if (result != SUCCESS) return result;


     auto set_channel_enabled_response = _postponed_reg_card->setChannelEnabledStatus({i, channels_data[i].channel_enabled});
     result = set_channel_enabled_response.error_code;
//     if (result != SUCCESS) return result;

     auto set_channel_inverted_response = _postponed_reg_card->setChannelInvertedStatus({i, channels_data[i].channel_inverted});
     result = set_channel_inverted_response.error_code;
//     if (result != SUCCESS) return result;
//

      auto set_channel_start_source = _postponed_reg_card->setChannelStartSource({i, channels_data[i].channel_start_source});
      result = set_channel_start_source.error_code;
//     if (result != SUCCESS) return result;

     auto set_channel_start_mode_response = _postponed_reg_card->setChannelStartMode({i, channels_data[i].channel_mode});
     result = set_channel_start_mode_response.error_code;
//     if (result != SUCCESS) return result;
    }

    _postponed_reg_card->updateRegCard();
  }
  return result;
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityConnectedStateStandaloneImpl1::updateDeviceDTO() {
  // TODO: Дописать процесс формирования DTO
  return DeviceEntityState::updateDeviceDTO();
}
