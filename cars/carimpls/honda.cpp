#include "honda.h"

#include <iostream>


void Honda::go() {
    std::cout << "Go HONDA!" << std::endl;
}

void Honda::setEngine(const std::string &engine_name) {
    _engine = engine_name;
}

void Honda::setColor(const std::string &color) {
    _color = color;
}
