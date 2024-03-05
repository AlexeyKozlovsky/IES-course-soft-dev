#ifndef CPP_PROJECT_TEMPLATE_OBSERVERS_BUTTON_H_
#define CPP_PROJECT_TEMPLATE_OBSERVERS_BUTTON_H_

#include <memory>

#include <QWidget>
#include <QPushButton>

#include "observer.h"


class Button: public QWidget {
  Q_OBJECT
 public:
  explicit Button(const std::shared_ptr<Observer> &observer,
                  QWidget *parent = nullptr);

 private:
  QPushButton *_button = nullptr;
  std::shared_ptr<Observer> _observer = nullptr;

  void initUI();
  void setConnections();

 private slots:
  void buttonClicked();
};

#endif //CPP_PROJECT_TEMPLATE_OBSERVERS_BUTTON_H_
