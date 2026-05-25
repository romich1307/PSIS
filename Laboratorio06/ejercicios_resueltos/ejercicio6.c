#include <stdio.h>
#include <string.h>
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
    if (fichero != NULL)
    {
        fgets(linea, 200, fichero);
        printf("Se ha leido:\n");
        printf("%s\n", linea);
        fclose(fichero);
    }
    else
    {
        printf("No se pudo abrir el fichero\n");
    }
    return 0;
}

