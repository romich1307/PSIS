#include <stdio.h>
#include "persona.h"

void mostrarPersona(struct Persona p)
{
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);
}

