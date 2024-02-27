#include "dataproviderfactoryimpl2.h"
#include "services/dataproviders/dataproviderimpl2.h"

std::shared_ptr<DataProvider> DataProviderFactoryImpl2::createDataProvider(const std::string &url) {
    std::shared_ptr<DataProvider> result = nullptr;
    // Тут возможно будут какие-то проверки на валидацию url и т.д.

    result = std::make_shared<DataProviderImpl2>();
    return result;
}
