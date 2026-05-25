#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    FILE *fichero;
    char nombre[100];
    char linea[200];
    printf("Dime el nombre del fichero: ");
    fgets(nombre, 100, stdin);
    /* eliminar salto de linea */
    nombre[strcspn(nombre, "\n")] = '\0';
    fichero = fopen(nombre, "r");
    if (fichero == NULL)
    {
        printf("No existe el fichero!\n");
        return 1;
    }
    while (!feof(fichero))
    {
        if (fgets(linea, 200, fichero) != NULL)
        {
            printf("%s", linea);
        }
    }
    fclose(fichero);
    return 0;
}
