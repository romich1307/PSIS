#include <stdio.h>
struct Fecha {
    int dia;
    int mes;
    int anio;
};
int main() {
    struct Fecha primerFecha, segundaFecha;
    int dias;
    printf("Ingrese la primera fecha (día mes año):");
    scanf("%d %d %d", &primerFecha.dia, &primerFecha.mes, &primerFecha.anio);
    printf("Ingrese la segunda fecha (día mes año):");
    scanf("%d %d %d", &segundaFecha.dia, &segundaFecha.mes, &segundaFecha.anio);
    dias = (segundaFecha.anio-primerFecha.anio)*365 +(segundaFecha.mes-primerFecha.mes)*30+(segundaFecha.dia-primerFecha.dia);
    printf("El número de días que hay entre las dos fechas es: %d\n", dias);
    return 0;
}