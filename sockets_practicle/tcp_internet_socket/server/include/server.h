#ifndef SERVER_H
#define SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <iostream>

using namespace std;

class Server{
    private:
    int serverSocket;
    sockaddr_in serverAddress;

    void handlerClient(int);
    string receive_data(int);
    void response_data(const char *, int, int);
    
    public:
    Server(int);
    ~Server();
    void new_connection();
};

#endif