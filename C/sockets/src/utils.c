#include "inc/utils.h"

bool send_message(int fd_client, pthread_mutex_t *print_mutex)
{
    char message[SIZE_BUFFER];
    memset(message, '\0', SIZE_BUFFER);
    pthread_mutex_lock(print_mutex);
    printf("->");
    pthread_mutex_unlock(print_mutex);
    fflush(stdout);
    fgets(message, sizeof(message), stdin);
    socket_message s_message = create_message(message);
    if (send(fd_client, s_message.message, s_message.size, 0) <= 0)
    {
        free(s_message.message);
        perror("Send message client to server error\n");
        exit(EXIT_FAILURE);
    }

    if (is_exit(s_message))
    {
        return true;
    }
    
    free(s_message.message);
    return false;
}

socket_message recibe_message(int fd_client)
{
    socket_message rec_message;
    rec_message.size = SIZE_BUFFER * sizeof(char);
    rec_message.message = (char *)malloc(rec_message.size);
    memset(rec_message.message, '\0', rec_message.size);
    if (read(fd_client, rec_message.message, SIZE_BUFFER) <= 0)
    {
        perror("The connection to the server was lost\n");
        exit(EXIT_SUCCESS);
    }

    rec_message.size = strlen(rec_message.message) * sizeof(char);
    rec_message.message = realloc(rec_message.message, rec_message.size);
    if (rec_message.message == NULL)
    {
        perror("Error realloc to resize server message\n");
        exit(EXIT_FAILURE);
    }

    return rec_message;
}

socket_message create_message(const char *message)
{
    socket_message m;
    m.size = strlen(message) * sizeof(char);
    m.message = (char *)malloc(m.size);
    strcpy(m.message, message);
    return m;
}

void s_lowercase(socket_message *s_message)
{
    for (int i = 0; i < s_message->size; i++)
    {
        s_message->message[i] = tolower(s_message->message[i]);
    }
}

bool is_exit(socket_message s_message)
{
    s_lowercase(&s_message);
    if (s_message.size >= strlen(END_CONNECT_MESAG)){
        s_message.message[s_message.size - 1] = '\0';
        if (strcmp(s_message.message, END_CONNECT_MESAG) == 0)
            return true;
    }
    return false;
}

void end_connection(int fd){
    close(fd);
}
