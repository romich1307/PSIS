#include <stdio.h>
void fun(int ptr[]) {
int x = 10;
// ptr es tratado como puntero
printf("sizeof(ptr) en funcion = %lu bytes\n", sizeof(ptr));
ptr = &x; // esto solo cambia el puntero local
printf("*ptr dentro de la funcion = %d\n", *ptr);
}
int main() {
int arr[] = {20, 20, 30, 40, 50, 60};
// tamaño real del arreglo
printf("sizeof(arr) en main = %lu bytes\n", sizeof(arr));
fun(arr);
return 0;
}