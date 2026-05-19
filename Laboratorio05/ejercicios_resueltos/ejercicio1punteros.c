#include <stdio.h>

struct persona
{
    char nombre[15];
    char apellido[15];
    int edad;
    char sexo[15];
    int telefono;
};

int main()
{
    struct persona amigo[5];

    for (int i = 0; i < 5; i++)
    {
        struct persona *p = &amigo[i];  

        printf("Escriba el Nombre %d: ", i + 1);
        scanf("%14s", p->nombre);

        printf("Escriba el Apellido %d: ", i + 1);
        scanf("%14s", p->apellido);

        printf("Escriba la Edad de %d: ", i + 1);
        scanf("%d", &p->edad);

        printf("Escriba el sexo %d: ", i + 1);
        scanf("%14s", p->sexo);

        printf("Escriba el Telefono de %d: ", i + 1);
        scanf("%d", &p->telefono);

        printf("\n");
    }

    printf("El registro de personas que se introdujeron es:\n\n");

    for (int i = 0; i < 5; i++)
    {
        struct persona *p = &amigo[i];  

        printf("%s\t", p->nombre);
        printf("%s\t", p->apellido);
        printf("%d\t", p->edad);
        printf("%s\t", p->sexo);
        printf("%d\n\n", p->telefono);
    }

    return 0;
}