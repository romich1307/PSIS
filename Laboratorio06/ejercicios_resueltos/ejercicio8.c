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
        exit(1);
    }
    if (!feof(fichero))
    {
        fgets(linea, 200, fichero);
        if (strcmp(linea, "") == 0)
        {
            printf("fichero vacio\n");
            fclose(fichero);
            exit(1);
        }
    }
    printf("el fichero tiene contenido\n");
    fclose(fichero);
    return 0;
}