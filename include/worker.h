#ifndef WORKER_H
#define WORKER_H

#include <thread>
#include "include/queue.h"


class Worker {
public:
    Worker(Queue &queue);

    void run();
    void stop();

private:
    Queue &queue;
    bool running;
}


#endif // WORKER_H
