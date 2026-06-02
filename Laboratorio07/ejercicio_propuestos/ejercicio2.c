#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 12
#define CAPACIDAD_CACHE 4

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

/* Biblioteca de canciones */
Cancion biblioteca[HASH_SIZE];
int cancionRegistrada[HASH_SIZE];

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
        cancionRegistrada[posicion] = 0;
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

    nodo->prev = NULL;
    nodo->next = NULL;
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
        int codigoEliminado = nodoMenosReciente->key;

        printf("\nCache llena: Eliminando '%s' por ser la menos escuchada recientemente.\n",
               biblioteca[codigoEliminado].titulo);

        cache->hashTable[codigoEliminado] = NULL;
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

    cache->head = NULL;
    cache->tail = NULL;
    cache->size = 0;
}

void limpiarBuffer() {
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }
}

void leerTexto(char texto[], int tamano) {
    fgets(texto, tamano, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}

int buscarCodigoPorTitulo(char tituloBuscado[]) {
    for (int codigo = 0; codigo < HASH_SIZE; codigo++) {
        if (cancionRegistrada[codigo] == 1 &&
            strcmp(biblioteca[codigo].titulo, tituloBuscado) == 0) {
            return codigo;
        }
    }

    return -1;
}

void agregarCancion() {
    int codigo;
    char titulo[100];
    char artista[100];
    int duracion;

    printf("\nIngrese el codigo de la cancion (0 - %d): ", HASH_SIZE - 1);
    scanf("%d", &codigo);
    limpiarBuffer();

    if (codigo < 0 || codigo >= HASH_SIZE) {
        printf("Codigo invalido.\n");
        return;
    }

    if (cancionRegistrada[codigo] == 1) {
        printf("Ese codigo ya tiene una cancion registrada.\n");
        return;
    }

    printf("Ingrese el titulo de la cancion: ");
    leerTexto(titulo, 100);

    if (buscarCodigoPorTitulo(titulo) != -1) {
        printf("Ya existe una cancion con ese titulo.\n");
        return;
    }

    printf("Ingrese el artista: ");
    leerTexto(artista, 100);

    printf("Ingrese la duracion en segundos: ");
    scanf("%d", &duracion);
    limpiarBuffer();

    strcpy(biblioteca[codigo].titulo, titulo);
    strcpy(biblioteca[codigo].artista, artista);
    biblioteca[codigo].duracion = duracion;
    cancionRegistrada[codigo] = 1;

    printf("\nCancion agregada correctamente.\n");
}

void buscarCancion() {
    char tituloBuscado[100];

    printf("\nIngrese el titulo de la cancion a buscar: ");
    leerTexto(tituloBuscado, 100);

    int codigo = buscarCodigoPorTitulo(tituloBuscado);

    if (codigo == -1) {
        printf("Cancion no encontrada.\n");
        return;
    }

    printf("\nCancion encontrada:\n");
    printf("Codigo: %d\n", codigo);
    printf("Titulo: %s\n", biblioteca[codigo].titulo);
    printf("Artista: %s\n", biblioteca[codigo].artista);
    printf("Duracion: %d segundos\n", biblioteca[codigo].duracion);
}

void reproducirCancion(LRUCache *cache) {
    char tituloBuscado[100];

    printf("\nIngrese el titulo de la cancion a reproducir: ");
    leerTexto(tituloBuscado, 100);

    int codigo = buscarCodigoPorTitulo(tituloBuscado);

    if (codigo == -1) {
        printf("La cancion no existe. Primero debe agregarla.\n");
        return;
    }

    int reproduccionesActuales = obtenerValor(cache, codigo);

    if (reproduccionesActuales == -1) {
        insertarValor(cache, codigo, 1);

        printf("\nReproduciendo nueva cancion: %s - %s\n",
               biblioteca[codigo].titulo,
               biblioteca[codigo].artista);
    } else {
        insertarValor(cache, codigo, reproduccionesActuales + 1);

        printf("\nReproduciendo nuevamente: %s - %s\n",
               biblioteca[codigo].titulo,
               biblioteca[codigo].artista);

        printf("Reproducciones en cache: %d\n", reproduccionesActuales + 1);
    }
}

void mostrarCancionesRecientes(LRUCache *cache) {
    Node *nodoActual = cache->head;

    if (nodoActual == NULL) {
        printf("\nNo hay canciones recientes.\n");
        return;
    }

    printf("\nCanciones recientes:\n");
    printf("Mas reciente -> Menos reciente\n\n");

    while (nodoActual != NULL) {
        int codigo = nodoActual->key;

        printf("Titulo: %s | Artista: %s | Duracion: %d s | Reproducciones: %d\n",
               biblioteca[codigo].titulo,
               biblioteca[codigo].artista,
               biblioteca[codigo].duracion,
               nodoActual->value);

        nodoActual = nodoActual->next;
    }
}

void mostrarMenu() {
    printf("\n========== MENU SPOTIFY LRU ==========\n");
    printf("1. Agregar cancion\n");
    printf("2. Buscar cancion\n");
    printf("3. Reproducir cancion\n");
    printf("4. Mostrar canciones recientes\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}

int main() {
    LRUCache cacheSpotify;
    int opcion;

    inicializarCache(&cacheSpotify, CAPACIDAD_CACHE);

    do {
        mostrarMenu();
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                agregarCancion();
                break;

            case 2:
                buscarCancion();
                break;

            case 3:
                reproducirCancion(&cacheSpotify);
                break;

            case 4:
                mostrarCancionesRecientes(&cacheSpotify);
                break;

            case 5:
                printf("\nSaliendo del programa\n");
                break;

            default:
                printf("\nOpcion invalida.intente nuevamente.\n");
                break;
        }

    } while (opcion != 5);

    liberarCache(&cacheSpotify);

    return 0;
}