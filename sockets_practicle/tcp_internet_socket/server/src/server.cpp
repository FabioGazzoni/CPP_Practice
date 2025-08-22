#include "server.h"
#include <exception>
#include <cstring>
#include <thread>

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

    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        throw runtime_error("Error en bind server");
    }
}

void Server::new_connection()
{
    if (listen(serverSocket, 5))
    {
        throw runtime_error("Listen error");
    }

    while (1)
    {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket < 0)
        {

            throw runtime_error("Accept connection server error");
        }

        std::thread([clientSocket, this]()
                    { this->handlerClient(clientSocket); })
            .detach(); // thread separado y “desprendido”
    }
}

void Server::handlerClient(int clientSocket)
{
    string message;
    while (1)
    {
        message = receive_data(clientSocket);
        if (message == "exit")
        {
            close(clientSocket);
            break;
        }
        cout << "Message from client: " << message << endl;
        response_data("Hola", strlen("Hola"), clientSocket);
    }
}

string Server::receive_data(int clientSocket)
{
    char buffer[1024] = {0};
    ssize_t err = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (err < 0)
    {
        throw runtime_error("recv to client error");
    }
    else if (err == 0)
    {
        return "exit";
    }
    return string(buffer);
}

void Server::response_data(const char *data, int len, int clientSocket)
{
    if (send(clientSocket, data, len, 0) < 0)
    {
        throw runtime_error("Send message to client error");
    }
}

Server::~Server()
{
    if (serverSocket != -1)
        close(serverSocket);
}
