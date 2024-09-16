#include "include/worker.h"
#include <iostream>
#include <chrono>


Worker::Worker(Queue &queue) : queue(queue), running(true) {}

void Worker::run() {
    while (running) {
        if (!queue.empty()) {
            Task task = queue.pop();
            try {
                task.apply();
            } catch (const std::exception &e) {
                std::cerr << e.what() << std::endl;
                queue.push(task);
            }
        }
    }
}

void Worker::stop() {
    running = false;
}
