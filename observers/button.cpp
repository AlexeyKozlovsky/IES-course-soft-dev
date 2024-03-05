#include "button.h"

#include <QVBoxLayout>

Button::Button(const std::shared_ptr<Observer> &observer,
               QWidget *parent):
               QWidget(parent),
               _observer(observer) {
  initUI();
  setConnections();
}

void Button::initUI() {
  auto main_layout = new QVBoxLayout();

  _button = new QPushButton("okey", this);
  main_layout->addWidget(_button);

  setLayout(main_layout);
}

void Button::setConnections() {
  if (_button != nullptr) {
    QObject::connect(_button, &QPushButton::released,
                     this, &Button::buttonClicked);
  }
}

void Button::buttonClicked() {
  if (_observer != nullptr) {
    _observer->update();
  }
}
