#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void leer_string(const char *prompt, char *buf, size_t size) {
    printf("%s", prompt);
    if (scanf("%39s", buf) != 1) {
        buf[0] = '\0';
    }
}

int main () {
    int n1 = 0, n2 = 0;

    printf("Resultados de Ligas\n");
    printf("Ingrese cantidad de equipos de baloncesto: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) return 1;
    Baloncesto *b = malloc(n1 * sizeof(Baloncesto));
    if (!b && n1>0) return 1;

    printf("Ingrese cantidad de equipos de futbol: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) { free(b); return 1; }
    Futbol *f = malloc(n2 * sizeof(Futbol));
    if (!f && n2>0) { free(b); return 1; }

    for (int i = 0 ; i < n1 ; i++) {
        printf("\nBaloncesto - Equipo %d\n", i+1);
        leer_string("Ingrese nombre: ", b[i].equipo.nombre, sizeof(b[i].equipo.nombre));

        printf("Ingrese victorias: ");
        scanf("%d", &b[i].equipo.victorias);

        printf("Ingrese derrotas: ");
        scanf("%d", &b[i].equipo.derrotas);

        printf("Ingrese perdidas de balon: ");
        scanf("%d", &b[i].perdidas);

        printf("Ingrese rebotes recogidos: ");
        scanf("%d", &b[i].rebotes);

        leer_string("Ingrese mejor anotador de triples: ", b[i].mejorAnotador, sizeof(b[i].mejorAnotador));

        printf("Ingrese numero de triples del anotador: ");
        scanf("%d", &b[i].triples);
    }

    for (int i = 0 ; i < n2 ; i++) {
        printf("\nFutbol - Equipo %d\n", i+1);
        leer_string("Ingrese nombre: ", f[i].equipo.nombre, sizeof(f[i].equipo.nombre));

        printf("Ingrese victorias: ");
        scanf("%d", &f[i].equipo.victorias);

        printf("Ingrese derrotas: ");
        scanf("%d", &f[i].equipo.derrotas);

        printf("Ingrese empates: ");
        scanf("%d", &f[i].empates);

        printf("Ingrese numero de goles: ");
        scanf("%d", &f[i].goles);

        leer_string("Ingrese nombre del goleador: ", f[i].goleador, sizeof(f[i].goleador));

        printf("Ingrese goles del goleador: ");
        scanf("%d", &f[i].golesGoleador);
    }

    printf("\n--- Mejores anotadores de triples por equipo (Baloncesto) ---\n");
    if (n1 == 0) printf("No hay equipos de baloncesto.\n");
    for (int i = 0; i < n1; i++) {
        printf("%s : %s (%d triples)\n", b[i].equipo.nombre, b[i].mejorAnotador, b[i].triples);
    }

    if (n2 == 0) {
        printf("\nNo hay equipos de futbol.\n");
    } else {
        int idxMaxGoleador = 0;
        for (int i = 1; i < n2; i++) {
            if (f[i].golesGoleador > f[idxMaxGoleador].golesGoleador) idxMaxGoleador = i;
        }
        printf("\n--- Máximo goleador de la liga de futbol ---\n");
        printf("%s (equipo %s) - %d goles\n",
               f[idxMaxGoleador].goleador,
               f[idxMaxGoleador].equipo.nombre,
               f[idxMaxGoleador].golesGoleador);
    }

    /* 3) Calcular puntos: victoria = 3, empate = 1 */
    /* 4) Equipo ganador de la liga de futbol (por puntos) */
    if (n2 > 0) {
        int idxGanadorFut = 0;
        int maxPuntos = f[0].equipo.victorias * 3 + f[0].empates;
        for (int i = 1; i < n2; i++) {
            int puntos = f[i].equipo.victorias * 3 + f[i].empates;
            if (puntos > maxPuntos) {
                maxPuntos = puntos;
                idxGanadorFut = i;
            }
        }
        printf("\n--- Liga de Futbol ---\n");
        printf("Equipo ganador: %s con %d puntos (Victorias: %d, Empates: %d, Derrotas: %d)\n",
               f[idxGanadorFut].equipo.nombre,
               maxPuntos,
               f[idxGanadorFut].equipo.victorias,
               f[idxGanadorFut].empates,
               f[idxGanadorFut].equipo.derrotas);
    }

    if (n1 > 0) {
        int idxGanadorBal = 0;
        int maxVictorias = b[0].equipo.victorias;
        for (int i = 1; i < n1; i++) {
            if (b[i].equipo.victorias > maxVictorias) {
                maxVictorias = b[i].equipo.victorias;
                idxGanadorBal = i;
            }
        }
        printf("\nLiga de Baloncesto \n");
        printf("Equipo ganador: %s con %d victorias (Derrotas: %d)\n",
               b[idxGanadorBal].equipo.nombre,
               b[idxGanadorBal].equipo.victorias,
               b[idxGanadorBal].equipo.derrotas);
    }

    free(b);
    free(f);
    return 0;
}