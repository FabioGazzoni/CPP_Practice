#include "client.h"
#include <cstring>
#include <exception>
#include <arpa/inet.h>

Client::Client(int port)
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1)
    {
        throw runtime_error("Socket mal inicializado");
    }
    
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    if(inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) < 0){
        throw runtime_error("Dirección IP inválida o no soportada");
    }
}

void Client::new_connection()
{
    if(connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1){
        throw runtime_error("Error al conectar con el servidor");
    }
}

void Client::send_message(string message){
    
    if(send(clientSocket, message.c_str(), message.size(), 0) == -1){
        throw runtime_error("Error al enviar el mensaje al servidor");
    }
}

void Client::receive_message(){
    char buffer[1024] = {0};
    if(recv(clientSocket, buffer, sizeof(buffer), 0) == -1){
        throw runtime_error("Error al recibir la respuesta del servidor");
    }
    cout << "Message from server: " << buffer<< endl;
}

Client::~Client()
{
    if(clientSocket != -1) close(clientSocket);
}