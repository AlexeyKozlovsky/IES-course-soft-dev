#ifndef CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET2_H_
#define CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET2_H_

#include <QWidget>
#include <QLineEdit>


class TestWidget2: public QWidget {
  Q_OBJECT
 public:
  explicit TestWidget2(QWidget *parent = nullptr);

  void setText(const QString &text);

 private:
  QLineEdit *_line_edit = nullptr;

  void initUI();
  void setConnections();
};

#endif //CPP_PROJECT_TEMPLATE_WIDGETS_TESTWIDGET2_H_
