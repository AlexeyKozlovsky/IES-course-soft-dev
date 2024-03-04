#include "testwidget2.h"

#include <QVBoxLayout>


TestWidget2::TestWidget2(QWidget *parent): QWidget(parent) {
  initUI();
  setConnections();
}

void TestWidget2::setText(const QString &text) {
  _line_edit->setText(text);
}

void TestWidget2::initUI() {
  auto main_layout = new QVBoxLayout();

  _line_edit = new QLineEdit(this);
  main_layout->addWidget(_line_edit);

  setLayout(main_layout);
}

void TestWidget2::setConnections() {

}
