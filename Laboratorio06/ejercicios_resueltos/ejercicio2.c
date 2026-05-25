#include <stdio.h>
int main()
{
    FILE *ficheroEntrada;
    char frase[100];
    ficheroEntrada = fopen("ficheroTexto.txt", "r");
    fgets(frase, 100, ficheroEntrada);
    fclose(ficheroEntrada);
    printf("Frase leida: %s\n", frase);
    return 0;
}