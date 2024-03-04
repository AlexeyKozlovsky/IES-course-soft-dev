#include "testwidget.h"

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>


TestWidget::TestWidget(QWidget *parent): QWidget(parent) {
  initUI();
}

void TestWidget::initUI() {
  auto main_layout = new QGridLayout();

  auto data_form_layout = new QFormLayout();

  auto ip_label = new QLabel("IP", this);
  auto ip_line_edit = new QLineEdit(this);

  auto accept_button = new QPushButton("Accept", this);
  auto cancel_button = new QPushButton("Cancel", this);

  data_form_layout->addRow(ip_label, ip_line_edit);

  main_layout->addLayout(data_form_layout, 0, 0, 1, 2);
  main_layout->addWidget(accept_button, 1, 0);
  main_layout->addWidget(cancel_button, 1, 1);

  setLayout(main_layout);
}
