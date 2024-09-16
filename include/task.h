#ifndef TASK_H
#define TASK_H

#include <functional>
#include <string>
#include <memory>

// V1

class Task {
public:
    using TaskFunc = std::function<void()>;

    Task(const std::string &name, TaskFunc taskFunc, int retry = 3);

    const std::string &getName() const;

    void apply();
    void retry();

    bool shouldRetry() const;
    void increaseRetry();
private:
    std::string name;
    TaskFunc taskFunc;
    int max_retry = 3;
    int retry;
}

#endif // TASK_H
