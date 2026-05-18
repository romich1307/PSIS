#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tirarDado();
int tirarDados(int *dado1, int *dado2);
int main() {
    int dado1, dado2;
    int suma;
    int punto;
    srand(time(NULL));
    printf("Juego de dados:\n\n");
    suma = tirarDados(&dado1, &dado2);
    printf("Primera tirada:\n");
    printf("Dado 1: %d\n", dado1);
    printf("Dado 2: %d\n", dado2);
    printf("Suma: %d\n\n", suma);
    if (suma ==7||suma ==11) {
        printf("Ganaste en la primera tirada.\n");
    } 
    else if (suma ==2||suma==3||suma==12) {
        printf("Craps. Perdiste en la primera tirada.\n");
    } 
    else {
        punto = suma;
        printf("Tu punto es: %d\n", punto);
        printf("Debes volver a sacar %d para ganar.\n", punto);
        printf("Si sale 7 antes, pierdes.\n\n");
        do {
            printf("Presiona ENTER para tirar los dados");
            getchar();
            suma = tirarDados(&dado1,&dado2);
            printf("\nDado 1: %d\n",dado1);
            printf("Dado 2: %d\n",dado2);
            printf("Suma: %d\n\n",suma);
            if (suma == punto) {
                printf("Volviste a sacar tu punto.ganaste.\n");
            } 
            else if (suma == 7) {
                printf("Salio 7 antes de tu punto,perdiste.\n");
            } 
            else {
                printf("Sigue jugando\n\n");
            }
        } while (suma != punto && suma != 7);
    }
    return 0;
}
int tirarDado() {
    return 1 + rand() % 6;
}
int tirarDados(int *dado1, int *dado2) {
    *dado1 = tirarDado();
    *dado2 = tirarDado();
    return *dado1 + *dado2;
}