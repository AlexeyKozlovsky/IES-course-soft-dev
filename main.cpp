#include <iostream>

#include <bridge/figure.h>
#include <bridge/rectangle/rectangle.h>
#include <bridge/impls/figurerasterimpl.h>


int main() {
  auto figure_impl = std::make_shared<FigureRasterImpl>();
  auto rectangle = std::make_shared<Rectangle>(100, 100, figure_impl);

  rectangle->draw();
  return 0;
}
