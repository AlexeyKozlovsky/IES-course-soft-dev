#include <iostream>

#include <QApplication>

#include "widgets/testwidget.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  auto test_widget = new TestWidget();
  test_widget->show();

  return app.exec();
}
