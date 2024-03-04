#include "controller.h"

Controller::Controller(TestWidget *test_widget, TestWidget2 *test_widget_2, QObject *parent):
    QObject(parent), _test_widget(test_widget), _test_widget_2(test_widget_2) {
  setConnections();
}

void Controller::setConnections() {
  QObject::connect(_test_widget, &TestWidget::acceptButtonSignal,
                   this, &Controller::acceptButtonClicked);
}

void Controller::acceptButtonClicked() {
  _test_widget_2->setText("blabla");
}
