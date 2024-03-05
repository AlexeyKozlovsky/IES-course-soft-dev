#ifndef CPP_PROJECT_TEMPLATE_OBSERVERS_TESTWIDGET_H_
#define CPP_PROJECT_TEMPLATE_OBSERVERS_TESTWIDGET_H_

#include <QWidget>
#include <QLineEdit>

#include "observer.h"

class TestWidget: public QWidget, public Observer {
  Q_OBJECT
 public:
  explicit TestWidget(QWidget *parent = nullptr);

  void setText(const QString &text);

  void update() override;

 private:
  QLineEdit *_line_edit = nullptr;

  void initUI();
  void setConnections();
};

#endif //CPP_PROJECT_TEMPLATE_OBSERVERS_TESTWIDGET_H_
