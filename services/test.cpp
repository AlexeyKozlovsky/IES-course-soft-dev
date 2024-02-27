#include "test.h"

Test::Test(const std::shared_ptr<DataProviderFactory> &data_provider_factory):
    _factory(data_provider_factory) {

}

std::string Test::getTitle() {
    std::string result;
    if (_factory != nullptr) {
        auto data_provider = _factory->createDataProvider("");
        if (data_provider != nullptr) {
            result = data_provider->getTitle();
        }
    }
    return result;
}
