#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearArchivoAleatorio(char nombreArchivo[], int n);
int leerArchivo(char nombreArchivo[], int numeros[]);
void ordenarAscendente(int numeros[], int n);
void guardarArchivoOrdenado(char nombreArchivo[], int numeros[], int n);

int main() {
    int n;
    int numeros[1000];
    int cantidad;

    printf("Ingrese la cantidad de numeros aleatorios: ");
    scanf("%d", &n);
    crearArchivoAleatorio("numeros.txt", n);
    printf("\nNumeros aleatorios guardados en numeros.txt\n");
    cantidad = leerArchivo("numeros.txt", numeros);
    ordenarAscendente(numeros, cantidad);
    guardarArchivoOrdenado("numeros.txt", numeros, cantidad);
    printf("El archivo numeros.txt fue ordenado de forma ascendente.\n");

    return 0;
}

void crearArchivoAleatorio(char nombreArchivo[], int n) {
    FILE *archivo;
    int numero;
    int i;

    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return;
    }

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        numero = rand() % 100 + 1;
        fprintf(archivo, "%d\n", numero);
    }

    fclose(archivo);
}

int leerArchivo(char nombreArchivo[], int numeros[]) {
    FILE *archivo;
    int i = 0;

    archivo = fopen(nombreArchivo, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 0;
    }

    while (fscanf(archivo, "%d", &numeros[i]) == 1) {
        i++;
    }

    fclose(archivo);

    return i;
}

void ordenarAscendente(int numeros[], int n) {
    int i, j, aux;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (numeros[j] > numeros[j + 1]) {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }
}

void guardarArchivoOrdenado(char nombreArchivo[], int numeros[], int n) {
    FILE *archivo;
    int i;

    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("Error al guardar el archivo ordenado.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        fprintf(archivo, "%d\n", numeros[i]);
    }

    fclose(archivo);
}