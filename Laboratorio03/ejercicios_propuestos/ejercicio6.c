#include <stdio.h>
void generarPermutaciones(int permutacion[], int usado[], int posicion, int n);
void imprimirPermutacion(int permutacion[], int n);
int main() {
    int n;
    int permutacion[10];
    int usado[10 + 1] = {0};
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);
    if (n < 1 || n > 10) {
        printf("Error: n debe estar entre 1 y %d.\n", 10);
        return 1;
    }
    printf("\nPermutaciones de los numeros del 1 al %d:\n\n", n);
    generarPermutaciones(permutacion, usado, 0, n);
    return 0;
}
void generarPermutaciones(int permutacion[], int usado[], int posicion, int n) {
    int i;
    if (posicion == n) {
        imprimirPermutacion(permutacion, n);
        return;
    }
    for (i = 1; i <= n; i++) {
        if (usado[i] == 0) {
            permutacion[posicion] = i;
            usado[i] = 1;
            generarPermutaciones(permutacion, usado, posicion + 1, n);
            usado[i] = 0;
        }
    }
}
void imprimirPermutacion(int permutacion[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", permutacion[i]);
    }
    printf("\n");
}