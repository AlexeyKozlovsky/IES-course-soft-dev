#ifndef TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOLFACTORY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOLFACTORY_H_

#include <memory>

#include "threadpool.h"


class ThreadPoolFactory {
 public:
  virtual std::shared_ptr<ThreadPool> createThreadPool(int threads_count, int period_in_ms) = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_THREADPOOLING_THREADPOOLFACTORY_H_
