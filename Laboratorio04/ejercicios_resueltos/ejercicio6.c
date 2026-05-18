#include <stdio.h>
void swap(int *primero, int *segundo) {
    int temporal;
    temporal = *primero;
    *primero = *segundo;
    *segundo = temporal;
}
int main() {
    int a = 2, b = 3;
    printf("Antes del intercambio: a = %d, b = %d\n", a, b);
    // enviamos las direcciones
    swap(&a, &b);
    printf("Despues del intercambio: a = %d, b = %d\n", a, b);
    return 0;
}