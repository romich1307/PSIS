#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int i, valor;
    srand(time(NULL));
    for (i = 1; i <= 20; i++) {
        valor = 5 + rand() % (10 - 5);
        printf("Calificacion %d: %d\t", i, valor);
        if (i % 2 == 0) printf("\n");
    }
    return 0;
}