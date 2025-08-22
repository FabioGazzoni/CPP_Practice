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
    int clientSocket;
    sockaddr_in serverAddress;

    public:
    Server(int);
    ~Server();
    void new_connection();
    void receive_data();
    void response_data(const char *, int);
};

#endif