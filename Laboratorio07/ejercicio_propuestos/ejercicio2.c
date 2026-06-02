#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HASH_SIZE 20000
#define CAPACIDAD_CACHE 1000

typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

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

void ejecutarPrueba(int cantidadOperaciones) {
    LRUCache cache;
    inicializarCache(&cache, CAPACIDAD_CACHE);

    int aciertos = 0;
    int fallos = 0;

    clock_t inicio = clock();

    for (int operacion = 0; operacion < cantidadOperaciones; operacion++) {
        int tipoOperacion = rand() % 2;
        int claveAleatoria = rand() % HASH_SIZE;
        int valorAleatorio = rand() % 100000;

        if (tipoOperacion == 0) {
            int resultado = obtenerValor(&cache, claveAleatoria);

            if (resultado != -1) {
                aciertos++;
            } else {
                fallos++;
            }
        } else {
            insertarValor(&cache, claveAleatoria, valorAleatorio);
        }
    }

    clock_t fin = clock();

    double tiempoEjecucion = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Operaciones realizadas: %d\n", cantidadOperaciones);
    printf("Capacidad del cache: %d\n", CAPACIDAD_CACHE);
    printf("Aciertos: %d\n", aciertos);
    printf("Fallos: %d\n", fallos);
    printf("Tiempo de ejecucion: %.6f segundos\n", tiempoEjecucion);
    printf("-------------------------------------\n");

    liberarCache(&cache);
}

int main() {
    srand(time(NULL));

    ejecutarPrueba(10000);
    ejecutarPrueba(50000);
    ejecutarPrueba(100000);

    return 0;
} 