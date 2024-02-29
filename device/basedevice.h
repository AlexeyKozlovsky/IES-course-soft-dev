#ifndef PLUGIN_LIBPLUGIN_INCLUDE_PLUGIN_DEVICEPLUGINS_BASEDEVICE_H_
#define PLUGIN_LIBPLUGIN_INCLUDE_PLUGIN_DEVICEPLUGINS_BASEDEVICE_H_

#include <string>

#include <utils/baseutils.h>


class BaseDevice {
 public:
  virtual std::string getDeviceName() = 0;
  virtual void setDeviceName(const std::string &name) = 0;

  virtual std::string getDeviceDescription() = 0;
  virtual void setDeviceDescription(const std::string &description) = 0;

  virtual DeviceState getDeviceState() = 0;
};

#endif //PLUGIN_LIBPLUGIN_INCLUDE_PLUGIN_DEVICEPLUGINS_BASEDEVICE_H_
