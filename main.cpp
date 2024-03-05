#include <iostream>

#include <QApplication>

#include "observers/testwidget.h"
#include "observers/button.h"
#include "observers/logger.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  auto logger = std::make_shared<Logger>();

  auto test_widget = std::make_shared<TestWidget>();
  test_widget->show();

  auto button = std::make_shared<Button>(logger);
  button->show();


  return app.exec();
}
