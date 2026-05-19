#include <stdio.h>
#include "alumno.h"

void leerAlumno(struct Alumno *a) {
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", a->nombre);
    printf("Ingrese la edad del alumno: ");
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

