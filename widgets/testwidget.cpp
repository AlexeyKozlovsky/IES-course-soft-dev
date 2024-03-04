#include "testwidget.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>

#include <QDebug>


TestWidget::TestWidget(QWidget *parent): QWidget(parent) {
  initUI();
  setConnections();
}

void TestWidget::initUI() {
  auto main_layout = new QGridLayout();

  auto data_form_layout = new QFormLayout();

  auto ip_label = new QLabel("IP", this);
  auto ip_line_edit = new QLineEdit(this);

  _accept_button = new QPushButton("Accept", this);
  _cancel_button = new QPushButton("Cancel", this);

  data_form_layout->addRow(ip_label, ip_line_edit);

  main_layout->addLayout(data_form_layout, 0, 0, 1, 2);
  main_layout->addWidget(_accept_button, 1, 0);
  main_layout->addWidget(_cancel_button, 1, 1);

  setLayout(main_layout);
}

void TestWidget::setConnections() {
  QObject::connect(_accept_button, &QPushButton::released,
                   this, &TestWidget::acceptButtonClicked);

//  QObject::connect(_accept_button, &QPushButton::released,
//                   this, &TestWidget::acceptButtonSignal);
}

void TestWidget::acceptButtonClicked() {
  emit acceptButtonSignal();
  qDebug() << "BUTTON CLICKED! " << __func__;
}
