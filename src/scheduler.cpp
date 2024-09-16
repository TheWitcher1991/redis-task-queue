#include "include/scheduler.h"
#include <iostream>

Scheduler::Scheduler(size_t pool_size, const std::string &host, int port) : pool(pool_size), broker(host, port) {}

void Scheduler::schedule(const Task &task, std::chrono::milliseconds delay) {
    auto times = std::chrono::steady_clock::now() + delay;
    scheduledTasks.insert({
        times, task
    });
}

void Scheduler::run() {
    while (true) {
        auto now = std::chrono::steady_clock::now();

        while (!scheduledTasks.empty() && scheduledTasks.begin()->first <= now) {
            auto task = scheduledTasks.begin()->second;
            scheduledTasks.erase(scheduledTasks.begin());
            pool.enqueue(task);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void Scheduler::dispatch(const std::string &taskName, Task::TaskFunc taskFunc) {
    pool.enqueue([taskName, taskFunc] {
        Task task(taskName, taskFunc);
        task.apply();
    });
}

void Scheduler::execute(const std::string &queue) {
    while (true) {
        std::string data = broker.pop(queue);
        if (data.empty()) {
            std::cout << "Queue is empty" << std::endl;
            break;
        }
    }
}
