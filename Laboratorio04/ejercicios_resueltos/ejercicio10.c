#include <stdio.h>
void alumnos() {
    // declaramos el arreglo
    int v[3] = {10, 100, 200};
    // declaramos un puntero
    int *ptr;
    // asignamos la dirección del primer elemento
    ptr = v;
    for (int i = 0; i < 3; i++) {
        printf("Direccion almacenada en ptr = %p\n", ptr);
        printf("Valor al que apunta ptr (*ptr) = %d\n", *ptr);
        // incrementamos el puntero
        ptr++;
    }
}
int main() {
    alumnos();
    return 0;
}