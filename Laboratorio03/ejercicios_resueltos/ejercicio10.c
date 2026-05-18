#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("%d\n", 1 + rand() % 100);
    printf("%d\n", 25 + rand() % 100);
    printf("%d\n", rand() % 51);
    return 0;
}