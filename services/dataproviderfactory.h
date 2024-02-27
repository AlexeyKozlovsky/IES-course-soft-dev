#ifndef CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDERFACTORY_H_
#define CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDERFACTORY_H_

#include <memory>

#include "dataprovider.h"


/**
 * Интерфейс для класса фабрики, чтобы реализовать фабричный метод.
 * Фабрики тоже могут иметь разные реализации. В этом и заключается основное преимущество.
 * В конкретных реализациях фабрики прописана логика по созданию КОНКРЕТНЫХ реализаций объекта.
 * В этом же, интерфейсе указывается, что сама по себе фабрика может создать объект абстрактного типа DataProvider
 */
class DataProviderFactory {
 public:
  virtual std::shared_ptr<DataProvider> createDataProvider(const std::string &url) = 0;
};

#endif //CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDERFACTORY_H_
