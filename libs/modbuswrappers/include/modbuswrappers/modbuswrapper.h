#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPER_H_

#include <cstdint>
#include <memory>
#include <vector>

#include <utils/baseutils.h>
#include <modbus/modbus.h>
#include <threadpooling/iprocessable.h>

#include "connectable.h"


class ModbusWrapper: public IProcessable {
 public:
  virtual ~ModbusWrapper() = default;

  virtual ErrorCode connect() = 0;
  virtual ErrorCode disconnect() = 0;

  virtual ErrorCode isConnected(bool &is_connected) = 0;

  virtual ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id = 1) = 0;
  virtual ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id = 1) = 0;
  virtual ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id = 1) = 0;
  virtual ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id = 1) = 0;

  virtual ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id = 1) = 0;
  virtual ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id = 1) = 0;

  virtual void addConnectable(const std::shared_ptr<Connectable> &connectable);
  virtual void sendConnectionStatus(bool connection_status);

  virtual void process() override;

 protected:
  std::vector<std::shared_ptr<Connectable>> _connectables;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSWRAPPER_H_
