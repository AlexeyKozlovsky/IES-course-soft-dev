#include "modbuswrappers/modbuswrapper.h"

void ModbusWrapper::addConnectable(const std::shared_ptr<Connectable> &connectable) {
  std::cout << "Connectable adding... " << _connectables.size() << " " << this << " " << __func__ << std::endl;
  _connectables.push_back(connectable);
  std::cout << "Connectable added: " << _connectables.size() << " " << this << " " << __func__ << std::endl;
}

void ModbusWrapper::sendConnectionStatus(bool connection_status) {
  std::cout << "Sending to " << _connectables.size() << " connectables " << this << " " << __func__ << std::endl;
  std::for_each(std::begin(_connectables), std::end(_connectables), [&](const std::shared_ptr<Connectable> &connectable) {
    connectable->setConnectionStatus(connection_status);
  });
}

void ModbusWrapper::process() {

}
