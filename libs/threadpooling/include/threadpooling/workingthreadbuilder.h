#ifndef TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_WORKINGTHREADBUILDER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_WORKINGTHREADBUILDER_H_

#include <memory>

#include "workingthread.h"


class WorkingThreadBuilder {
 public:
  virtual const std::shared_ptr<WorkingThread> &createBase();
  virtual const std::shared_ptr<WorkingThread> &addTask(const std::shared_ptr<IProcessable> &task,
                                                        std::string &task_name) = 0;
  virtual const std::shared_ptr<WorkingThread> &removeTask(const std::string &task_name) = 0;
  virtual const std::shared_ptr<WorkingThread> &getResult() = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_WORKINGTHREADBUILDER_H_
