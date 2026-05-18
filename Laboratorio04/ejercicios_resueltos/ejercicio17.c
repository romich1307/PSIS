#include <stdio.h>
#include <math.h>
void fun(int n, int *cuadrado, double *raiz_cuadrada) {
    *cuadrado = n * n;
    *raiz_cuadrada = sqrt(n);
}
int main() {
    int n = 100;
    int sq;
    double sq_root;
    fun(n, &sq, &sq_root);
    printf("Cuadrado: %d\n", sq);
    printf("Raiz cuadrada: %.2f\n", sq_root);
    return 0;
}