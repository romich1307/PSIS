#include <stdio.h>
    int main() {
    int arr[] = {10, 20};
    int x = 10;
    int *ptr = &x; // correcto
    arr = &x; // ERROR: no permitido
    return 0;
}
