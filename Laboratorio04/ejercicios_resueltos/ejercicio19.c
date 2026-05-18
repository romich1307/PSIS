#include <stdio.h>
#include <stdlib.h>
int main() {
    // reservamos memoria para un entero
    int *n = (int*) malloc(sizeof(int));
    if (n == NULL) {
        printf("Error al asignar memoria\n");
        return 1;
}
// asignamos valor
*n = 10;
printf("Valor almacenado: %d\n", *n);
// liberamos memoria
free(n);
return 0;
}