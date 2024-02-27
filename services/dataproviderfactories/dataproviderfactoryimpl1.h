#ifndef CPP_PROJECT_TEMPLATE_SERVICES_FACTORIES_DATAPROVIDERFACTORYIMPL1_H_
#define CPP_PROJECT_TEMPLATE_SERVICES_FACTORIES_DATAPROVIDERFACTORYIMPL1_H_

#include "services/dataproviderfactory.h"

/**
 * Конкретная реализация фабрики для создания объекта класса DataProviderImpl1
 */
class DataProviderFactoryImpl1: public DataProviderFactory {
 public:
  std::shared_ptr<DataProvider> createDataProvider(const std::string &url) override;
};

#endif //CPP_PROJECT_TEMPLATE_SERVICES_FACTORIES_DATAPROVIDERFACTORYIMPL1_H_
