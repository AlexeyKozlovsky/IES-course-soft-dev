#ifndef CPP_PROJECT_TEMPLATE_CARBUILDERKAMAZIMPL_H
#define CPP_PROJECT_TEMPLATE_CARBUILDERKAMAZIMPL_H

#include "cars/carbuilder.h"


class CarBuilderKamazImpl: public CarBuilder {
public:
    std::shared_ptr<Car> createBase() override;

    void setEngine(const std::string &engine_name) override;

    void setColor(const std::string &color) override;

    void reset() override;

    std::shared_ptr<Car> getResult() override;

private:
    std::shared_ptr<Car> _car = nullptr;
};


#endif //CPP_PROJECT_TEMPLATE_CARBUILDERKAMAZIMPL_H
