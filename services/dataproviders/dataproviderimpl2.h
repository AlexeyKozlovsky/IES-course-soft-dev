#ifndef CPP_PROJECT_TEMPLATE_DATAPROVIDERIMPL2_H
#define CPP_PROJECT_TEMPLATE_DATAPROVIDERIMPL2_H


#include "services/dataprovider.h"


class DataProviderImpl2: public DataProvider {
public:
    std::string getTitle() override;
};


#endif //CPP_PROJECT_TEMPLATE_DATAPROVIDERIMPL2_H
