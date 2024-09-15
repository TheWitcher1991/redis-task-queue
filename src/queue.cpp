#include "queue.h"

void Queue::push(Task task) {
    std::lock_guard<std::mutex> lock(mutex);
    tasks.push(task);
    cv.notify_one();
}

void Queue::shutdown() {
    {
        std::lock_guard<std::mutex> lock(mutex);
        is_shutdown = true;
    }
    cv.notify_all();
    return tasks.empty();
}

void Queue::pop() {
    std::lock_guard<std::mutex> lock(mutex);
    cv.wait(lock, [this]() { return !tasks.empty() || is_shutdown; }
    if (tasks.empty()) {
        return nullptr;
    }

    auto task = tasks.front();
    tasks.pop();
    return task;
}
