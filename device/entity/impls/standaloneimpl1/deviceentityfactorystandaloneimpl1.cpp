#include "deviceentityfactorystandaloneimpl1.h"

#include <modbuswrappers/modbusasyncclientwrapper/abstractmodbusasyncclientwrapper.h>
#include <modbuswrappers/modbuspostponedwritewrapper/modbuspostponedwritewrapper.h>

#include "deviceentityconnectedstatestandaloneimpl1.h"
#include "deviceentitynotconnectedstatestandaloneimpl1.h"
#include "deviceentityregcardimpl1.h"
#include "device/entity/impls/deviceentityimpl.h"


std::shared_ptr<DeviceEntity> DeviceEntityFactoryStandaloneImpl1::createDeviceEntity(const std::shared_ptr<ModbusWrapper> &modbus_wrapper,
                                                                                     const std::shared_ptr<
                                                                                         DeviceEntityDTO> &dto) {

  std::shared_ptr<DeviceEntityImpl> result = nullptr;

  if (modbus_wrapper != nullptr && dto != nullptr) {

    result = std::make_shared<DeviceEntityImpl>(dto);

    auto inner_start_period_converter = std::make_shared<DiscreteValueConverter<uint64_t>>(25, 100, 25);
    auto inner_start_width_converter = std::make_shared<DiscreteValueConverter<uint64_t>>(25, 100, 25);
    auto channel_delay_converter = std::make_shared<DiscreteValueConverter<uint64_t>>(25, 100, 25);
    auto channel_width_converter = std::make_shared<DiscreteValueConverter<uint64_t>>(25, 100, 25);

    auto reg_card = std::make_shared<DeviceEntityRegCardImpl1>(modbus_wrapper,
                                                               inner_start_period_converter,
                                                               inner_start_width_converter,
                                                               channel_delay_converter,
                                                               channel_width_converter);
    auto postponed_reg_card = std::make_shared<DeviceEntityRegCardImpl1>(modbus_wrapper,
                                                                         inner_start_period_converter,
                                                                         inner_start_width_converter,
                                                                         channel_delay_converter,
                                                                         channel_width_converter);
//      std::shared_ptr<DeviceEntityRegCardImpl1> postponed_reg_card = nullptr;


    auto connected_state = std::make_shared<DeviceEntityConnectedStateStandaloneImpl1>(result, reg_card, postponed_reg_card);
    auto not_connected_state = std::make_shared<DeviceEntityNotConnectedStateStandaloneImpl1>();

    result->addState({CONNECTED, connected_state});
    result->addState({NOT_CONNECTED, not_connected_state});
    result->setRegCard(reg_card);

    bool is_connected = false;
    modbus_wrapper->isConnected(is_connected);
    std::cout << "before MODBUS CLIENT ADDING " << __func__ << std::endl;
    modbus_wrapper->addConnectable(result);
//      std::cout << "before MODBUS POST ADDING " << __func__ << std::endl;
//      postponed_modbus_wrapper->addConnectable(result);
//      std::cout << "before MODBUS ASYNC ADDING " << __func__ << std::endl;
//      async_modbus_wrapper->addConnectable(result);

    result->setConnectionStatus(is_connected);

    result->loadDeviceDTO(dto);
  }

  return result;
}
