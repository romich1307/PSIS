#include <stdio.h>
int main()
{
    int i;
    long pos;
    char mes[][20] =
        {
            "Enero",
            "Febrero",
            "Marzo",
            "Abril",
            "Mayo",
            "Junio",
            "Julio",
            "Agosto",
            "Septiembre",
            "Octubre",
            "Noviembre",
            "Diciembre"};
    char cad[20];
    FILE *fsalida;
    FILE *fentrada;
    /* Crear archivo */
    fsalida = fopen("meses.dat", "wb");
    printf("Crear archivo de nombres de meses:\n");
    for (i = 0; i < 12; i++)
    {
        fwrite(mes[i], sizeof(char), 20, fsalida);
    }
    fclose(fsalida);
    /* Abrir archivo */
    fentrada = fopen("meses.dat", "rb");
    /* Acceso secuencial */
    printf("\nAcceso secuencial:\n");
    fread(cad, sizeof(char), 20, fentrada);
    while (!feof(fentrada))
    {
        printf("%s\n", cad);
        fread(cad, sizeof(char), 20, fentrada);
    }
    /* Acceso aleatorio */
    printf("\nAcceso aleatorio:\n");
    for (i = 11; i >= 0; i--)
    {
        fseek(fentrada, 20 * i, SEEK_SET);
        fread(cad, sizeof(char), 20, fentrada);
        printf("%s\n", cad);
    }
    /* Numero de registros */
    fseek(fentrada, 0, SEEK_END);
    pos = ftell(fentrada);
    printf("\nNumero de registros: %ld\n", pos / 20);
    fclose(fentrada);
    return 0;
}