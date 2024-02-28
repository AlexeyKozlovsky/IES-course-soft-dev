#ifndef CPP_PROJECT_TEMPLATE_SERVICES_TESTCLASS_H_
#define CPP_PROJECT_TEMPLATE_SERVICES_TESTCLASS_H_

class TestClass {
 public:
  explicit TestClass(int a);
  void printSomething();

 private:
  int _a = 0;
  int _d = 0;

  void someLogic();
};

#endif //CPP_PROJECT_TEMPLATE_SERVICES_TESTCLASS_H_
