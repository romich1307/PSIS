#include <stdio.h>
void leerMatriz(int filas, int columnas, double matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese matriz[%d][%d]: ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }
}
void mostrarMatriz(int filas, int columnas, double matriz[filas][columnas]) {
    printf("\nMatriz ingresada:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%8.2lf", matriz[i][j]);
        }
        printf("\n");
    }
}
int esMenorFila(int filas, int columnas, double matriz[filas][columnas], int fila, int columna) {
    double valor = matriz[fila][columna];
    for (int j = 0; j < columnas; j++) {
        if (valor > matriz[fila][j]) {
            return 0;
        }
    }

    return 1;
}
int esMayorColumna(int filas, int columnas, double matriz[filas][columnas], int fila, int columna) {
    double valor = matriz[fila][columna];
    for (int i = 0; i < filas; i++) {
        if (valor < matriz[i][columna]) {
            return 0;
        }
    }

    return 1;
}
int buscarPuntoSilla(int filas, int columnas, double matriz[filas][columnas], int *filaPunto, int *columnaPunto) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (esMenorFila(filas, columnas, matriz, i, j) &&
                esMayorColumna(filas, columnas, matriz, i, j)) {

                *filaPunto = i;
                *columnaPunto = j;

                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int filas, columnas;
    int filaPunto, columnaPunto;

    printf("Ingrese numero de filas: ");                                        
    scanf("%d", &filas);

    printf("Ingrese numero de columnas: ");
    scanf("%d", &columnas);

    if (filas <= 0 || columnas <= 0) {
        printf("Las dimensiones no son validas.\n");
        return 1;
    }
    double matriz[filas][columnas];

    leerMatriz(filas, columnas, matriz);
    mostrarMatriz(filas, columnas, matriz);
    if (buscarPuntoSilla(filas, columnas, matriz, &filaPunto, &columnaPunto)) {
        printf("\nExiste punto de silla.\n");
        printf("Valor: %.2lf\n", matriz[filaPunto][columnaPunto]);
        printf("Posicion: fila %d, columna %d\n", filaPunto + 1, columnaPunto + 1);
    } else {
        printf("\nNo existe punto de silla.\n");
    }
    return 0;
}