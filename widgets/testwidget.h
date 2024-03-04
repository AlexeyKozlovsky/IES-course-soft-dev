#ifndef CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET_H_
#define CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET_H_

#include <QWidget>
#include <QPushButton>

class TestWidget: public QWidget {
  Q_OBJECT
 public:
  explicit TestWidget(QWidget *parent = nullptr);

 signals:
  void acceptButtonSignal();

 private:
  void initUI();
  void setConnections();

  QPushButton *_accept_button = nullptr;
  QPushButton *_cancel_button = nullptr;

 private slots:
  void acceptButtonClicked();
};

#endif //CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET_H_
