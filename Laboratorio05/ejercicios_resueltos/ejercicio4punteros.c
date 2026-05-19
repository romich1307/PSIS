#include <stdio.h>
struct Point
{
    int x;
    int y;
};
int main()
{
    struct Point p1 = {0, 1};
    struct Point *ptr = &p1;
    ptr->x = 20;

    printf("x = %d, y = %d\n", ptr->x, ptr->y);
    return 0;
}
