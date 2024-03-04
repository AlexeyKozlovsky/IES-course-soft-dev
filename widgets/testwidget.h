#ifndef CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET_H_
#define CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET_H_

#include <QWidget>


class TestWidget: public QWidget {
  Q_OBJECT
 public:
  explicit TestWidget(QWidget *parent = nullptr);

 private:
  void initUI();
};

#endif //CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET_H_
