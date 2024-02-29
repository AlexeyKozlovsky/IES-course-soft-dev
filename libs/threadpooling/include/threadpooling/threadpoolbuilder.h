#ifndef TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_THREADPOOLBUILDER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_THREADPOOLBUILDER_H_

#include <string>
#include <memory>

#include "threadpooling/threadpool.h"
#include "threadpooling/threadpooltask.h"


class ThreadPoolBuilder {
 public:
  virtual std::shared_ptr<ThreadPool> createBase(int threads_count) = 0;
  virtual std::shared_ptr<ThreadPool> setThreadsCount(int threads_count) = 0;
  virtual std::shared_ptr<ThreadPool> addTask(const std::shared_ptr<IProcessable> &periodic_task,
                                              const std::string &task_uid,
                                              int period_in_ms) = 0;
  virtual std::shared_ptr<ThreadPool> removeTask(const std::string &task_uid) = 0;
  virtual std::shared_ptr<ThreadPool> getThreadPool() = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_SERVICES_MODELS_IMPLS_STANDALONEIMPL_BACKGROUND_THREADPOOLBUILDER_H_
