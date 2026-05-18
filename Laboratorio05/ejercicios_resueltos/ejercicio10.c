#include <stdio.h>
#include <string.h>
struct Fecha
{
    int dia;
    int mes;
    int anio;
};
struct Persona
{
    char nombre[20];
    int edad;
    int peso;
    struct Fecha fecha;
};
struct Empleado
{
    struct Persona persona;
    int salario;
};
int main()
{
    struct Persona persona =
        {
            "Cindy",
            20,
            45,
            {2, 12, 1997}};
    struct Empleado trabajador =
        {
            {"Steven", 19, 60, {22, 7, 1998}},
            1000};
    printf("Persona: %s\n", persona.nombre);
    printf("Edad: %d\n", persona.edad);
    printf("Peso: %d\n", persona.peso);
    printf("Dia nacimiento: %d\n", persona.fecha.dia);
    printf("Mes nacimiento: %d\n", persona.fecha.mes);
    printf("Anio nacimiento: %d\n", persona.fecha.anio);
    printf("\n----------Trabajador----------\n");
    printf("Trabajador: %s\n", trabajador.persona.nombre);
    printf("Edad: %d\n", trabajador.persona.edad);
    printf("Peso: %d\n", trabajador.persona.peso);
    printf("Dia nacimiento: %d\n", trabajador.persona.fecha.dia);
    printf("Mes nacimiento: %d\n", trabajador.persona.fecha.mes);
    printf("Anio nacimiento: %d\n", trabajador.persona.fecha.anio);
    printf("Salario: %d\n", trabajador.salario);
    return 0;
}