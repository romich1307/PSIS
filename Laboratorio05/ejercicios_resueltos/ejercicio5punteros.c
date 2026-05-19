#include <stdio.h>
struct Point
{
    int x;
    int y;
};
int main()
{
    // Crear arreglo de estructuras
    struct Point p1[10];
    struct Point *ptr = p1;

    ptr->x = 10;
    ptr->y = 20;
    printf("%d %d\n", ptr->x, ptr->y);
    return 0;
}

