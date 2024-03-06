#ifndef CPP_PROJECT_TEMPLATE_THREADPOOL_THREADPOOL_H_
#define CPP_PROJECT_TEMPLATE_THREADPOOL_THREADPOOL_H_

#include <vector>
#include <thread>
#include <deque>
#include <atomic>

#include "command/command.h"


class ThreadPool {
 public:
  explicit ThreadPool(int threads_count);

  void addTask(const std::shared_ptr<Command> &task);

  void process();

  void start();
  void stop();

 private:
  std::deque<std::shared_ptr<Command>> _task_queue;

  std::vector<std::thread> _threads;
  std::thread _background_thread;

  std::atomic<bool> _is_started = false;
};

#endif //CPP_PROJECT_TEMPLATE_THREADPOOL_THREADPOOL_H_
