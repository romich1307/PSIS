#include <stdio.h>
double suma(double x, double y);
double producto(double x, double y);

int main() {
    double a, b;
    int c;

    printf("Escribe un número:");
    scanf("%lf", &a);

    printf("Escribe el segundo número:");
    scanf("%lf", &b);

    printf("Que operacion deseas hacer?\n");
    printf("1.Suma\n");
    printf("2.Producto\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &c);

    if (c==1) {
        printf("El resultado de la suma es:%.2f\n", suma(a, b));
    } 
    else if (c==2) {
        printf("El resultado del producto es:%.2f\n", producto(a, b));
    } 
    else {
        printf("inválido.\n");
    }
    return 0;
}
double producto(double x, double y) {
    return x*y;
}
double suma (double x, double y){
    double z;
    z=x + y;
    return z;
}