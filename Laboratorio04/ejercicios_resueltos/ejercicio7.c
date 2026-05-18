#include <stdio.h>
int main() {
    int var = 10;
    int *p1 = &var; // puntero simple
    int **p2 = &p1; // puntero doble
    int ***p3 = &p2; // puntero triple
    printf("Valor de var: %d\n", var);
    printf("\n--- Direcciones ---\n");
    printf("Direccion de var: %p\n", &var);
    printf("Direccion de p1: %p\n", &p1);
    printf("Direccion de p2: %p\n", &p2);
    printf("Direccion de p3: %p\n", &p3);
    printf("\n--- Contenido de punteros ---\n");
    printf("p1 (apunta a var): %p\n", p1);
    printf("p2 (apunta a p1): %p\n", p2);
    printf("p3 (apunta a p2): %p\n", p3);
    printf("\n--- Acceso a valores ---\n");
    printf("*p1: %d\n", *p1);
    printf("**p2: %d\n", **p2);
    printf("***p3: %d\n", ***p3);
    return 0;
}