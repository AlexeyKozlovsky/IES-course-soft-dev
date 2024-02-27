#include "dataproviderfactoryimpl1.h"

#include "services/dataproviders/dataproviderimpl1.h"


std::shared_ptr<DataProvider> DataProviderFactoryImpl1::createDataProvider(const std::string &url) {
  std::shared_ptr<DataProvider> result = nullptr;
  // Тут возможно будут какие-то проверки на валидацию url и т.д.

  result = std::make_shared<DataProviderImpl1>(url);
  return result;
}
