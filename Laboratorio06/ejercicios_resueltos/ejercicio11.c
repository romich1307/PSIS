#include <stdio.h>
int main()
{
    char l;
    long i, lon;
    FILE *fich;
    /* Abrir archivo para lectura y escritura */
    fich = fopen("prueba.dat", "wb+");
    /* Escribir palabra */
    fprintf(fich, "abracadabra");
    fflush(fich);
    /* Obtener tamaño del archivo */
    fseek(fich, 0L, SEEK_END);
    lon = ftell(fich);
    /* Reemplazar caracteres */
    for (i = 0L; i < lon; i++)
    {
        fseek(fich, i, SEEK_SET);
        fread(&l, sizeof(char), 1, fich);
        if (l == 'a')
        {
            l = 'e';
            fseek(fich, i, SEEK_SET);
            fwrite(&l, sizeof(char), 1, fich);
        }
    }
    /* Mostrar resultado */
    printf("Salida:\n");
    fseek(fich, 0L, SEEK_SET);
    for (i = 0L; i < lon; i++)
    {
        fread(&l, sizeof(char), 1, fich);
        printf("%c", l);
    }
    printf("\n");
    fclose(fich);
    return 0;
}