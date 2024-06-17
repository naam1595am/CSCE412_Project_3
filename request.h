#ifndef REQUEST_H
#define REQUEST_H

#include <string>
using namespace std;

class Request {
private:
    string IP_in;
    string IP_out;
    int time;
public:
    Request(std::string ipIn, std::string ipOut, int t);
    string getIPin() const;
    string getIPout() const;
    int getTime() const;
    void setTime(int t);
};

#endif
