#include <stdio.h>
int main() {
    FILE *archivo;
    char nombre[50];
    int edad;
    char carrera[50];
    char linea[100];
    printf("Ingrese su nombre: ");
    fgets(nombre, 50, stdin);
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    getchar();
    printf("Ingrese su carrera: ");
    fgets(carrera, 50, stdin);
    archivo = fopen("ejercicio1.txt", "w");
    if (archivo==NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }
    fprintf(archivo, "Nombre: %s", nombre);
    fprintf(archivo, "Edad: %d\n", edad);
    fprintf(archivo, "Carrera: %s", carrera);
    fclose(archivo);

    archivo = fopen("ejercicio1.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    printf("\nContenido del archivo:\n");

    fgets(linea,100, archivo);
        printf("%s", linea);

    fclose(archivo);
    return 0;
}