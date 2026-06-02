#include <stdio.h>
int main() {
    FILE *archivo;
    char nombreArchivo[100];
    char linea[200];
    int contador = 0;
    printf("Ingrese el nombre el fichero: ");
    scanf("%s", nombreArchivo);
    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error: no se pudo encontrar el fichero.\n");
        return 1;
    }
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
        contador++;
        if (contador == 25) {
            printf("\nPresione enter para continuar");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            getchar();
            contador = 0;
        }
    }
    fclose(archivo);
    return 0;
}