#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    for (i = 1; i <= 3; i++) {
    printf("Corrida: %d\n", i);
    printf("Sin semilla: %d\n", rand());
    srand(40);
    printf("valor2: %d\n", rand());
    printf("valor3: %d\n", rand() % 100 + 1);
    srand(1);
}
    return 0;
}