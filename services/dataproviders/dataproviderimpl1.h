#ifndef CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDERS_DATAPROVIDERIMPL1_H_
#define CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDERS_DATAPROVIDERIMPL1_H_

#include "services/dataprovider.h"


/**
 * Реализация дата провайдера, которая отвечает за парсер сайта статьи и получение её названия
 */
class DataProviderImpl1: public DataProvider {
 public:
  explicit DataProviderImpl1(const std::string &url);

  std::string getTitle() override;

 private:
  std::string _url;
};

#endif //CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDERS_DATAPROVIDERIMPL1_H_
