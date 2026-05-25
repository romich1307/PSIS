#include <stdio.h>
#include <string.h>

int main()
{
    FILE *ficheroEntrada;
    char nombre[100];
    char frase[200];
    printf("Dime el nombre del fichero: ");
    fgets(nombre, 100, stdin);
    /* eliminar salto de linea */
    nombre[strcspn(nombre, "\n")] = '\0';
    ficheroEntrada = fopen(nombre, "r");
    if (ficheroEntrada != NULL)
    {
        while (fgets(frase, 200, ficheroEntrada) != NULL)
        {
            printf("Leido: %s", frase);
        }
        fclose(ficheroEntrada);
    }
    else
    {
        printf("Fichero inexistente o faltan permisos para abrirlo\n");
    }
    return 0;
}
