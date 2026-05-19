#ifndef PRODUCTO_H
#define PRODUCTO_H

struct Producto
{
    char nombre[30];
    float precio;
    int cantidad;
};
void leerProducto(struct Producto *p);
void mostrarProducto(struct Producto p);
float calcularTotal(struct Producto p);
#endif
