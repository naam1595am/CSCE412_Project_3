Project 3: Load Balancer Simulation
Overview
This project simulates a load balancer managing web requests for a large company. The load balancer distributes incoming web requests to multiple web servers to ensure efficient processing and to prevent any single server from becoming overloaded. The simulation runs for a specified number of clock cycles and logs important events and metrics.

Key Features
Random Request Generation: The simulation generates web requests with random source and destination IP addresses and random processing times.
Dynamic Server Management: The load balancer dynamically allocates and deallocates servers based on the load to maintain efficiency.
Queue Management: Requests are stored in a queue before being distributed to the servers for processing.
Logging: The simulation logs important events such as request additions, server allocations, request processing, and server deallocations to both the console and a log file.
Inputs
The simulation prompts the user for the following inputs:

Minimum number of servers: The initial number of servers available for processing requests.
Maximum number of servers: The maximum number of servers that can be allocated dynamically based on the load.
Runtime (in clock cycles): The duration for which the simulation will run.
Outputs
Starting Queue Size: The size of the request queue at the start of the simulation.
Ending Queue Size: The size of the request queue at the end of the simulation.
Task Time Range: The range of processing times for the tasks (1 to 10 clock cycles).
Logging
The simulation logs the following events to a file named loadbalancer_log.txt:

Addition of new requests to the queue.
Allocation of new servers when the load increases.
Deallocation of servers when the load decreases.
Processing of requests by the servers.
How to Run the Simulation
Compile the Program:
sh
Copy code
g++ -std=c++11 src/request.cpp src/webserver.cpp src/loadbalancer.cpp src/requestqueue.cpp main.cpp -Iinclude -o loadbalancer
Run the Program:
sh
Copy code
./loadbalancer
Provide Inputs:
mathematica
Copy code
Enter the number of minimum servers: 10
Enter the number of maximum servers: 10
Enter the time to run the load balancer: 10000
Example Log Entries
The log file loadbalancer_log.txt will contain entries such as:

arduino
Copy code
Starting queue size: 1000
Task time range: 1-10
Request added: 192.168.1.1 -> 192.168.1.2 | Time: 5
...
Server processing request: 192.168.1.3 -> 192.168.1.4
...
Ending queue size: [final queue size]


Summary
This simulation provides a basic model of how a load balancer works in a networked environment, handling dynamic loads and ensuring efficient processing of web requests. The project demonstrates the use of queues, dynamic memory allocation, and logging in a simulated network environment.