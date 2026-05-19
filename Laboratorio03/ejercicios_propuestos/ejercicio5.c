#include <stdio.h>
void paresImpares(void);
int esPerfecto(int numero);
void numerosPerfectos();
int invertirNumero(int numero);
int main() {
    int opcion;
    int numero, invertido;
    do {
        printf("\nMENU DE OPCIONES\n");
        printf("1.Determinar pares e impares de 10 enteros\n");
        printf("2.Mostrar numeros perfectos del 1 al 100\n");
        printf("3.Invertir un numero de cuatro digitos\n");
        printf("4.Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                paresImpares();
                break;
            case 2:
                numerosPerfectos();
                break;
            case 3:
                printf("Ingrese un numero entero de cuatro digitos:");
                scanf("%d", &numero);
                if (numero < 1000 || numero > 9999) {
                    printf("Error: debe ingresar un numero de cuatro digitos.\n");
                } else {
                    invertido = invertirNumero(numero);
                    printf("Numero invertido: %d\n", invertido);
                }
                break;
            case 4:
                printf("Saliendo\n");
                break;

            default:
                printf("Opcion no valida.\n");
                break;
        }
    } while (opcion != 4);
    return 0;
}

void paresImpares() {
    int numero;
    int i;
    printf("\nIngrese 10 numeros enteros:\n");
    for (i = 1; i <= 10; i++) {
        printf("Numero %d: ", i);
        scanf("%d", &numero);
        if (numero % 2 == 0) {
            printf("%d es par.\n", numero);
        } else {
            printf("%d es impar.\n", numero);
        }
    }
}
int esPerfecto(int numero) {
    int suma = 0;
    int i;
    for (i = 1; i < numero; i++) {
        if (numero % i == 0) {
            suma = suma + i;
        }
    }
    if (suma == numero) {
        return 1;
    } else {
        return 0;
    }
}
void numerosPerfectos() {
    int i;
    printf("\nNumeros perfectos del 1 al 100:\n");
    for (i = 1; i <= 100; i++) {
        if (esPerfecto(i) == 1) {
            printf("%d\n", i);
        }
    }
}
int invertirNumero(int numero) {
    int millar, centena, decena, unidad;
    int invertido;
    millar = numero / 1000;
    centena = (numero / 100) % 10;
    decena = (numero / 10) % 10;
    unidad = numero % 10;
    invertido = unidad * 1000 + decena * 100 + centena * 10 + millar;
    return invertido;
}