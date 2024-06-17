#include "request.h"

Request::Request(string ipIn, string ipOut, int t) : IP_in(ipIn), IP_out(ipOut), time(t) {}

string Request::getIPin() const { return IP_in; }
string Request::getIPout() const { return IP_out; }
int Request::getTime() const { return time; }
void Request::setTime(int t) { time = t; }
