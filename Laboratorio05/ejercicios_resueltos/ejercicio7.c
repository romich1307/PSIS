#include <stdio.h>
#include <string.h>
int main()
{
    struct
    {
        char nombre[20];
        char inicial;
        int edad;
        float nota;
    } persona;
    strcpy(persona.nombre, "Juan");
    persona.inicial = 'J';
    persona.edad = 20;
    persona.nota = 7.5;
    printf("La edad es %d\n", persona.edad);
    return 0;
}
