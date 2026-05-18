#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int secreto, intento, contador = 0;
    srand(time(NULL));
    secreto = 1 + rand() % 10;
    printf("Adivina el numero (1-10). Tienes 2 intentos\n");
    do {
        printf("Ingrese numero: ");
        scanf("%d", &intento);
        contador++;
        if (intento == secreto) {
            printf("Ganaste! Era %d\n", secreto);
            return 0;
        } else {
            printf("Incorrecto\n");
        }
    } while (contador < 2);
    printf("Perdiste. Era: %d\n", secreto);
    return 0;
}