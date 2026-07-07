// codigo12.c
#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h>
#include <time.h>
atomic_int counter;
void *increment(void *arg)
{
    for (int i = 0; i < 1000; i++)
    {
        counter++;
    }
    return NULL;
}
int main()
{
    pthread_t t1, t2;
    clock_t inicio = clock();
    for (int i = 0; i < 10000; i++)
    {
        atomic_store(&counter, 0);
        pthread_create(&t1, NULL, increment, NULL);
        pthread_create(&t2, NULL, increment, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        if (atomic_load(&counter) != 2000)
        {
            printf("%d : %d\n", i, atomic_load(&counter));
        }
    }
    clock_t fin = clock();
    printf("Tiempo = %.3f ms\n",
           (double)(fin - inicio) * 1000 / CLOCKS_PER_SEC);
    return 0;
}