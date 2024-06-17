#include "webserver.h"

void WebServer::processRequest(Request& req) {
    // Simulate processing time by decreasing the request's time
    req.setTime(req.getTime() - 1);
}

bool WebServer::requestNew() {
    // Return true if the server is ready for a new request
    return true;
}
