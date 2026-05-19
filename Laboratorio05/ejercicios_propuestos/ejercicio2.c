#include <stdio.h>
#include <stdlib.h>
enum Estado {
    moroso,
    aceptado,
    pagado
};

typedef struct {
    char nombre [40];
    int uniSolicitadas;
    float precio;
    enum Estado estado;
} Cliente;

int main () {
    
    int estado = 1;
    int n;
    const char* estados[] = {"Moroso", "Aceptado", "Pagado"};
    
    printf("Facturacion de clientes\n");
    printf("Ingrese cantidad de clientes: ");
    
    scanf("%d", &n);
    Cliente *p = malloc(n * sizeof(Cliente));

    for (int i = 0 ; i < n ; i++) {
        printf("\nCLIENTE %d ", i+1);
        printf("\nIngrese nombre: ");
        scanf("%s", p[i].nombre);
        
        printf("Ingrese unidades solicitadas: ");
        scanf("%d", &p[i].uniSolicitadas);
        
        printf("Ingrese precio unitario: ");
        scanf("%f", &p[i].precio);
        
        printf("Ingrese estado (1) moroso (2) aceptado (3) pagado: ");
        scanf("%d", &estado);
        if (estado == 1) {
            p[i].estado = moroso;
        } else if (estado == 2) {
            p[i].estado = aceptado;
        } else {
            p[i].estado = pagado;
        }
    }

    for (int i = 0 ; i < n ; i++) {
        printf("\nCLIENTE %d ", i+1);
        printf("\nNombre: %s", p[i].nombre);
        printf("\nPrecio: %2f", p[i].precio);
        printf("\nUnidades solicitadas: %d", p[i].uniSolicitadas);
        
        if (p[i].estado == moroso) {
            printf("\nEstado: Moroso");
        } else if (p[i].estado == aceptado) {
            printf("\nEstado: Aceptado");
        } else {
            printf("\nEstado: Pagado");
        }
    }
}