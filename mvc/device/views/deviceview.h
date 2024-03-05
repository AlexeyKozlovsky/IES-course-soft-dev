#ifndef CPP_PROJECT_TEMPLATE_MVC_DEVICE_VIEWS_DEVICEVIEW_H_
#define CPP_PROJECT_TEMPLATE_MVC_DEVICE_VIEWS_DEVICEVIEW_H_

#include <QString>

#include <QWidget>


class DeviceView: public QWidget {
  Q_OBJECT
 public:
  explicit DeviceView(QWidget *parent = nullptr);

  virtual void setPeriod(const QString &text) = 0;
  virtual QString getPeriod() = 0;

 signals:
  void periodChangedSignal(const QString &period);
};

#endif //CPP_PROJECT_TEMPLATE_MVC_DEVICE_VIEWS_DEVICEVIEW_H_
