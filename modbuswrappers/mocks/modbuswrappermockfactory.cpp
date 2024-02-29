#include "modbuswrappers/mocks/modbuswrappermockfactory.h"
#include "modbuswrappers/mocks/modbuswrappermock1.h"

std::shared_ptr<ModbusWrapper> ModbusWrapperMockFactory::createModbusWrapper(const std::string &ip,
                                                                             int port,
                                                                             int modbus_id,
                                                                             int holding_regs_count,
                                                                             int input_regs_count) {
  std::shared_ptr<ModbusWrapper> result = nullptr;

  result = std::make_shared<ModbusWrapperMock1>();
  return result;
}
std::shared_ptr<ModbusWrapper> ModbusWrapperMockFactory::createBaseModbusWrapper(const std::string &ip, int port) {
  std::shared_ptr<ModbusWrapper> result = nullptr;

  result = std::make_shared<ModbusWrapperMock1>();
  return result;
}
