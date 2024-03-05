#include "devicemodelimpl1.h"

DeviceModelImpl1::DeviceModelImpl1(QObject *parent) : DeviceModel(parent) {

}

void DeviceModelImpl1::setPeriod(uint64_t period) {
  _period = period;
}

uint64_t DeviceModelImpl1::getPeriod() {
  return _period;
}
