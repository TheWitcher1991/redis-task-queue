include "include/mechanism.h"

bool Mechanism::shouldRetry(Task &task) {
    if (task.shouldRetry()) {
        task.increaseRetry();
        return true;
    }
    return false;
}
