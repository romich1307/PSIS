// codigo10.c
#include <stdio.h>
#include <pthread.h>
void *funcion1(void *arg)
{
int n = *((int *)arg);
for(int i = 0; i < n; i++)
{
printf("Hilo usando la funcion 1\n");
}
return NULL;
}
void *funcion2(void *arg)
{
int n = *((int *)arg);
for(int i = 0; i < n; i++)
{
printf("Hilo usando la funcion 2\n");
}
return NULL;
}
void *funcion3(void *arg)
{
int n = *((int *)arg);
for(int i = 0; i < n; i++)
{
printf("Hilo usando la funcion 3\n");
}
return NULL;
}
int main()
{
pthread_t th1, th2, th3;
int veces = 3;
printf("Hilos 1, 2 y 3 operando independientemente\n");
pthread_create(&th1, NULL, funcion1, &veces);
pthread_create(&th2, NULL, funcion2, &veces);
pthread_create(&th3, NULL, funcion3, &veces);
pthread_join(th1, NULL);
pthread_join(th2, NULL);
pthread_join(th3, NULL);
return 0;
}