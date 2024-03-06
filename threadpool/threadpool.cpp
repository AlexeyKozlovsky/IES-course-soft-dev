#include "threadpool.h"

ThreadPool::ThreadPool(int threads_count) {
  _threads.resize(threads_count);
}

void ThreadPool::addTask(const std::shared_ptr<Command> &task) {
  _task_queue.push_back(task);
}

void ThreadPool::start() {
  _is_started = true;
}
void ThreadPool::stop() {
  _is_started = false;
}

void ThreadPool::process() {
  while (_is_started) {
    // Тут логика распределения по потокам
  }
}
