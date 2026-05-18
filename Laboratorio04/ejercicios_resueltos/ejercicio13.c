#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    // puntero apunta al inicio del arreglo
    int *ptr = arr;
    printf("Valor del primer elemento (*ptr): %d\n", *ptr);
    printf("Direccion de arr: %p\n", arr);
    printf("Direccion almacenada en ptr: %p\n", ptr);
    return 0;
}