#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo
{
    int valor;
    struct Nodo *siguiente;
} Nodo;

Nodo *crearCabecera();
void insertarNodo(Nodo *cabecera, int valor);
void imprimirNodo(Nodo *nodo);
void imprimirLista(Nodo *cabecera);
Nodo *buscarNodo(Nodo *cabecera, int valor);
void eliminarNodo(Nodo *cabecera, int valor);
void liberarLista(Nodo *cabecera);

#endif