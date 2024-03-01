#include "rectangle.h"

Rectangle::Rectangle(int width, int height, const std::shared_ptr<FigureImpl> &figure_impl):
    Figure(width, height), _figure_impl(figure_impl){

}

int Rectangle::getArea() {
  int result = _bounding_box_height * _bounding_box_width;
  return result;
}

void Rectangle::draw() {
  if (_figure_impl != nullptr) {
    _figure_impl->draw();
  }
}
