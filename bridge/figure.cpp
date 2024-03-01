#include "figure.h"

Figure::Figure(int width, int height):
  _bounding_box_width(width), _bounding_box_height(height) {

}

int Figure::getBoundingBoxArea() {
  auto area = _bounding_box_width * _bounding_box_height;
  return area;
}
