#ifndef CPP_PROJECT_TEMPLATE_DATAPROVIDERFACTORYIMPL2_H
#define CPP_PROJECT_TEMPLATE_DATAPROVIDERFACTORYIMPL2_H


#include "services/dataproviderfactory.h"

class DataProviderFactoryImpl2: public DataProviderFactory {
public:
    std::shared_ptr<DataProvider> createDataProvider(const std::string &url) override;
};


#endif //CPP_PROJECT_TEMPLATE_DATAPROVIDERFACTORYIMPL2_H
