#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = rand();
    printf("%d\n", a);
    printf("RAND_MAX: %d\n", RAND_MAX);
    return 0;
}