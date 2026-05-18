#include <stdio.h>
int main() {
    int x = 10;
    // puntero que "apunta" a x (similar a referencia en C++)
    int *ref = &x;
    // modificamos x a través del puntero
    *ref = 20;
    printf("x = %d\n", x);
    // modificamos x directamente
    x = 30;
    printf("valor accedido con puntero (*ref) = %d\n", *ref);
    return 0;
}