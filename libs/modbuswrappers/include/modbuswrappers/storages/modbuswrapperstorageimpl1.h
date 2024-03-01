#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_STORAGES_MODBUSWRAPPERSTORAGEIMPL1_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_STORAGES_MODBUSWRAPPERSTORAGEIMPL1_H_

#include <map>

#include "modbuswrappers/modbuswrapperstorage.h"

class ModbusWrapperStorageImpl1: public ModbusWrapperStorage {
 public:
  std::shared_ptr<ModbusWrapper> getBaseModbusWrapper(const std::string &ip) override;
  void addBaseModbusWrapper(const std::shared_ptr<ModbusWrapper> &modbus_wrapper, const std::string &ip) override;

 private:
  std::map<std::string, std::shared_ptr<ModbusWrapper>> _base_modbus_wrappers;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_STORAGES_MODBUSWRAPPERSTORAGEIMPL1_H_
