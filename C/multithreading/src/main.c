#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define PLACES_N 4
#define CONSUMERS_TH 3
#define PRODUCERS_TH 3
#define MIN_T_US 10000
#define MAX_T_US 50000
#define STEPS 100

bool free_places[PLACES_N];
pthread_t consumers[CONSUMERS_TH];
pthread_t producers[PRODUCERS_TH];
pthread_mutex_t mutex;
int steps = STEPS;

void *consumer(void *arg);
void *producer(void *arg);
void print_status();
void init_threads();

int main()
{
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    init_threads();
    printf("Finish program");
    return 0;
}

void init_threads()
{
    for (int i = 0; i < PLACES_N; i++)
    {
        free_places[i] = true;
    }

    for (int i = 0; i < CONSUMERS_TH; i++)
    {
        pthread_create(&consumers[i], NULL, consumer, NULL);
    }

    for (int i = 0; i < CONSUMERS_TH; i++)
    {
        pthread_create(&producers[i], NULL, producer, NULL);
    }

    for (int i = 0; i < CONSUMERS_TH; i++)
    {
        pthread_join(consumers[i], NULL);
    }

    for (int i = 0; i < PRODUCERS_TH; i++)
    {
        pthread_join(producers[i], NULL);
    }
}

void *consumer(void *arg)
{
    while (steps > 0)
    {
        pthread_t self_th = pthread_self();
        bool take = false;
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < PLACES_N; i++)
        {
            if (free_places[i] == false)
            {
                free_places[i] = true;
                take = true;
                break;
            }
        }
        if (take)
        {
            printf("Consumer Thread-%lu: ", self_th);
            print_status();
            steps--;
        }
        pthread_mutex_unlock(&mutex);

        usleep(rand() % (MAX_T_US - MIN_T_US + 1) + MIN_T_US);
    }
    return NULL;
}

void *producer(void *arg)
{
    while (steps > 0)
    {
        pthread_t self_th = pthread_self();
        bool take = false;
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < PLACES_N; i++)
        {
            if (free_places[i] == true)
            {
                free_places[i] = false;
                take = true;
                break;
            }
        }
        if (take)
        {
            printf("Producer Thread-%lu: ", self_th);
            print_status();
            steps--;
        }
        pthread_mutex_unlock(&mutex);

        usleep(rand() % (MAX_T_US - MIN_T_US + 1) + MIN_T_US);
    }
    return NULL;
}

void print_status()
{
    printf("[");
    for (int i = 0; i < PLACES_N - 1; i++)
    {
        printf("%d, ", (int)free_places[i]);
    }

    printf("%d]\n", free_places[PLACES_N - 1]);
}
