#include <stdio.h>
#include <math.h>
double suma(double a, double b);
double resta(double a, double b);
double multiplicacion(double a, double b);
double division(double a, double b);
double cuadrado(double a);
double divisionEspecial(double a);
double raizCuadrada(double a);
double porcentaje(double numero, double porcentaje);

int main() {
    int opcion;
    double a, b, resultado;

    do {
        printf("\nCALCULADORA\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicacion\n");
        printf("4. Division\n");
        printf("5. Exponencial cuadrado\n");
        printf("6. Division especial 1/n\n");
        printf("7. Raiz cuadrada\n");
        printf("8. Porcentaje\n");
        printf("9. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese dos numeros: ");
                scanf("%lf %lf", &a, &b);
                resultado = suma(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;

            case 2:
                printf("Ingrese dos numeros: ");
                scanf("%lf %lf", &a, &b);
                resultado = resta(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                printf("Ingrese dos numeros: ");
                scanf("%lf %lf", &a, &b);
                resultado = multiplicacion(a, b);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 4:
                printf("Ingrese el dividendo: ");
                scanf("%lf", &a);
                printf("Ingrese el divisor: ");
                scanf("%lf", &b);
                if (b == 0) {
                    printf("Error: no se puede dividir entre cero.\n");
                } else {
                    resultado = division(a, b);
                    printf("Resultado: %.2f\n", resultado);
                }
                break;
            case 5:
                printf("Ingrese un numero: ");
                scanf("%lf", &a);
                resultado = cuadrado(a);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 6:
                printf("Ingrese un numero: ");
                scanf("%lf", &a);
                if (a == 0) {
                    printf("no se puede dividir 1 entre cero\n");
                } else {
                    resultado = divisionEspecial(a);
                    printf("Resultado: %.2f\n", resultado);
                }
                break;

            case 7:
                printf("Ingrese un numero: ");
                scanf("%lf", &a);

                if (a < 0) {
                    printf("no se puede calcular la raiz cuadrada de un numero negativo\n");
                } else {
                    resultado = raizCuadrada(a);
                    printf("Resultado: %.2f\n", resultado);
                }
                break;
            case 8:
                printf("Ingrese el numero base:");
                scanf("%lf", &a);
                printf("Ingrese el porcentaje: ");
                scanf("%lf", &b);
                resultado = porcentaje(a, b);
                printf("%.2f%% de %.2f es: %.2f\n", b, a, resultado);
                break;
            case 9:
                printf("hasta luego\n");
                break;
            default:
                printf("Invalido\n");
                break;
        }
    } while (opcion != 9);
    return 0;
}
double suma(double a, double b){
    return a + b;
}
double resta(double a, double b){
    return a - b;
}
double multiplicacion(double a, double b){
    return a * b;
}
double division(double a, double b){
    return a / b;
}
double cuadrado(double a){
    return a * a;
}
double divisionEspecial(double a){
    return 1 / a;
}
double raizCuadrada(double a){
    return sqrt(a);
}
double porcentaje(double numero, double porcentaje){
    return (numero * porcentaje) / 100;
}