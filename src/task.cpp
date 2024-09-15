#include "task.h"

Task::Task(std::function<void()> f) : func(f) {}

void Task::apply() {
    func();
}
