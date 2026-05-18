#include <stdio.h>
// función que recibe la dirección (puntero)
void cuadrado3(int *n) {
    // misma dirección que en main
    printf("Direccion de n en funcion: %p\n", n);
    // modificamos directamente el valor
    *n = (*n) * (*n);
}
void alumnos() {
    int n3 = 8;
    printf("Direccion de n3 en main: %p\n", &n3);
    // enviamos la dirección
    cuadrado3(&n3);
    printf("Cuadrado de n3: %d\n", n3);
    printf("Cambio reflejado en n3: %d\n", n3);
}
int main() {
    alumnos();
    return 0;
}