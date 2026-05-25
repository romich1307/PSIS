#include <stdio.h>
int main()
{
    FILE *fichero;
    char linea[200];
    fichero = fopen("prueba.txt", "r");
    fgets(linea, 200, fichero);
    printf("Se ha leido:\n");
    printf("%s\n", linea);
    fclose(fichero);
    return 0;
}
