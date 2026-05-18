#include <stdio.h>
#include <stdlib.h>
int main() {
    int *a;
    // reservar memoria
    a = (int*) malloc(sizeof(int));
    if (a == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
}
    printf("Ingrese un valor entero: ");
    scanf("%d", a);
    printf("El valor ingresado es: %d\n", *a);
    // liberar memoria
    free(a);
    return 0;
}