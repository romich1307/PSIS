#include <stdio.h>
// Función recursiva
void generar(char set[], char prefix[], int n, int k, int index) {
    // Caso base: cuando ya tenemos k caracteres
    if (index == k) {
        prefix[index] = '\0'; // cerrar cadena
        printf("%s\n", prefix);
        return;
    }
    // Probar cada carácter del conjunto
    for (int i = 0; i < n; i++) {
        prefix[index] = set[i]; // agregar carácter
        generar(set, prefix, n, k, index + 1);
    }
}
int main() {
    char set[] = {'a', 'b'};
    int k = 3;
    char prefix[10]; // buffer para la cadena
    printf("Primera prueba:\n");
    generar(set, prefix, 2, k, 0);
    return 0;
}