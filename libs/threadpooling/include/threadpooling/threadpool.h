#ifndef TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOL_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOL_H_

#include <vector>

#include "iprocessable.h"
#include "threadpooltask.h"


class ThreadPool: public IProcessable {
 public:
  virtual bool start() = 0;
  virtual void stop() = 0;

  virtual bool isRunning() = 0;

  virtual void addTask(const std::string &task_uid, const std::shared_ptr<ThreadPoolTask> &thread_pool_task) = 0;
  virtual std::shared_ptr<ThreadPoolTask> getTask(const std::string &uid) = 0;
  virtual void removeTask(const std::string &task_uid) = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOL_H_
