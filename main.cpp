#include <iostream>

#include <QApplication>

#include "widgets/testwidget.h"
#include "widgets/testwidget2.h"
#include "widgets/controller.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  auto test_widget = new TestWidget();
  test_widget->show();

  auto test_widget_2 = new TestWidget2();
  test_widget_2->show();

  auto controller = new Controller(test_widget, test_widget_2);

  return app.exec();
}
