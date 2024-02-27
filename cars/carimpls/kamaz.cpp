#include "kamaz.h"

#include <iostream>


void Kamaz::go() {
    std::cout << "Go KAMAZ! color:\t" << _color << ", engine:\t" << _engine << std::endl;
}

void Kamaz::setEngine(const std::string &engine_name) {
    _engine = engine_name;
}

void Kamaz::setColor(const std::string &color) {
    _color = color;
}
