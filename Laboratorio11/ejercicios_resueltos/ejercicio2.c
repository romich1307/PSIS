#include <stdio.h>
#include <pthread.h>
typedef struct
{
    int n;
    double m;
} Datos;
void *func(void *arg)
{
    Datos *datos = (Datos *)arg;
    printf("n = %d\n", datos->n);
    printf("m = %.1f\n", datos->m);
    return NULL;
}
int main()
{
    pthread_t th;
    Datos datos;
    datos.n = 1;
    datos.m = 5.7;
    pthread_create(&th, NULL, func, &datos);
    pthread_join(th, NULL);
    return 0;
}