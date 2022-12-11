#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

sem_t chop[5];
char status[6] = {'-', '-', '-', '-', '-'};

void printStatus()
{
    printf("\n");
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("  %c ", status[i]);
    }
}

void *philosopher(void *args)
{

    long int num = (long int)args;
    status[num] = 'H';
    printStatus();

    sem_wait(&chop[num]);
    sem_wait(&chop[(num + 1) % 5]);
    status[num] = 'E';
    printStatus();
    sleep(1);

    sem_post(&chop[(num + 1) % 5]);
    sem_post(&chop[num]);

    status[num] = 'T';
    printStatus();

    pthread_exit(NULL);
}

int main()
{

    long int i, j;
    pthread_t phil[5];
    for (i = 0; i < 5; i++)
    {
        sem_init(&chop[i], 0, 1);
    }
    for (i = 0; i < 5; i++)
    {
        printf(" p[%ld]", i);
    }
    for (i = 0; i < 5; i++)
    {
        pthread_create(&phil[i], NULL, philosopher, (void *)i);
    }

    for (j = 0; j < 5; j++)
    {
        pthread_join(phil[j], NULL);
    }

    return 0;
}