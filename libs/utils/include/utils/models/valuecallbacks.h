#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECALLBACKS_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECALLBACKS_H_

#include <QObject>

#include <utils/baseutils.h>

class ValueCallback: public QObject {
  Q_OBJECT
 public:
  explicit ValueCallback(QObject *parent = nullptr);

 signals:
  void statusChangedError(const QString &error_message);
  void deviceStateChanged(DeviceState device_state);
};


class BoolValueCallback: public ValueCallback {
  Q_OBJECT
 public:
  explicit BoolValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(bool value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(bool status);
};


class BoolValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit BoolValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<bool> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<bool> &status);
};


class UShortValueCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit UShortValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(quint16 value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(quint16 status);
};

class UShortValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit UShortValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<quint16> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<quint16> &status);
};

class ShortValueCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit ShortValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(qint16 value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(qint16 status);
};

class ShortValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit ShortValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<qint16> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<qint16> &status);
};


class ULongValueCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit ULongValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(quint32 value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(quint32 status);
};

class ULongValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit ULongValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<quint32> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<quint32> &status);
};


class LongValueCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit LongValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(qint32 value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(qint32 status);
};

class LongValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit LongValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<qint32> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<qint32> &status);
};

class ULong64ValueCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit ULong64ValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(quint64 value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(quint64 status);
};

class ULong64ValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit ULong64ValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<quint64> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<quint64> &status);
};

class Long64ValueCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit Long64ValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(qint64 value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(qint64 status);
};

class Long64ValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit Long64ValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<qint64> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<qint64> &status);
};


class StringValueCallback: public ValueCallback {
  Q_OBJECT
 public:
  explicit StringValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QString &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QString &status);
};

class StringValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit StringValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<QString> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<QString> &status);
};

class DoubleValueCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit DoubleValueCallback(QObject *parent = nullptr);
  virtual void pushEvent(double value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(double status);
};

class DoubleValuesCallback: public ValueCallback {
 Q_OBJECT
 public:
  explicit DoubleValuesCallback(QObject *parent = nullptr);
  virtual void pushEvent(const QVector<double> &value) {
    emit statusChanged(value);
  };

 signals:
  void statusChanged(const QVector<double> &status);
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_VALUECALLBACKS_H_
