#include <stdio.h>
struct Producto
{
    char nombre[30];
    float precio;
    int cantidad;
};

struct Producto p1;
struct Producto *ptr=&p1;

int main(){
    printf("Ingrese el nombre del producto: ");
    scanf("%s", ptr->nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &ptr->precio);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &ptr->cantidad);

    printf("\nProducto registrado:\n");
    printf("Nombre: %s\n", ptr->nombre);
    printf("Precio: %.2f\n", ptr->precio);
    printf("Cantidad: %d\n", ptr->cantidad);
    printf("Total: %.2f\n", ptr->cantidad * ptr->precio);

    return 0;
}