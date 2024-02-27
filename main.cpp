#include <iostream>

#include "cars/carbuilderimpls/carbuilderkamazimpl.h"


int main() {
    auto car_builder = std::make_shared<CarBuilderKamazImpl>();

    std::shared_ptr<Car> car = car_builder->createBase();

    car_builder->setColor("red");
    car_builder->setEngine("tesseract");

    car->go();
    return 0;
}
