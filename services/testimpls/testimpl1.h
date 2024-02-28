#ifndef CPP_PROJECT_TEMPLATE_SERVICES_TESTIMPLS_TESTIMPL1_H_
#define CPP_PROJECT_TEMPLATE_SERVICES_TESTIMPLS_TESTIMPL1_H_

#include "services/test.h"
#include "services/task.h"


class TestImpl1: public Test, public Task {
 public:
  void someMethod() override;
  void solve() override;
};

#endif //CPP_PROJECT_TEMPLATE_SERVICES_TESTIMPLS_TESTIMPL1_H_
