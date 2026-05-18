#include <stdio.h>
// Variable global
int x = 0;
struct Record
{
    int dato;
};
int main()
{
    struct Record r1, r2;
    x = 10;
    printf("Valor de x = %d\n", x);
    return 0;
}