#include <stdio.h>
struct Punto
{
    int x;
    int y;
};
int main()
{
    struct Punto punto[7];
    for (int i = 0; i < 7; i++)
    {
        punto[i].x = i - 3;
        printf("Introduce la altura de la curva en %d: ",
               punto[i].x);
        scanf("%d", &punto[i].y);
        printf("\n");
    }
    printf("Las coordenadas son:\n");
    for (int i = 0; i < 7; i++)
    {
        printf("(%d,%d)\n",
               punto[i].x,
               punto[i].y);
    }
    return 0;
}