#ifndef CPP_PROJECT_TEMPLATE_BRIDGE_FIGURE_H_
#define CPP_PROJECT_TEMPLATE_BRIDGE_FIGURE_H_

class Figure {
 public:
  Figure(int width, int height);

  virtual int getArea() = 0;

  int getBoundingBoxArea();

  virtual void draw() = 0;

 protected:
  int _bounding_box_width = 0;
  int _bounding_box_height = 0;
};

#endif //CPP_PROJECT_TEMPLATE_BRIDGE_FIGURE_H_
