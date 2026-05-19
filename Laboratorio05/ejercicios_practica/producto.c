#include <stdio.h>
#include "producto.h"

void leerProducto(struct Producto *p) {
    printf("Ingrese el nombre del producto: ");
    scanf("%s", p->nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &p->precio);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &p->cantidad);
}

void mostrarProducto(struct Producto p) {
    printf("\nDatos del producto:\n");
    printf("Nombre: %s\n", p.nombre);
    printf("Precio: %.2f\n", p.precio);
    printf("Cantidad: %d\n", p.cantidad);
}

float calcularTotal(struct Producto p) {
    return p.precio * p.cantidad;
}

    scanf("%d", &a->edad);
    printf("Ingrese la nota del alumno: ");
    scanf("%f", &a->nota);
}

void mostrarAlumno(struct Alumno a) {
    printf("\nDatos del alumno:\n");
    printf("Nombre: %s\n", a.nombre);
    printf("Edad: %d\n", a.edad);
    printf("Nota: %.2f\n", a.nota);
}

