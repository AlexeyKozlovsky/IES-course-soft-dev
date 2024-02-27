#ifndef CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDER_H_
#define CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDER_H_

#include <string>

/**
 * Интерфейс для абстракции DataProvider. Для того, чтобы его использовать, нужно прописать
 * 1. Реализацию этого интерфейса (класс, который будет реализовывать его)
 * 2. Фабрику для создания этого класса (по сути, реализацию интерфейса фабрики dataprovider.h
 *
 * В данном случае, это просто пример из головы. Абстракция должна отвечать за то, чтобы отдавать название статью.
 * Представим, что, например, у нас должна быть реализация, которая отдает название статьи с сайта. Для этого будет
 * отдельная реализация
 */
class DataProvider {
 public:
  virtual std::string getTitle() = 0;
};

#endif //CPP_PROJECT_TEMPLATE_SERVICES_DATAPROVIDER_H_
