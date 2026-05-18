#include <stdio.h>
struct Fecha
{
    int dia;
    int mes;
    int anio;
};
int main()
{
    struct Fecha hoy, cumpleanios;
    printf("Ingrese la fecha de hoy\n");
    printf("Dia: ");
    scanf("%d", &hoy.dia);
    printf("Mes: ");
    scanf("%d", &hoy.mes);
    printf("Anio: ");
    scanf("%d", &hoy.anio);
    printf("\nIngrese su cumpleanios\n");
    printf("Dia: ");
    scanf("%d", &cumpleanios.dia);
    printf("Mes: ");
    scanf("%d", &cumpleanios.mes);
    printf("Anio: ");
    scanf("%d", &cumpleanios.anio);
    if (cumpleanios.dia == hoy.dia)
    {
        if (cumpleanios.mes == hoy.mes)
        {
            printf("FELIZ CUMPLEANIOS. FELICITACIONES!!!!\n");
        }
        else
        {
            printf("Hoy es el mismo dia de tu cumpleanios.\n");
            printf("Pero de diferente mes.\n");
        }
    }
    else
    {
        printf("Hoy no es tu cumpleanios.\n");
    }
    return 0;
}