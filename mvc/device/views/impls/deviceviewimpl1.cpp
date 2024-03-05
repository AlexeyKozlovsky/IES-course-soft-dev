#include "deviceviewimpl1.h"

#include <QVBoxLayout>


DeviceViewImpl1::DeviceViewImpl1(QWidget *parent): DeviceView(parent) {
  initUI();
  setConnections();
}

void DeviceViewImpl1::setPeriod(const QString &text) {
  if (_period_line_edit != nullptr) {
    _period_line_edit->setText(text);
  }
}

QString DeviceViewImpl1::getPeriod() {
  QString result;
  if (_period_line_edit != nullptr) {
    result = _period_line_edit->text();
  }
  return result;
}

void DeviceViewImpl1::initUI() {
  auto main_layout = new QVBoxLayout();

  _period_line_edit = new QLineEdit(this);
  _accept_button = new QPushButton("Accept", this);

  main_layout->addWidget(_period_line_edit);
  main_layout->addWidget(_accept_button);

  setLayout(main_layout);
}

void DeviceViewImpl1::setConnections() {
  if (_accept_button != nullptr) {
    QObject::connect(_accept_button, &QPushButton::released,
                     this, &DeviceViewImpl1::acceptButtonClicked);
  }
}

void DeviceViewImpl1::acceptButtonClicked() {
  if (_period_line_edit != nullptr) {
    auto period = _period_line_edit->text();
    emit periodChangedSignal(period);
  }
}
