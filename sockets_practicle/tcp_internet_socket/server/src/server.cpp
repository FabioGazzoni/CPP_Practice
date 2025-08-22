#include "server.h"
#include <exception>
#include <cstring>

Server::Server(int port)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        throw runtime_error("Socket mal inicializado");
    }
    
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    if(bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0){
        throw runtime_error("Error en bind server");
    }
}

void Server::new_connection()
{
    if(listen(serverSocket, 5)){
        throw runtime_error("Listen error");
    }

    clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket < 0)
    {
        throw runtime_error("Accept connection server error");
    }
    
}

void Server::receive_data(){
    char buffer[1024] = {0};
    if(recv(clientSocket, buffer, sizeof(buffer), 0) < 0){
        throw runtime_error("recv to client error");
    }
    cout << "Message from client: " << buffer<< endl;
}

void Server::response_data(const char *data, int len){
    if(send(clientSocket, data, len, 0) < 0){
        throw runtime_error("Send message to client error");
    }
}

Server::~Server()
{
    if(serverSocket != -1) close(serverSocket);
    if(clientSocket != -1) close(clientSocket);
}
