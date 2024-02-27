#ifndef CPP_PROJECT_TEMPLATE_CAR_H
#define CPP_PROJECT_TEMPLATE_CAR_H

class Car {
public:
    virtual void go() = 0;

    virtual void setEngine(const std::string &engine_name) = 0;
    virtual void setColor(const std::string &color) = 0;
};

#endif //CPP_PROJECT_TEMPLATE_CAR_H
