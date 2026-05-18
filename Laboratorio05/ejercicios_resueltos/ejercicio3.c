#include <stdio.h>
struct Point
{
    int x;
    int y;
};
int main()
{
    struct Point p1;
    // Inicialización manual
    p1.x = 0;
    p1.y = 1;
    printf("x = %d, y = %d\n", p1.x, p1.y);
    // Modificando el valor de y
    p1.y = 20;
    printf("x = %d, y = %d\n", p1.x, p1.y);
    return 0;
}