#ifndef TASK_H
#define TASK_H

#include <functional>

// V1

class Task {
public:
    std::function<void()> func;
    Task(std::function<void()> func);
    void apply();
}

#endif // TASK_H
