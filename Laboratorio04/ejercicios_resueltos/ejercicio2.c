#include <stdio.h>
void cuadrado(int *n){
    printf("Direccion de n en funcion: %p\n", n);
    *n = (*n) * (*n);
}

void alumnos() {
    int n1 = 8;
    printf("Direccion de n1 en main: %p\n", &n1);
    cuadrado(&n1);
    printf("Valor de n1 despues de la funcion: %d\n", n1);
}
int main() {
    alumnos();
    return 0;
}