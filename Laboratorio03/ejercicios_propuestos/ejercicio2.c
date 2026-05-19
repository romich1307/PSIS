#include <stdio.h>
double AreaCuadrilatero(double ladoA, double ladoB);
double AreaTriangulo(double base, double altura);
double AreaCirculo(double radio);
int main() {
    double a, b, area;
    int figura;
    printf("Que figura quiere analizar?\n");
    printf("Cuadrado=1, Rectangulo=2, Triangulo=3, Circulo=4\n");+
    scanf("%d", &figura);
    switch (figura) {
        case 1:
            printf("Introduzca el valor del lado: ");
            scanf("%lf", &a);

            if (a <= 0) {
                printf("el area es negativa\n");
            } else {
                area = AreaCuadrilatero(a, a);
                printf("El area del cuadrado es: %.2f\n", area);
            }
            break;
        case 2:
            printf("Introduzca el valor del lado a y lado b: ");
            scanf("%lf %lf", &a, &b);

            if (a <= 0 || b <= 0) {
                printf("el area es negativa\n");
            } else {
                area = AreaCuadrilatero(a, b);
                printf("El area del rectangulo es: %.2f\n", area);
            }
            break;
        case 3:
            printf("Introduzca la base y la altura: ");
            scanf("%lf %lf", &a, &b);

            if (a <= 0 || b <= 0) {
                printf("el area es negativa o invalida.\n");
            } else {
                area = AreaTriangulo(a, b);
                printf("El area del triangulo es: %.2f\n", area);
            }
            break;
        case 4:
            printf("Introduzca el valor del radio: ");
            scanf("%lf", &a);

            if (a <= 0) {
                printf("el area es negativa o invalida.\n");
            } else {
                area = AreaCirculo(a);
                printf("El area del circulo es: %.2f\n", area);
            }
            break;

        default:
            printf("Figura equivocada.\n");
            break;
    }
    return 0;
}
double AreaCuadrilatero(double ladoA, double ladoB) {
    return ladoA* ladoB;
}
double AreaTriangulo(double base, double altura) {
    return (base * altura) / 2;
}
double AreaCirculo(double radio){
    double pi=3.14;
    return (pi*(radio)*(radio));
}