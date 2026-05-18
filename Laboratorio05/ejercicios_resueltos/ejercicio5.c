#include <stdio.h>
struct Point
{
    int x;
    int y;
};
int main()
{
    // Crear arreglo de estructuras
    struct Point arr[10];
    // Accediendo a los atributos
    arr[0].x = 10;
    arr[0].y = 20;
    printf("%d %d\n", arr[0].x, arr[0].y);
    return 0;
}