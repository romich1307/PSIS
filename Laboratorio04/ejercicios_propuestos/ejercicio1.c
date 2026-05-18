#include <stdio.h>

void mostrarFila(int *fila, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("%4d", *(fila + i));
    }
    printf("\n");
}

void generarPascal(int n) {
    int fila[50] = {0};
    *fila = 1;
    for (int i = 0; i < n; i++) {
        for (int espacio = 0; espacio < n - i; espacio++) {
            printf("  ");
        }
        mostrarFila(fila, i + 1);
        for (int posicion = i + 1; posicion > 0; posicion--) {
            *(fila + posicion) = *(fila + posicion) + *(fila + posicion - 1);
        }
    }
}

int main() {
    int n;
    printf("Ingrese número de filas: ");
    scanf("%d", &n);
    if (n <= 0 || n > 50) {
        printf("Número de filas no válido.\n");
        return 1;
    }
    generarPascal(n);
    return 0;
}
