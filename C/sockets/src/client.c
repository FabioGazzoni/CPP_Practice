#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#include "inc/utils.h"


struct sockaddr_in serv_addr;

/**
 * Init socket client
 * @return fd_socket_client
 */
int init_client()
{
    serv_addr.sin_family = AF_INET;
    
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        perror("Socket creation error\n");
        exit(EXIT_FAILURE);
    }
    serv_addr.sin_addr.s_addr = inet_addr(IP_SERVER);
    serv_addr.sin_port = htons(PORT);

    if (connect(client_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) != 0)
    {
        perror("Socket conection error\n");
        end_connection(client_fd);
        exit(EXIT_FAILURE);
    }

    return client_fd;
}
