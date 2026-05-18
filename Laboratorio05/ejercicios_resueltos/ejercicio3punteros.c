#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Point p1;
    struct Point *ptr;

    ptr = &p1;  // ptr apunta a p1

    // Inicialización usando puntero
    ptr->x = 0;
    ptr->y = 1;

    printf("x = %d, y = %d\n", ptr->x, ptr->y);

    // Modificando el valor de y usando puntero
    ptr->y = 20;

    printf("x = %d, y = %d\n", ptr->x, ptr->y);

    return 0;
}