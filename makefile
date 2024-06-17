# Define the compiler and the flags
CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

# Define the source and header files
SRCS = request.cpp webserver.cpp loadbalancer.cpp requestQueue.cpp main.cpp
HEADERS = request.h webserver.h loadbalancer.h requestQueue.h

# Define the output executable
TARGET = loadbalancer

# Default target to build the project
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean the build files
clean:
	rm -f $(TARGET) *.o

# Phony targets
.PHONY: all clean
