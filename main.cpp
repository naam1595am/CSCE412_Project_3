#include "loadbalancer.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

std::string generateRandomIP() {
    return std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256) + "." +
           std::to_string(rand() % 256);
}

int main() {
    srand(time(0));
    int numServers, runTime, maxServers;

    std::cout << "Enter the number of minimum servers: ";
    std::cin >> numServers;
    std::cout << "Enter the number of maximum servers: ";
    std::cin >> maxServers;
    std::cout << "Enter the time to run the load balancer: ";
    std::cin >> runTime;

    // Open a file to log the output
    std::ofstream logFile("loadbalancer_log.txt");

    if (!logFile.is_open()) {
        std::cerr << "Failed to open log file." << std::endl;
        return 1;
    }

    // Create a LoadBalancer object with both console and file logging
    LoadBalancer lb(numServers, maxServers, numServers * 100, logFile);

    // Redirect std::cout to logFile to log both to console and file
    std::streambuf *coutbuf = std::cout.rdbuf(); // Save old buf
    std::cout.rdbuf(logFile.rdbuf()); // Redirect std::cout to logFile

    // Log starting queue size
    std::cout << "Starting queue size: " << numServers * 100 << std::endl;

    // Log task time range
    std::cout << "Task time range: 1-10" << std::endl;

    // Initial requests
    for (int i = 0; i < numServers * 100; ++i) {
        lb.addRequest(Request(generateRandomIP(), generateRandomIP(), rand() % 10 + 1));
    }

    // Run the load balancer for the specified clock cycles
    for (int cycle = 0; cycle < runTime; ++cycle) {
        lb.distributeRequests();
        lb.manageServers();
        if (rand() % 5 == 0) {
            lb.addRequest(Request(generateRandomIP(), generateRandomIP(), rand() % 10 + 1));
        }
        lb.balanceLoad();
    }

    // Log ending queue size
    std::cout << "Ending queue size: " << lb.getQueueSize() << std::endl;

    // Restore std::cout buffer
    std::cout.rdbuf(coutbuf); // Reset to standard output again
    logFile.close();
    return 0;
}

