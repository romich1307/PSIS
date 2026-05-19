#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int *ptr = arr;
    //Tamaño del arreglo completo
    printf("Size of arr[]: %lu bytes\n", sizeof(arr));
    //Tamaño del puntero
    printf("Size of ptr: %lu bytes\n", sizeof(ptr));
    return 0;
}