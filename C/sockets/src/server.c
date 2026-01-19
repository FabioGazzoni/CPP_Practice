#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "inc/utils.h"

struct sockaddr_in addr;

int init_server()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    int addr_len = sizeof(addr);
    if (server_fd == -1)
    {
        perror("Socket creation error\n");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(IP_SERVER);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Error to associate port\n");
        end_connection(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("New conection error");
        end_connection(server_fd);
        exit(EXIT_FAILURE);
    }

    int new_socket = accept(server_fd, (struct sockaddr *)&addr, (socklen_t *)&addr_len);
    if (new_socket < 0)
    {
        perror("Error accept new connection\n");
        end_connection(server_fd);
        exit(EXIT_FAILURE);
    }

    return new_socket;
}
