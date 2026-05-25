#include <stdio.h>
#include <string.h>
int main()
{
    FILE *fichero;
    char nombre[100];
    unsigned char dato;
    int compresion;
    printf("Comprobador de imagenes BMP\n");
    printf("Dime el nombre del fichero: ");
    fgets(nombre, 100, stdin);
    /* eliminar salto de linea */
    nombre[strcspn(nombre, "\n")] = '\0';
    fichero = fopen(nombre, "rb");
    if (fichero == NULL)
    {
        printf("No encontrado\n");
    }
    else
    {
        /* mover cursor al byte 30 */
        fseek(fichero, 30, SEEK_SET);
        /* leer 1 byte */
        fread(&dato, sizeof(unsigned char), 1, fichero);
        fclose(fichero);
        compresion = dato;
        if (compresion == 0)
        {
            printf("Sin compresion\n");
        }
        else
        {
            printf("BMP Comprimido\n");
        }
    }
}