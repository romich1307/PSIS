#include <stdio.h>
#include <string.h>

struct Agenda {
    char nombre[50];
    char direccion[100];
    char telefono[20];
    char email[50];
    short dia;
    short mes;
    short anio;
};

int main() {
    struct Agenda fichas[100];
    FILE *archivo;
    int cantidad = 0;
    int opcion;
    char buscar[50];
    int encontrado;

    archivo = fopen("agenda.dat", "rb");

    if (archivo != NULL) {
        while (fread(&fichas[cantidad], sizeof(struct Agenda), 1, archivo) == 1) {
            cantidad++;
        }
        fclose(archivo);
    }

    do {
        printf("\n===== AGENDA =====\n");
        printf("1. Agregar nuevo dato\n");
        printf("2. Visualizar nombres existentes\n");
        printf("3. Visualizar datos de una persona\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                if (cantidad < 100) {
                    printf("Nombre: ");
                    fgets(fichas[cantidad].nombre, sizeof(fichas[cantidad].nombre), stdin);
                    fichas[cantidad].nombre[strcspn(fichas[cantidad].nombre, "\n")] = '\0';

                    printf("Direccion: ");
                    fgets(fichas[cantidad].direccion, sizeof(fichas[cantidad].direccion), stdin);
                    fichas[cantidad].direccion[strcspn(fichas[cantidad].direccion, "\n")] = '\0';

                    printf("Telefono movil: ");
                    fgets(fichas[cantidad].telefono, sizeof(fichas[cantidad].telefono), stdin);
                    fichas[cantidad].telefono[strcspn(fichas[cantidad].telefono, "\n")] = '\0';

                    printf("Email: ");
                    fgets(fichas[cantidad].email, sizeof(fichas[cantidad].email), stdin);
                    fichas[cantidad].email[strcspn(fichas[cantidad].email, "\n")] = '\0';

                    printf("Dia de nacimiento: ");
                    scanf("%hd", &fichas[cantidad].dia);

                    printf("Mes de nacimiento: ");
                    scanf("%hd", &fichas[cantidad].mes);

                    printf("Anio de nacimiento: ");
                    scanf("%hd", &fichas[cantidad].anio);
                    getchar();

                    cantidad++;
                } else {
                    printf("La agenda esta llena.\n");
                }
                break;

            case 2:
                printf("\nNombres existentes:\n");

                for (int i = 0; i < cantidad; i++) {
                    printf("%d. %s\n", i + 1, fichas[i].nombre);
                }
                break;

            case 3:
                printf("Ingrese el nombre de la persona: ");
                fgets(buscar, sizeof(buscar), stdin);
                buscar[strcspn(buscar, "\n")] = '\0';

                encontrado = 0;

                for (int i = 0; i < cantidad; i++) {
                    if (strcmp(fichas[i].nombre, buscar) == 0) {
                        printf("\nDatos encontrados:\n");
                        printf("Nombre: %s\n", fichas[i].nombre);
                        printf("Direccion: %s\n", fichas[i].direccion);
                        printf("Telefono movil: %s\n", fichas[i].telefono);
                        printf("Email: %s\n", fichas[i].email);
                        printf("Fecha de nacimiento: %hd/%hd/%hd\n",
                               fichas[i].dia,
                               fichas[i].mes,
                               fichas[i].anio);

                        encontrado = 1;
                    }
                }

                if (!encontrado) {
                    printf("No se encontro a la persona.\n");
                }
                break;

            case 4:
                archivo = fopen("agenda.dat", "wb");

                if (archivo == NULL) {
                    printf("Error al guardar el archivo.\n");
                    return 1;
                }

                fwrite(fichas, sizeof(struct Agenda), cantidad, archivo);
                fclose(archivo);

                printf("Datos guardados correctamente.\n");
                break;

            default:
                printf("Opcion no valida.\n");
        }

    } while (opcion != 4);

    return 0;
}