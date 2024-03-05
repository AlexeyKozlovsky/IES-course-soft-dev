#include "logger.h"

#include <QDebug>

void Logger::printLog() {
  qDebug() << "LOG PRINTED " << __func__;
}

void Logger::update() {
  printLog();
}
