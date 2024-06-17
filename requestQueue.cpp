#include "requestqueue.h"

RequestQueue::RequestQueue(int size) : maxSize(size) {}

void RequestQueue::enqueue(Request req) {
    if(queue.size() < maxSize) {
        queue.push(req);
    }
}

Request RequestQueue::dequeue() {
    if(!queue.empty()) {
        Request req = queue.front();
        queue.pop();
        return req;
    }
    return Request("", "", 0); // Return an empty request if queue is empty
}

bool RequestQueue::isEmpty() const {
    return queue.empty();
}

bool RequestQueue::isFull() const {
    return queue.size() == maxSize;
}

int RequestQueue::size() const {
    return queue.size();
}
