

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t mutex, wrt;
int a = 0;
int readerNo = 0;
void *reader(void *arg)
{
    long int num;
    num = (long int)arg;
    pthread_mutex_lock(&mutex);
    readerNo++;
    pthread_mutex_unlock(&mutex);
    if (readerNo == 1)
    {
        pthread_mutex_lock(&wrt);
    }
    printf("Reader %d is in critical section. \n", num);
    sleep(1);
    pthread_mutex_lock(&mutex);
    readerNo--;
    pthread_mutex_unlock(&mutex);
    if (readerNo == 0)
    {
        pthread_mutex_unlock(&wrt);
    }
    printf("Reader %d left critical section. \n", num);
}
void *writer(void *arg)
{
    long int num;
    num = (long int)arg;
    pthread_mutex_lock(&wrt);

    a++;
    printf("writer %d modified data to %d. \n", num, a);
    sleep(1);
    pthread_mutex_unlock(&wrt);
}
int main()
{
    pthread_t r[10], w[10];
    long int i, j;
    int rN, wN;

    printf("Enter number of readers and writers : ");
    scanf("%d", &rN);
    scanf("%d", &wN);

    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&wrt, NULL);

    for (i = 0; i < rN; i++)
    {
        pthread_create(&r[i], NULL, reader, (void *)i);
    }
    for (j = 0; j < wN; j++)
    {
        pthread_create(&w[j], NULL, writer, (void *)j);
    }

    for (i = 0; i < rN; i++)
    {
        pthread_join(w[j], NULL);
    }
    for (j = 0; j < wN; j++)
    {
        pthread_join(w[j], NULL);
    }

    return 0;
}