#include <stdio.h>

int main() {
    int edad;
    printf("Ingresa su edad: ");
    if (scanf("%d", &edad) == 1) {
        printf("Tu edad es: %d\n", edad);
    }
    return 0;
}