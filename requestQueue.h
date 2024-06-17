#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "request.h"
#include <queue>

class RequestQueue {
private:
    std::queue<Request> queue;
    int maxSize;
public:
    RequestQueue(int size);
    void enqueue(Request req);
    Request dequeue();
    bool isEmpty() const;
    bool isFull() const;
    int size() const; // New method to get current queue size
};

#endif
