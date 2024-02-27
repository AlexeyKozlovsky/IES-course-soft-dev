#ifndef CPP_PROJECT_TEMPLATE_TEST_H
#define CPP_PROJECT_TEMPLATE_TEST_H

#include <memory>
#include "dataproviderfactory.h"


class Test {
public:
    explicit Test(const std::shared_ptr<DataProviderFactory> &data_provider_factory);

    std::string getTitle();

private:
    std::shared_ptr<DataProviderFactory> _factory = nullptr;
};


#endif //CPP_PROJECT_TEMPLATE_TEST_H
