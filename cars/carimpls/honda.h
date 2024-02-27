#ifndef CPP_PROJECT_TEMPLATE_HONDA_H
#define CPP_PROJECT_TEMPLATE_HONDA_H

#include <string>

#include "cars/car.h"


class Honda: public Car {
public:
    void go() override;

    void setEngine(const std::string &engine_name) override;

    void setColor(const std::string &color) override;

private:
    std::string _engine;
    std::string _color;
};



#endif //CPP_PROJECT_TEMPLATE_HONDA_H
