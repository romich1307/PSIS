#include <stdio.h>
#include "alumno.h"

int main() {
    struct Alumno a;
    leerAlumno(&a);
    mostrarAlumno(a);
    return 0;

    struct Producto b;
    leerProducto(&b);
    mostrarProducto(b);
    printf("Total: %.2f\n", calcularTotal(b));
    return 0;
}