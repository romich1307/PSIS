#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HASH_SIZE 12

typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    char titulo[100];
    char artista[100];
    int duracion;
} Cancion;

typedef struct {
    int capacity;
    int size;
    Node *head;
    Node *tail;
    Node *hashTable[HASH_SIZE];
} LRUCache;

Node *crearNodo(int clave, int valor) {
    Node *nuevoNodo = (Node *)malloc(sizeof(Node));

    if (nuevoNodo == NULL) {
        printf("Error al reservar memoria.\n");
        exit(1);
    }

    nuevoNodo->key = clave;
    nuevoNodo->value = valor;
    nuevoNodo->prev = NULL;
    nuevoNodo->next = NULL;

    return nuevoNodo;
}

void inicializarCache(LRUCache *cache, int capacidad) {
    cache->capacity = capacidad;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;

    for (int posicion = 0; posicion < HASH_SIZE; posicion++) {
        cache->hashTable[posicion] = NULL;
    }
}

void agregarAlInicio(LRUCache *cache, Node *nodo) {
    nodo->prev = NULL;
    nodo->next = cache->head;

    if (cache->head != NULL) {
        cache->head->prev = nodo;
    }

    cache->head = nodo;

    if (cache->tail == NULL) {
        cache->tail = nodo;
    }
}

void quitarNodo(LRUCache *cache, Node *nodo) {
    if (nodo->prev != NULL) {
        nodo->prev->next = nodo->next;
    } else {
        cache->head = nodo->next;
    }

    if (nodo->next != NULL) {
        nodo->next->prev = nodo->prev;
    } else {
        cache->tail = nodo->prev;
    }
}

void moverAlInicio(LRUCache *cache, Node *nodo) {
    if (cache->head == nodo) {
        return;
    }

    quitarNodo(cache, nodo);
    agregarAlInicio(cache, nodo);
}

int obtenerValor(LRUCache *cache, int clave) {
    Node *nodoEncontrado = cache->hashTable[clave];

    if (nodoEncontrado == NULL) {
        return -1;
    }

    moverAlInicio(cache, nodoEncontrado);
    return nodoEncontrado->value;
}

void insertarValor(LRUCache *cache, int clave, int valor) {
    Node *nodoExistente = cache->hashTable[clave];

    if (nodoExistente != NULL) {
        nodoExistente->value = valor;
        moverAlInicio(cache, nodoExistente);
        return;
    }

    Node *nuevoNodo = crearNodo(clave, valor);

    if (cache->size == cache->capacity) {
        Node *nodoMenosReciente = cache->tail;

        cache->hashTable[nodoMenosReciente->key] = NULL;
        quitarNodo(cache, nodoMenosReciente);
        free(nodoMenosReciente);

        cache->size--;
    }

    agregarAlInicio(cache, nuevoNodo);
    cache->hashTable[clave] = nuevoNodo;
    cache->size++;
}

void liberarCache(LRUCache *cache) {
    Node *nodoActual = cache->head;

    while (nodoActual != NULL) {
        Node *nodoSiguiente = nodoActual->next;
        free(nodoActual);
        nodoActual = nodoSiguiente;
    }
}

int main() {
    // Code

    return 0;
} 