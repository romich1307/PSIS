// codigo09.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 5
void *wait_thread(void *arg)
{
    long tid = (long)arg;
    sleep(1);
    printf("El thread esta durmiendo\n");
    printf("Thread con id : %ld ... saliendo\n", tid);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long i;
    void *status;
    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("main(): creando el thread %ld\n", i);
        rc = pthread_create(&threads[i], NULL,
                            wait_thread, (void *)i);
        if (rc)
        {
            printf("Error: inhabilitado para crear un thread. Codigo=%d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            printf("Error: inhabilitado para join. Codigo=%d\n", rc);
            exit(EXIT_FAILURE);
        }
        printf("Main: thread %ld completado\n", i);
    }
    printf("Main: programa saliendo.\n");
    return 0;
}