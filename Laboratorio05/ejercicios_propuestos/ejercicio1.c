#include <stdio.h>
struct Fecha {
    int dia;
    int mes;
    int anio;
};

void leerFecha(struct Fecha *f) {
    scanf("%d %d %d", &f->dia, &f->mes, &f->anio);
}

int calcularDias(struct Fecha f1, struct Fecha f2) {
    int dias = (f2.anio - f1.anio) * 365 + (f2.mes - f1.mes) * 30 + (f2.dia - f1.dia);
    return dias;
}
int main() {
    struct Fecha primerFecha, segundaFecha;
    printf("Ingrese la primera fecha (día mes año):");
    leerFecha(&primerFecha);
    printf("Ingrese la segunda fecha (día mes año):");
    leerFecha(&segundaFecha);
    printf("El número de días que hay entre las dos fechas es:%d\n", calcularDias(primerFecha, segundaFecha));
    return 0;
}