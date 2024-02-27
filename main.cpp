#include <iostream>

#include "services/dataproviderfactories/dataproviderfactoryimpl1.h"
#include "services/dataproviderfactories/dataproviderfactoryimpl2.h"
#include "services/test.h"


int main(int argc, char *argv[]) {
//  // Создаем саму фабрику
//  auto data_provider_factory = std::make_shared<DataProviderFactoryImpl1>();
//
//
//
//
//
//  std::string url = "https://google.com";
//  // Используем фабрик для создания объекта.
//  // Если он корректно создается, то нам возвращается НЕпустой указатель на объект
//  auto data_provider = data_provider_factory->createDataProvider(url);
//
//  if (data_provider != nullptr) {
//    auto title = data_provider->getTitle();
//    std::cout << "Title is:\t" << title;
//  }

  auto data_provider_factory = std::make_shared<DataProviderFactoryImpl1>();

  if (data_provider_factory != nullptr) {
      auto test = std::make_shared<Test>(data_provider_factory);

      if (test != nullptr) {
          std::cout << test->getTitle() << std::endl;
      }
  }

  return 0;
}