#include <stdio.h>

int main() {
    int opcion;
    int repetir = 1;
    do {
        printf("\nMenu de Opciones\n");
        printf("1. Opcion 1\n");
        printf("2. Opcion 2\n");
        printf("3. Opcion 3\n");
        printf("4. Opcion 4\n");
        printf("0. SALIR\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
            case 2:
            case 3:
            case 4:
                break;
            case 0:
                repetir = 0;
                break;
            }
        } while(repetir);
        return 0;
}
