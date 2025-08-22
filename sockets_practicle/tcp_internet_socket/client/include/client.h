#ifndef CLIENT_H
#define CLIENT_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace std;

class Client{
    private:
        int clientSocket ;
        sockaddr_in serverAddress;
    public:
        Client(int port);
        ~Client();
        void new_connection();
        void send_message(string);
        void receive_message();
};

#endif // CLIENT_H