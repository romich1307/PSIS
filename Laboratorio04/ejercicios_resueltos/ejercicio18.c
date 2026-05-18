#include <stdio.h>
#include <stdlib.h>
int* createArr(int n) {
    return (int*) malloc(n * sizeof(int));
}
int main() {
    int *pt = createArr(10);
    if (pt == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
    }
    // inicializamos el arreglo
    for (int i = 0; i < 10; i++) {
        pt[i] = i * 10;
    }
    // mostramos el contenido
    for (int i = 0; i < 10; i++) {
        printf("%d ", pt[i]);
    }
    printf("\n");
    // liberamos memoria
    free(pt);
    return 0;
    }   