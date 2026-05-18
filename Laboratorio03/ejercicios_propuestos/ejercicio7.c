#include <stdio.h>

void generarSubconjuntos(int conjunto[], int subconjunto[], int inicio, int posicion, int n, int tamanio);
void imprimirSubconjunto(int subconjunto[], int tamanio);

int main() {
    int n;
    int i, tamanio;

    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Error: n debe ser mayor que 0.\n");
        return 1;
    }

    int conjunto[n];
    int subconjunto[n];

    for (i = 0; i < n; i++) {
        conjunto[i] = i + 1;
    }

    printf("\nSubconjuntos no vacios del conjunto del 1 al %d:\n\n", n);

    for (tamanio = 1; tamanio <= n; tamanio++) {
        generarSubconjuntos(conjunto, subconjunto, 0, 0, n, tamanio);
    }

    return 0;
}

void generarSubconjuntos(int conjunto[], int subconjunto[], int inicio, int posicion, int n, int tamanio) {
    int i;

    if (posicion == tamanio) {
        imprimirSubconjunto(subconjunto, tamanio);
        return;
    }

    for (i = inicio; i < n; i++) {
        subconjunto[posicion] = conjunto[i];

        generarSubconjuntos(conjunto, subconjunto, i + 1, posicion + 1, n, tamanio);
    }
}

void imprimirSubconjunto(int subconjunto[], int tamanio) {
    int i;

    for (i = 0; i < tamanio; i++) {
        printf("%d ", subconjunto[i]);
    }

    printf("\n");
}