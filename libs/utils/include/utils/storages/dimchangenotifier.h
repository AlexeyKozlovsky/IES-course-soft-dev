#ifndef PLUGIN_LIBPLUGIN_SRC_PLUGIN_STORAGES_DIMCHANGENOTIFIER_H_
#define PLUGIN_LIBPLUGIN_SRC_PLUGIN_STORAGES_DIMCHANGENOTIFIER_H_

// TODO: Потом возможно вынести класс в DiaUtils

class DimChangeNotifier {
 public:
  virtual void insertRows(int row, int count) = 0;
  virtual void removeRows(int row, int count) = 0;
  virtual void insertColumns(int column, int count) = 0;
  virtual void removeColumns(int column, int count) = 0;
};

#endif //PLUGIN_LIBPLUGIN_SRC_PLUGIN_STORAGES_DIMCHANGENOTIFIER_H_
