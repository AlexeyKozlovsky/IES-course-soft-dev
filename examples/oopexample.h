#ifndef CPP_PROJECT_TEMPLATE_EXAMPLES_OOPEXAMPLE_H_
#define CPP_PROJECT_TEMPLATE_EXAMPLES_OOPEXAMPLE_H_

// Структура. По сти класс, у которого по умолчанию модификаторы доступа Public
struct ExampleStruct {
  int x = 0;
  int y = 0;
};


// Интерфейс. По сути класс, у которого все методы чисто виртуальные
class ExampleClassInterface {
 public:
  virtual int foo(int param) = 0;
};


// Класс. По сути, класс )
class ExampleClass: public ExampleClassInterface {
 public:
  int foo(int param) override;
  int someMethod();

 private:
  int _some_value = 0;
  ExampleStruct _example_struct;
};

#endif //CPP_PROJECT_TEMPLATE_EXAMPLES_OOPEXAMPLE_H_
