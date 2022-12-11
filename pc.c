#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

sem_t empty, full;
int buffer[5];
int count = 0;
pthread_mutex_t mutex;

void *producer(void *args)
{
    long int num = (long int)args;

    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[count] = (rand() % 10);
    printf("Producer %d produced %d\n", num + 1, buffer[count]);
    count++;
    sleep(1);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void *consumer(void *args)
{
    long int num = (long int)args;

    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    count--;
    printf("consumer %d consumed %d\n", num + 1, buffer[count]);
    sleep(1);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main()
{
    pthread_t p[10], c[10];
    int nP, nC;
    long int i, j;
    printf("Enter number of producers:\n ");
    scanf("%d", &nP);
    printf("Enter number of producers: \n");
    scanf("%d", &nC);

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);

    for (i = 0; i < nP; i++)
    {
        pthread_create(&p[i], NULL, producer, (void *)i);
    }

    for (j = 0; j < nC; j++)
    {
        pthread_create(&c[j], NULL, consumer, (void *)j);
    }
    for (i = 0; i < nP; i++)
    {
        pthread_join(p[i], NULL);
    }
    for (j = 0; j < nC; j++)
    {
        pthread_join(c[j], NULL);
    }

    return 0;
}