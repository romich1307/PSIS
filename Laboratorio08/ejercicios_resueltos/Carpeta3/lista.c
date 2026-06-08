#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Nodo *crearCabecera()
{
    Nodo *cabecera = (Nodo *)malloc(sizeof(Nodo));

    if (cabecera == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(1);
    }

    cabecera->siguiente = NULL;
    return cabecera;
}

void insertarNodo(Nodo *cabecera, int valor)
{
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nuevoNodo == NULL)
    {
        printf("Error al reservar memoria.\n");
        exit(1);
    }

    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = NULL;

    Nodo *actual = cabecera;

    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevoNodo;
}

void imprimirNodo(Nodo *nodo)
{
    printf("-----------------------------\n");
    printf("Direccion : %p\n", (void *)nodo);
    printf("Valor     : %d\n", nodo->valor);
    printf("Siguiente : %p\n", (void *)nodo->siguiente);
    printf("-----------------------------\n");
}

void imprimirLista(Nodo *cabecera)
{
    Nodo *actual = cabecera->siguiente;

    while (actual != NULL)
    {
        imprimirNodo(actual);
        actual = actual->siguiente;
    }

    printf("NULL\n");
}

Nodo *buscarNodo(Nodo *cabecera, int valor)
{
    Nodo *actual = cabecera->siguiente;

    while (actual != NULL)
    {
        if (actual->valor == valor)
        {
            return actual;
        }

        actual = actual->siguiente;
    }

    return NULL;
}

void eliminarNodo(Nodo *cabecera, int valor)
{
    Nodo *anterior = cabecera;
    Nodo *actual = cabecera->siguiente;

    while (actual != NULL)
    {
        if (actual->valor == valor)
        {
            anterior->siguiente = actual->siguiente;
            free(actual);
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    }
}

void liberarLista(Nodo *cabecera)
{
    Nodo *actual = cabecera;

    while (actual != NULL)
    {
        Nodo *temporal = actual;
        actual = actual->siguiente;
        free(temporal);
    }
}