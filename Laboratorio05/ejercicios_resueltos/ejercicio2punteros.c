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
        struct Libro *p = &libro[i];

        printf("Titulo libro %d: ", i + 1);
        fgets(p->titulo, 20, stdin);

        printf("Autor libro %d: ", i + 1);
        fgets(p->autor, 20, stdin);

        printf("Anio libro %d: ", i + 1);
        scanf("%d", &p->anio);
        getchar();

        if (i == 0)
        {
            p->color = rojo;
        }
        else if (i == 1)
        {
            p->color = verde;
        }
        else
        {
            p->color = azul;
        }
        printf("\n");
    }
}

void mostrarLibro(struct Libro libro[3])
{
    for (int i = 0; i < 3; i++)
    {
        struct Libro *p = &libro[i];

        printf("Titulo: %s", p->titulo);
        printf("Autor: %s", p->autor);
        printf("Anio: %d\n", p->anio);

        switch (p->color)
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