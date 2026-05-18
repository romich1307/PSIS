#include <stdio.h>

int main() {
    int m;
    printf("\n\t\tELija una opcion\n\n");
    printf("1. Ingreso\n");
    printf("2. Modificación\n");
    printf("3. Consultas\n");
    printf("4. Reportes\n");
    printf("5. Utilidades\n");
    printf("6. Salir\n");
    scanf("%d", &m);

    switch (m){
        case 1: printf("Ud tiene S/. 2500\n"); break;
        case 2: printf("¿Que desea modificar?\n"); break;
        case 3: printf("Escriba su consulta aqui:\n"); break;
        case 4: printf("Ud. no presenta reportes\n"); break;
        case 5: printf("Servicio bloqueado\n"); break;
        case 6: printf("Ya esta fuera\n"); break;
        default: printf("Opcion invalida\n");
    }
    return 0;
}