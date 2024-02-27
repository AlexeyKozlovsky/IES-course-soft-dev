#ifndef CPP_PROJECT_TEMPLATE_CARBUILDER_H
#define CPP_PROJECT_TEMPLATE_CARBUILDER_H

#include <string>
#include <memory>

#include "car.h"

class CarBuilder {
public:
    virtual std::shared_ptr<Car> createBase() = 0;

    virtual void setEngine(const std::string &engine_name) = 0;
    virtual void setColor(const std::string &color) = 0;

    virtual void reset() = 0;

    virtual std::shared_ptr<Car> getResult() = 0;
};

#endif //CPP_PROJECT_TEMPLATE_CARBUILDER_H
