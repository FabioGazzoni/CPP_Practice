#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define IP_SERVER "127.0.0.1"
#define PORT 8080
#define END_CONNECT_MESAG "exit"
#define SIZE_BUFFER 1024

typedef struct
{
    char *message;
    int size;
} socket_message;

bool send_message(int fd_client, pthread_mutex_t *print_mutex);
socket_message recibe_message(int fd_client);
socket_message create_message(const char *message);
bool is_exit(socket_message s_message);
void end_connection(int fd);

#endif //UTILS_H
