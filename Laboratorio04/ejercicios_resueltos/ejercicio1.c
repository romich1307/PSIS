#include <stdio.h>
void alumnos() {
    int var =20;
    int *ptr;

    ptr = &var;

    printf("Direccion almacenada en ptr = %p\n", ptr);
    printf("Direccion de var = %p\n", &var);
    printf("Valor de var = %d\n", var);
    printf("Valor al que apunta ptr (*ptr) = %d\n", *ptr);
}
int main() {
    alumnos();
    return 0;
}