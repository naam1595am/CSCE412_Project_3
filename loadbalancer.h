#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "webserver.h"
#include "requestqueue.h"
#include <vector>
#include <ostream>

class LoadBalancer {
private:
    std::vector<WebServer*> servers;
    RequestQueue requestQueue;
    int minServers;
    int maxServers;
    std::ostream& logStream; // Reference to the log stream
public:
    LoadBalancer(int minServers, int maxServers, int queueSize, std::ostream& logStream);
    ~LoadBalancer();
    void manageServers();
    void distributeRequests();
    void addRequest(Request req);
    void removeRequest();
    void balanceLoad();
    void allocateServer();
    void deallocateServer();
    int getQueueSize() const; // New method to get current queue size
};

#endif

