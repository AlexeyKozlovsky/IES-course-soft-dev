#ifndef TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_IMPLS_PERIODIC_PERIODICTASK_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_IMPLS_PERIODIC_PERIODICTASK_H_

#include <atomic>
#include <memory>
#include <chrono>
#include <mutex>

#include "threadpooling/threadpooltask.h"


class PeriodicTask: public ThreadPoolTask {
 public:
  explicit PeriodicTask(const std::shared_ptr<IProcessable> &processable, std::chrono::system_clock::duration period);
  virtual ~PeriodicTask() = default;

  void process() override;

  void setBusy(bool busy) override;
  bool isReady() override;

  bool setPeriod(int period_in_ms);

 private:
  std::atomic<bool> _is_busy{false};
  std::shared_ptr<IProcessable> _processable = nullptr;

  std::chrono::system_clock::time_point _last_time_processed;
  std::chrono::system_clock::duration _period;

  std::mutex _mutex;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_IMPLS_PERIODIC_PERIODICTASK_H_
