#include <stdio.h>
#include <stdlib.h>

int **crearMatriz(int filas, int columnas) {
    int **matriz = (int **)malloc(filas * sizeof(int *));

    if (matriz == NULL) {
        return NULL;
    }

    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));

        if (matriz[i] == NULL) {
            return NULL;
        }
    }

    return matriz;
}

void leerMatriz(int **matriz, int filas, int columnas, char nombre) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese %c[%d][%d]: ", nombre, i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrices(int **A, int **B, int **C, int filasA, int columnasA, int columnasB) {
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            C[i][j] = 0;

            for (int k = 0; k < columnasA; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void liberarMatriz(int **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }

    free(matriz);
}

int main() {
    int filasA, columnasA, filasB, columnasB;

    printf("Ingrese filas de A: ");
    scanf("%d", &filasA);

    printf("Ingrese columnas de A: ");
    scanf("%d", &columnasA);

    printf("Ingrese filas de B: ");
    scanf("%d", &filasB);

    printf("Ingrese columnas de B: ");
    scanf("%d", &columnasB);

    if (filasA <= 0 || columnasA <= 0 || filasB <= 0 || columnasB <= 0) {
        printf("Dimensiones no validas.\n");
        return 1;
    }

    if (columnasA != filasB) {
        printf("No se pueden multiplicar las matrices.\n");
        printf("Las columnas de A deben ser iguales a las filas de B.\n");
        return 1;
    }

    int **A = crearMatriz(filasA, columnasA);
    int **B = crearMatriz(filasB, columnasB);
    int **C = crearMatriz(filasA, columnasB);

    if (A == NULL || B == NULL || C == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("\nIngrese matriz A:\n");
    leerMatriz(A, filasA, columnasA, 'A');

    printf("\nIngrese matriz B:\n");
    leerMatriz(B, filasB, columnasB, 'B');

    multiplicarMatrices(A, B, C, filasA, columnasA, columnasB);

    printf("\nMatriz A:\n");
    imprimirMatriz(A, filasA, columnasA);

    printf("\nMatriz B:\n");
    imprimirMatriz(B, filasB, columnasB);

    printf("\nResultado A x B:\n");
    imprimirMatriz(C, filasA, columnasB);

    liberarMatriz(A, filasA);
    liberarMatriz(B, filasB);
    liberarMatriz(C, filasA);

    return 0;
}