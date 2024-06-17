#include "loadbalancer.h"
#include <iostream>

LoadBalancer::LoadBalancer(int minServers, int maxServers, int queueSize, std::ostream& logStream)
    : requestQueue(queueSize), minServers(minServers), maxServers(maxServers), logStream(logStream) {
    for (int i = 0; i < minServers; ++i) {
        servers.push_back(new WebServer());
    }
}

LoadBalancer::~LoadBalancer() {
    for (auto server : servers) {
        delete server;
    }
}

void LoadBalancer::manageServers() {
    for (auto &server : servers) {
        if (server->requestNew() && !requestQueue.isEmpty()) {
            Request req = requestQueue.dequeue();
            server->processRequest(req);
            logStream << "Server processing request: " << req.getIPin() << " -> " << req.getIPout() << std::endl;
        }
    }
}

void LoadBalancer::distributeRequests() {
    for (auto &server : servers) {
        if (server->requestNew() && !requestQueue.isEmpty()) {
            Request req = requestQueue.dequeue();
            server->processRequest(req);
            logStream << "Server processing request: " << req.getIPin() << " -> " << req.getIPout() << std::endl;
        }
    }
}

void LoadBalancer::addRequest(Request req) {
    requestQueue.enqueue(req);
    logStream << "Request added: " << req.getIPin() << " -> " << req.getIPout() << " | Time: " << req.getTime() << std::endl;
    if (requestQueue.isFull() && servers.size() < maxServers) {
        allocateServer();
    }
}

void LoadBalancer::removeRequest() {
    if (!requestQueue.isEmpty()) {
        requestQueue.dequeue();
    }
}

void LoadBalancer::balanceLoad() {
    static size_t serverIndex = 0;
    if (!requestQueue.isEmpty()) {
        Request req = requestQueue.dequeue();
        servers[serverIndex]->processRequest(req);
        serverIndex = (serverIndex + 1) % servers.size();
    }
}

void LoadBalancer::allocateServer() {
    if (servers.size() < maxServers) {
        servers.push_back(new WebServer());
        logStream << "Allocated a new server. Total servers: " << servers.size() << std::endl;
    }
}

void LoadBalancer::deallocateServer() {
    if (servers.size() > minServers) {
        delete servers.back();
        servers.pop_back();
        logStream << "Deallocated a server. Total servers: " << servers.size() << std::endl;
    }
}

int LoadBalancer::getQueueSize() const {
    return requestQueue.size();
}
