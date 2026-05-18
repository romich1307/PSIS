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
        printf("Escriba el Nombre %d: ", i + 1);
        scanf("%s", amigo[i].nombre);
        printf("Escriba el Apellido %d: ", i + 1);
        scanf("%s", amigo[i].apellido);
        printf("Escriba la Edad de %d: ", i + 1);
        scanf("%d", &amigo[i].edad);
        printf("Escriba el sexo %d: ", i + 1);
        scanf("%s", amigo[i].sexo);
        printf("Escriba el Telefono de %d: ", i + 1);
        scanf("%d", &amigo[i].telefono);
        printf("\n");
    }
    printf("El registro de personas que se introdujeron es:\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t", amigo[i].nombre);
        printf("%s\t", amigo[i].apellido);
        printf("%d\t", amigo[i].edad);
        printf("%s\t", amigo[i].sexo);
        printf("%d\n\n", amigo[i].telefono);
    }
    return 0;
}