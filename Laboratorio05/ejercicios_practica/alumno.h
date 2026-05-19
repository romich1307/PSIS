#ifndef ALUMNO_H
#define ALUMNO_H

struct Alumno
{
    char nombre[30];
    int edad;
    float nota;
};
void leerAlumno(struct Alumno *a);
void mostrarAlumno(struct Alumno a);
#endif