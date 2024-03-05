#include "testwidget.h"

#include <QVBoxLayout>

TestWidget::TestWidget(QWidget *parent): QWidget(parent) {
  initUI();
  setConnections();
}

void TestWidget::setText(const QString &text) {
  if (_line_edit != nullptr) {
    _line_edit->setText(text);
  }
}

void TestWidget::initUI() {
  auto main_layout = new QVBoxLayout();

  _line_edit = new QLineEdit(this);

  main_layout->addWidget(_line_edit);

  setLayout(main_layout);
}

void TestWidget::setConnections() {

}

void TestWidget::update() {
  setText("123123");
}
