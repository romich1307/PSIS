#include <stdio.h>

void funcion1() { printf("\nFuncion 1\n"); }
void funcion2() { printf("\nFuncion 2\n"); }
void funcion3() { printf("\nFuncion 3\n"); }
void funcion4() { printf("\nFuncion 4\n"); }
int main() {
    int opcion;
    int repetir = 1;
    do {
        printf("\nMenu de Opciones\n");
        printf("1. Funcion 1\n");
        printf("2. Funcion 2\n");
        printf("3. Funcion 3\n");
        printf("4. Funcion 4\n");
        printf("0. SALIR\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1: funcion1(); break;
            case 2: funcion2(); break;
            case 3: funcion3(); break;
            case 4: funcion4(); break;
            case 0: repetir = 0; break;
        }
    } while(repetir);
    return 0;
}