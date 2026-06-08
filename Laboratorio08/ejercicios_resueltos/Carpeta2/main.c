#include <string.h>
#include "persona.h"

int main()
{
    struct Persona p;

    strcpy(p.nombre, "Juan");
    p.edad = 20;

    mostrarPersona(p);

    return 0;
}
