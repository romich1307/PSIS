#include <stdio.h>
struct Point
{
    int x;
    int y;
};
int main()
{
    struct Point p1 = {1, 2};
    // p2 es un puntero a la estructura p1
    struct Point *p2 = &p1;
    // Accediendo a los atributos usando el operador ->
    printf("%d %d\n", p2->x, p2->y);
    return 0;
}