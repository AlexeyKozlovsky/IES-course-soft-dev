#ifndef TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_WORKINGTHREAD_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_WORKINGTHREAD_H_

#include <memory>
#include <string>

#include "iprocessable.h"


class WorkingThread {
 public:
  virtual bool start() = 0;
  virtual void stop() = 0;
  virtual bool isRunning() = 0;
  virtual int getTasksCount() = 0;

  virtual void addTask(const std::string &task_id, const std::shared_ptr<IProcessable> &task) = 0;
  virtual void removeTask(const std::string &task_id) = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_WORKINGTHREAD_H_
