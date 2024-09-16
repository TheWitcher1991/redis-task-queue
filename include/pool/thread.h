#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <include/task.h>

class ThreadPool {
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();

    void enqueue(Task task);
private:
    std::vector<std::thread> workers;
    std::queue<Task> tasks;
    std::mutex tasks_mutex;
    std::condition_variable tasks_condition;
    bool stop;

    void worker();
}

#endif // THREADPOOL_H
