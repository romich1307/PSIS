// codigo08.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 5
struct thread_data
{
    int thread_id;
    char *message;
};
void *PrintHello(void *threadarg)
{
    struct thread_data *my_data;
    my_data = (struct thread_data *)threadarg;
    printf("Thread ID : %d", my_data->thread_id);
    printf(" Mensaje : %s\n", my_data->message);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("main(): creando un hilo %d\n", i);
        td[i].thread_id = i;
        td[i].message = "Este es el mensaje";
        rc = pthread_create(&threads[i], NULL,
                            PrintHello, (void *)&td[i]);
        if (rc)
        {
            printf("Error: no es posible crear el hilo. Codigo=%d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    return 0;
}