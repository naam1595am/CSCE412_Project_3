#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"

class WebServer {
public:
    void processRequest(Request& req);
    bool requestNew();
};

#endif
