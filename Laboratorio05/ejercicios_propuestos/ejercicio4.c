#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre [40];
    int victorias;
    int derrotas;
} Equipo;

typedef struct {
    Equipo equipo;
    int perdidas;
    int rebotes;
    char mejorAnotador [40];
    int triples;
} Baloncesto;

typedef struct {
    Equipo equipo;
    int empates;
    int goles;
    char goleador [40];
    int golesGoleador;
} Futbol;

int main () {    
    
    int n1, n2;
    
    printf("Resultados de Ligas\n");
    printf("Ingrese cantidad de equipos de baloncesto: ");
    scanf("%d", &n1);
    Baloncesto *b = malloc(n1 * sizeof(Baloncesto));

    printf("Ingrese cantidad de equipos de futbol: ");
    scanf("%d", &n2);
    Futbol *f = malloc(n2 * sizeof(Futbol));

    printf("\nLiga de Baloncesto");
    for (int i = 0 ; i < n1 ; i++) {
        printf("\nEquipo %d ", i+1);
        printf("\nIngrese nombre: ");
        scanf("%s", b[i].equipo.nombre);
        
        printf("Ingrese victorias: ");
        scanf("%d", &b[i].equipo.victorias);
        
        printf("Ingrese derrotas: ");
        scanf("%f", &b[i].equipo.derrotas);

        printf("Ingrese perdidas de balon: ");
        scanf("%d", &b[i].perdidas);
        
        printf("Ingrese rebotes recogidos: ");
        scanf("%d", &b[i].rebotes);

        printf("Ingrese mejor anotador de triples: ");
        scanf("%s", b[i].mejorAnotador);

        printf("Ingrese numero de triples del anotador: ");
        scanf("%d", &b[i].triples);
    }

    printf("\nLiga de Futbol");
    for (int i = 0 ; i < n2 ; i++) {
        printf("\nEquipo %d ", i+1);
        printf("\nIngrese nombre: ");
        scanf("%s", f[i].equipo.nombre);
        
        printf("Ingrese victorias: ");
        scanf("%d", &f[i].equipo.victorias);
        
        printf("Ingrese derrotas: ");
        scanf("%f", &f[i].equipo.derrotas);
        
        printf("Ingrese empates: ");
        scanf("%d", &f[i].empates);

        printf("Ingrese numero de goles: ");
        scanf("%d", &f[i].goles);

        printf("Ingrese nombre del goleador: ");
        scanf("%s", f[i].goleador);

        printf("Ingrese goles del goleador: ");
        scanf("%d", &f[i].golesGoleador);
    }

    free(b);
    free(f);
    return 0;
}