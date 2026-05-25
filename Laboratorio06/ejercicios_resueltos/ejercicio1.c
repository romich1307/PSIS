#include <stdio.h>
int main()
{
    FILE *ficheroSalida;
    ficheroSalida = fopen("ficheroTexto.txt", "w");
    fprintf(ficheroSalida, "Texto para el fichero");
    fclose(ficheroSalida);
    return 0;
}