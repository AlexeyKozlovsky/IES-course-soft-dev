#include "carbuilderkamazimpl.h"

#include "cars/carimpls/kamaz.h"


std::shared_ptr<Car> CarBuilderKamazImpl::createBase() {
    _car = std::make_shared<Kamaz>();
    return _car;
}

void CarBuilderKamazImpl::setEngine(const std::string &engine_name) {
    if (engine_name != "kamaz") {
        _car->setEngine(engine_name);
    }
}

void CarBuilderKamazImpl::setColor(const std::string &color) {
    if (color != "red") {
        _car->setColor(color);
    }
}

void CarBuilderKamazImpl::reset() {
    _car = nullptr;
    createBase();
}

std::shared_ptr<Car> CarBuilderKamazImpl::getResult() {
    return _car;
}
