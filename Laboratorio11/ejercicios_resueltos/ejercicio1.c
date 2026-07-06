#include <stdio.h>
#include <pthread.h>
void *func(void *arg)
{
    return NULL;
}
int main()
{
    pthread_t th;
    pthread_create(&th, NULL, func, NULL);
    pthread_join(th, NULL);
    return 0;
}