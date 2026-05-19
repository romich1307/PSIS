#include <stdio.h>
struct Fecha {
    int dia;
    int mes;
    int anio;
};
struct Persona {
    char nombre[100];
    struct Fecha fecha;
};
void leerPersona(struct Persona *p) {
    printf("Nombre: ");
    scanf("%99s", p->nombre);
    printf("Día de nacimiento: ");
    scanf("%d", &p->fecha.dia);
    printf("Mes de nacimiento: ");
    scanf("%d", &p->fecha.mes);
    printf("Año de nacimiento: ");
    scanf("%d", &p->fecha.anio);
}
void mostrarPersona(const struct Persona *p) {
    printf("Nombre: %s, Fecha de nacimiento: %d/%d/%d\n",
           p->nombre, p->fecha.dia, p->fecha.mes, p->fecha.anio);
}
int main() {
    const int n = 2;
    struct Persona personas[n];
    int i;

    struct Persona *ptr = personas;
    for (i = 0; i < n; ++i, ++ptr) {
        printf("Ingrese los siguientes datos de la persona %d:\n", i + 1);
        leerPersona(ptr);
    }

    int mesConsulta;
    while (1) {
        printf("Ingrese un número de mes del 1 al 12 para consultar cumpleaños, ingrese 0 para salir: ");
        if (scanf("%d", &mesConsulta) != 1) break;
        if (mesConsulta == 0) break;

        printf("Personas que cumplen años en el mes %d:\n", mesConsulta);
        for (ptr = personas, i = 0; i < n; ++i, ++ptr) {
            if (ptr->fecha.mes == mesConsulta) {
                mostrarPersona(ptr);
            }
        }
    }
    return 0;
}