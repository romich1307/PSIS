#include <stdio.h>
int main()
{
    FILE *fichero;
    fichero = fopen("prueba.txt", "w");
    fprintf(fichero, "Esto es una linea\n");
    fprintf(fichero, "Esto es otra");
    fprintf(fichero, " y esto es continuacion de la anterior\n");
    fclose(fichero);
    return 0;
}