#ifndef CPP_PROJECT_TEMPLATE_WIDGETS_CONTROLLER_H_
#define CPP_PROJECT_TEMPLATE_WIDGETS_CONTROLLER_H_

#include <QObject>

#include "testwidget.h"
#include "testwidget2.h"

class Controller: public QObject {
  Q_OBJECT
 public:
  explicit Controller(TestWidget *test_widget,
                      TestWidget2 *test_widget_2,
                      QObject *parent = nullptr);

 private:
  TestWidget *_test_widget = nullptr;
  TestWidget2 *_test_widget_2 = nullptr;

  void setConnections();

 private slots:
  void acceptButtonClicked();
};

#endif //CPP_PROJECT_TEMPLATE_WIDGETS_CONTROLLER_H_
