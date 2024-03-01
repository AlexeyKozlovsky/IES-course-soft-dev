#ifndef TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOLBUILDERPERIODICIMPL_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOLBUILDERPERIODICIMPL_H_

#include <utils/services/uidgenerator.h>

#include "threadpooling/threadpoolbuilder.h"
#include "threadpoolperiodicimpl.h"

class ThreadPoolPeriodicImplBuilder: public ThreadPoolBuilder {
 public:
  explicit ThreadPoolPeriodicImplBuilder(const std::shared_ptr<UIDGenerator> &uid_generator);
  virtual ~ThreadPoolPeriodicImplBuilder() = default;

  void setThreadBuilderSleep(int sleep_in_ms);

  std::shared_ptr<ThreadPool> createBase(int threads_count) override;
  std::shared_ptr<ThreadPool> setThreadsCount(int threads_count) override;
  std::shared_ptr<ThreadPool> addTask(const std::shared_ptr<IProcessable> &periodic_task,
                                      const std::string &task_uid,
                                      int period_in_ms) override;
  std::shared_ptr<ThreadPool> removeTask(const std::string &task_uid) override;
  std::shared_ptr<ThreadPool> getThreadPool() override;

 private:
  int _threads_count = 0;
  int _sleep_in_ms = 0;

  std::shared_ptr<ThreadPoolPeriodicImpl> _thread_pool = nullptr;
  std::shared_ptr<UIDGenerator> _uid_generator = nullptr;

  void clear();
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOLBUILDERPERIODICIMPL_H_
