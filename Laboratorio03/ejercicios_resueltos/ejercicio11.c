#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("%d\n", 10 + rand() % (26 - 10));
    printf("%d\n", 25 + rand() % (100 - 25));
    return 0;
}