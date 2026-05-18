#include <stdio.h>
void cuadrado2(int *n) {
    // dirección recibida (misma que la variable original)
    printf("Direccion de n en funcion: %p\n", n);
    // desreferenciación para modificar el valor
    *n = (*n) * (*n);
}
void alumnos() {
    int n2 = 8;
    printf("Direccion de n2 en main: %p\n", &n2);
    // enviamos la dirección
    cuadrado2(&n2);
    printf("Cuadrado de n2: %d\n", n2);
    printf("Cambio visto en n2: %d\n", n2);
}
int main() {
    alumnos();
    return 0;
}