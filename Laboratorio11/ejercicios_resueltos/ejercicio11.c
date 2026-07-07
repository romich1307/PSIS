// codigo11.c
#include <stdio.h>
#include <pthread.h>
#include <time.h>
int counter = 0;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
void *increment(void *arg)
{
    for (int i = 0; i < 1000; i++)
    {
        pthread_mutex_lock(&mtx);
        counter++;
        pthread_mutex_unlock(&mtx);
    }
    return NULL;
}
int main()
{
    pthread_t t1, t2;
    clock_t inicio = clock();
    for (int i = 0; i < 10000; i++)
    {
        counter = 0;
        pthread_create(&t1, NULL, increment, NULL);
        pthread_create(&t2, NULL, increment, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        if (counter != 2000)
        {
            printf("%d : %d\n", i, counter);
        }
    }
    clock_t fin = clock();
    printf("Tiempo = %.3f ms\n",
           (double)(fin - inicio) * 1000 / CLOCKS_PER_SEC);
    pthread_mutex_destroy(&mtx);
    return 0;
}