// codigo07.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5
void *PrintHello(void *threadid)
{
    int tid = *((int *)threadid);
    printf("Hola mundo! parametro ID: %d\n", tid);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS];
    int rc;
    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("main(): parametro %d\n", i);
        indexes[i] = i;
        rc = pthread_create(&threads[i], NULL,
                            PrintHello, (void *)&indexes[i]);
        if (rc)
        {
            printf("Error: error_code=%d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}