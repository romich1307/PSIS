// codigo04.c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void *func(void *arg)
{
    int *empezar = (int *)arg;
    while (!(*empezar))
    {
        usleep(1000); // Espera 1 milisegundo
    }
    printf("B\n");
    return NULL;
}
int main()
{
    pthread_t th;
    int empezar = 0;
    pthread_create(&th, NULL, func, &empezar);
    printf("A\n");
    empezar = 1;
    pthread_join(th, NULL);
    return 0;
}