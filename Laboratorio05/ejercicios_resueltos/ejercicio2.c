#include <stdio.h>
enum Color
{
    rojo,
    verde,
    azul
};
struct Libro
{
    char titulo[20];
    char autor[20];
    int anio;
    enum Color color;
};
void datosLibro(struct Libro libro[]);
void mostrarLibro(struct Libro libro[]);
int main()
{
    struct Libro libro[3];
    datosLibro(libro);
    mostrarLibro(libro);
    return 0;
}
void datosLibro(struct Libro libro[3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Titulo libro %d: ", i + 1);
        fgets(libro[i].titulo, 20, stdin);
        printf("Autor libro %d: ", i + 1);
        fgets(libro[i].autor, 20, stdin);
        printf("Anio libro %d: ", i + 1);
        scanf("%d", &libro[i].anio);
        getchar();
    }
    libro[0].color = rojo;
    libro[1].color = verde;
    libro[2].color = azul;
}
void mostrarLibro(struct Libro libro[3])
{
    for (int i = 0; i < 3; i++)
    {
        printf("Titulo: %s", libro[i].titulo);
        printf("Autor: %s", libro[i].autor);
        printf("Anio: %d\n", libro[i].anio);
        switch (libro[i].color)
        {
        case rojo:
            printf("Color: Rojo\n");
            break;
        case verde:
            printf("Color: Verde\n");
            break;
        case azul:
            printf("Color: Azul\n");
            break;
        }
        printf("\n");
    }
}