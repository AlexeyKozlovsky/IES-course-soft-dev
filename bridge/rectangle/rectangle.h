#ifndef CPP_PROJECT_TEMPLATE_BRIDGE_RECTANGLE_RECTANGLE_H_
#define CPP_PROJECT_TEMPLATE_BRIDGE_RECTANGLE_RECTANGLE_H_

#include <memory>

#include "bridge/figure.h"
#include "bridge/figureimpl.h"

class Rectangle: public Figure {
 public:
  explicit Rectangle(int width, int height, const std::shared_ptr<FigureImpl> &figure_impl);

  int getArea() override;
  void draw() override;

 private:
  std::shared_ptr<FigureImpl> _figure_impl = nullptr;
};

#endif //CPP_PROJECT_TEMPLATE_BRIDGE_RECTANGLE_RECTANGLE_H_
