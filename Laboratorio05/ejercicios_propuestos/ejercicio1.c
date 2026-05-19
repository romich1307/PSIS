#include <stdio.h>

struct Fecha {
    int dia;
    int mes;
    int anio;
};

int main() {
    struct Fecha fecha1, fecha2;
    int dias;

    printf("Ingrese la primera fecha (dd mm aaaa): ");
    scanf("%d %d %d", &fecha1.dia, &fecha1.mes, &fecha1.anio);
    printf("Ingrese la segunda fecha (dd mm aaaa): ");
    scanf("%d %d %d", &fecha2.dia, &fecha2.mes, &fecha2.anio);

   
    dias = (fecha2.anio - fecha1.anio) * 365 + (fecha2.mes - fecha1.mes) * 30 + (fecha2.dia - fecha1.dia);

    printf("El número de días entre las dos fechas es: %d\n", dias);

    return 0;
}