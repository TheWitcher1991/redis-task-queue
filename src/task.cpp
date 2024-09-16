#include "task.h"

Task::Task(const std::string &name, TaskFunc taskFunc, int retry) : name(name), taskFunc(taskFunc), retry(0) {}

void Task::apply() {
    try {
        taskFunc();
    } catch(std::exception &e) {
        retry();
    }
}

void Task::retry() {
    if (retry > 0 && retry <= max_retry) {
        retry--;
        apply();
    } else {
        std::cout << "Task " << name << " failed" << std::endl;
    }
}

const std::string &Task::getName() const {
    return name;
}

bool Task::shouldRetry() const {
    return retry <= max_retry;
}

void Task::increaseRetry() {
    retry++;
}
