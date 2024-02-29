#ifndef TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_IMPLS_PERIODICTASKTHREADPOOLING_THREADPOOLPERIODICTASK_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_IMPLS_PERIODICTASKTHREADPOOLING_THREADPOOLPERIODICTASK_H_

#include <atomic>
#include <map>
#include <thread>
#include <chrono>
#include <string>

#include "threadpooling/threadpool.h"
#include "threadpooling/threadpooltask.h"


class ThreadPoolPeriodicImpl: public ThreadPool {
 public:
  explicit ThreadPoolPeriodicImpl(int threads_count, std::chrono::system_clock::duration sleep_duration);
  virtual ~ThreadPoolPeriodicImpl();

  void process() override;

  bool start() override;
  void stop() override;

  bool isRunning() override;

  void addTask(const std::string &task_uid, const std::shared_ptr<ThreadPoolTask> &thread_pool_task) override;
  std::shared_ptr<ThreadPoolTask> getTask(const std::string &uid) override;
  void removeTask(const std::string &task_uid) override;

 private:
  int _threads_count = 0;
  std::atomic<bool> _is_running{false};
  std::map<std::string, std::shared_ptr<ThreadPoolTask>> _tasks;

  std::vector<std::thread> _threads;

  std::chrono::system_clock::duration _sleep_duration;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_IMPLS_PERIODICTASKTHREADPOOLING_THREADPOOLPERIODICTASK_H_
