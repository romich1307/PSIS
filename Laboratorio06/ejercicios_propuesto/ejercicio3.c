#include <stdio.h>
#include <string.h>

int main() {
    FILE *archivo;
    char frase[200];
    archivo = fopen("frases.txt", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }
    printf("Ingrese frases, prresione enter sin escribir nada para terminar.\n");
    while (1) {
        printf("Frase: ");
        fgets(frase, 200 , stdin);
        if (strcmp(frase, "\n") == 0) {
            break;
        }
        fprintf(archivo, "%s", frase);
    }
    fclose(archivo);
    archivo = fopen("frases.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    printf("\nFrases:\n");

    while (fgets(frase, 200, archivo) != NULL) {
        printf("%s", frase);
    }
    fclose(archivo);
    return 0;
}