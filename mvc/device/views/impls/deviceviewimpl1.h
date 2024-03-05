#ifndef CPP_PROJECT_TEMPLATE_MVC_DEVICE_VIEWS_IMPLS_DEVICEVIEWIMPL1_H_
#define CPP_PROJECT_TEMPLATE_MVC_DEVICE_VIEWS_IMPLS_DEVICEVIEWIMPL1_H_

#include <QPushButton>
#include <QLineEdit>

#include "mvc/device/views/deviceview.h"

class DeviceViewImpl1: public DeviceView {
  Q_OBJECT
 public:
  explicit DeviceViewImpl1(QWidget *parent = nullptr);

  void setPeriod(const QString &text) override;
  QString getPeriod() override;

 private:
  QPushButton *_accept_button = nullptr;
  QLineEdit *_period_line_edit = nullptr;

  void initUI();
  void setConnections();

 private slots:
  void acceptButtonClicked();
};

#endif //CPP_PROJECT_TEMPLATE_MVC_DEVICE_VIEWS_IMPLS_DEVICEVIEWIMPL1_H_
