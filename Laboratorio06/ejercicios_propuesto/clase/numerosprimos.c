#include <stdio.h>
#include <stdlib.h>
 int es_primo(int num) {
    if (num <= 1) return 0;
    for (int i=2;i<= num/2;i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int cantidad;
    printf("Ingrese la cantidad de numeros primos:");
    scanf("%d", &cantidad);

    FILE *ficheroSalida;
    ficheroSalida = fopen("numeros_primos.txt","w");

    int contador = 0;
    int num = 2;
    while (contador<cantidad) {
        if (es_primo(num)) {
            fprintf(ficheroSalida, "%d\n", num);
            contador++;
        }
        num++;
    }
    fclose(ficheroSalida);
    printf("Se han generado %d numeros primos.\n", cantidad);
    return 0;
}
