#include "server.c"
#include "inc/utils.h"
#include <string.h>
#include <signal.h>
#include <pthread.h>

void exit_sign(int signal);
void *server_rx(void *arg);
void *server_tx(void *arg);

int server_fd;

pthread_mutex_t print_mutex;

int main(int argc, char const *argv[])
{
    signal(SIGINT, exit_sign);
    server_fd = init_server();

    pthread_t rx_thread;
    pthread_t tx_thread;

    pthread_mutex_init(&print_mutex, NULL);

    pthread_create(&rx_thread, NULL, server_rx, NULL);
    pthread_create(&tx_thread, NULL, server_tx, NULL);

    pthread_join(rx_thread, NULL);
    pthread_cancel(tx_thread);
    pthread_join(tx_thread, NULL);

    pthread_mutex_destroy(&print_mutex);
    return 0;
}

void *server_rx(void *arg)
{
    while (1)
    {
        socket_message message_rec = recibe_message(server_fd);

        pthread_mutex_lock(&print_mutex);
        printf("\x1b[2K\r"); // Clean the current terminal line and carriage return
        printf("%s->", message_rec.message);
        fflush(stdout);
        pthread_mutex_unlock(&print_mutex);
        if (is_exit(message_rec))
        {
            break;
        }
        free(message_rec.message);
    }

    end_connection(server_fd);

    return NULL;
}

void *server_tx(void *arg)
{
    while (1)
    {
        if (send_message(server_fd, &print_mutex))
        {
            break;
        }
    }

    return NULL;
}

void exit_sign(int signal)
{
    end_connection(server_fd);
    exit(EXIT_SUCCESS);
}
