#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "include/pool/thread.h"
#include "include/task.h"
#include "include/redis/client.h"
#include <string>
#include <chrono>


class Scheduler {
public:
    Scheduler(size_t pool_size, const std::string &host, int port);

    void schedule(const Task &task, std::chrono::milliseconds delay);
    void run()

    void dispatch(const std::string &taskName, Task::TaskFunc taskFunc);
    void execute(const std::string &queue);

private:
    ThreadPool *pool;
    RedisClient *broker;
    std::multimap<std::chrono::time_point<std::chrono::steady_clock>, Task> scheduledTasks;
}


#endif // SCHEDULER_H
