#include <stdio.h>
#include "lista.h"

int main()
{
    Nodo *cabecera = crearCabecera();

    insertarNodo(cabecera, 10);
    insertarNodo(cabecera, 20);
    insertarNodo(cabecera, 30);
    insertarNodo(cabecera, 40);

    printf("Lista original:\n");
    imprimirLista(cabecera);

    eliminarNodo(cabecera, 40);

    printf("Lista despues de eliminar 40:\n");
    imprimirLista(cabecera);

    printf("Buscando 40\n");

    Nodo *resultado = buscarNodo(cabecera, 40);

    if (resultado != NULL)
    {
        printf("Nodo encontrado:\n");
        imprimirNodo(resultado);
    }
    else
    {
        printf("Nodo no encontrado.\n");
    }

    liberarLista(cabecera);

    return 0;
}