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

const char* estados_str[] = {"Moroso", "Aceptado", "Pagado"};

void leerClientes(Cliente *p, int n) {
    int estado_in;
    for (int i = 0; i < n; i++) {
        printf("\nCLIENTE %d\n", i + 1);
        printf("Ingrese nombre: ");
        scanf("%39s", p[i].nombre);

        printf("Ingrese unidades solicitadas: ");
        scanf("%d", &p[i].uniSolicitadas);

        printf("Ingrese precio unitario: ");
        scanf("%f", &p[i].precio);

        printf("Ingrese estado (1) moroso (2) aceptado (3) pagado: ");
        scanf("%d", &estado_in);
        if (estado_in == 1) {
            p[i].estado = moroso;
        } else if (estado_in == 2) {
            p[i].estado = aceptado;
        } else {
            p[i].estado = pagado;
        }
    }
}
void mostrarCliente(const Cliente *c, int idx) {
    float factura = c->precio * c->uniSolicitadas;
    printf("\nCLIENTE %d\n", idx + 1);
    printf("Nombre: %s\n", c->nombre);
    printf("Precio unitario: %.2f\n", c->precio);
    printf("Unidades solicitadas: %d\n", c->uniSolicitadas);
    printf("Factura (precio * unidades): %.2f\n", factura);
    printf("Estado: %s\n", estados_str[c->estado]);
}
void listarTodos(Cliente *p, int n) {
    for (int i = 0; i < n; i++) {
        mostrarCliente(&p[i], i);
    }
}
void listarMorosos(Cliente *p, int n) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].estado == moroso) {
            mostrarCliente(&p[i], i);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("\nNo hay clientes en estado moroso.\n");
    }
}

void listarPagadosMayor(Cliente *p, int n, float minimo) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].estado == pagado) {
            float factura = p[i].precio * p[i].uniSolicitadas;
            if (factura > minimo) {
                mostrarCliente(&p[i], i);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("\nNo hay clientes pagados con factura mayor a %.2f\n", minimo);
    }
}

int main(void) {
    int n;
    int opcion;
    printf("Facturacion de clientes\n");
    printf("Ingrese cantidad de clientes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Cantidad de clientes invalida.\n");
        return 1;
    }

    Cliente *p = malloc(n * sizeof(Cliente));
    if (!p) {
        fprintf(stderr, "Error\n");
        return 1;
    }

    leerClientes(p, n);

    do {
        printf("\n--- MENU ---\n");
        printf("1) Listar todos los clientes\n");
        printf("2) Listar clientes en estado moroso\n");
        printf("3) Listar clientes pagados con factura mayor a un monto\n");
        printf("4) Salir\n");
        printf("Seleccione una opcion: ");
        if (scanf("%d", &opcion) != 1) {
            break;
        }

        if (opcion == 1) {
            listarTodos(p, n);
        } else if (opcion == 2) {
            listarMorosos(p, n);
        } else if (opcion == 3) {
            float minimo;
            printf("Ingrese monto minimo:");
            if (scanf("%f", &minimo) == 1) {
                listarPagadosMayor(p, n, minimo);
            } else {
                printf("Monto invalido.\n");
            }
        } else if (opcion == 4) {
            printf("salir\n");
        } else {
            printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    free(p);
    return 0;
}