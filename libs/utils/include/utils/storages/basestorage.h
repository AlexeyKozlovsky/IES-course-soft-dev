#ifndef UTILS_UTILSD_INCLUDE_UTILS_STORAGES_BASESTORAGE_H_
#define UTILS_UTILSD_INCLUDE_UTILS_STORAGES_BASESTORAGE_H_

#include <memory>
#include <vector>

#include "dimchangenotifier.h"

class BaseStorage {
 public:
  virtual void addDimChangeNotifier(const std::shared_ptr<DimChangeNotifier> &notifier);
  virtual void removeDimChangeNotifier(const std::shared_ptr<DimChangeNotifier> &notifier);

  virtual int getRowCount() = 0;

 protected:
  virtual void rowInsertedNotify();
  virtual void rowRemovedNotify();

  void updateNotifiers();

  std::vector<std::shared_ptr<DimChangeNotifier>> _dim_change_notifiers;
};


#endif //UTILS_UTILSD_INCLUDE_UTILS_STORAGES_BASESTORAGE_H_
