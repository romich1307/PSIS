#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", rand() % 2);
    printf("%d\n", rand() % 10);
    printf("%d\n", rand() % 1500);
    printf("%d\n", rand() % 65536);
    return 0;
}