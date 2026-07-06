// codigo06.c
#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 5
void *say_hello(void *args)
{
    printf("Hola mundo!\n");
    return NULL;
}
int main()
{
    pthread_t tids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
            printf("pthread_create error: error_code=%d\n", ret);
        }
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(tids[i], NULL);
    }
    return 0;
}