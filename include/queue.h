#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "task.h"

class Queue {
private:
    std::queue<Task> tasks;
    std::mutex mutex;
    std::condition_variable cv;
    bool is_shutdown;

public:
    void push(Task task);
    Task pop();
    bool shutdown();
}

#endif // TASK_QUEUE_H
