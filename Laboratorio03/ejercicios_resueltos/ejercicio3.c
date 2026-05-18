#include <stdio.h>

int main() {
    double x,y,z;
    printf("Introduzca el primer número: ");
    scanf("%lf", &x);
    printf("Introduzca el segundo número: ");
    scanf("%lf", &y);
    z = x + y;
    printf("%.2lf + %.2lf = %.2lf\n", x, y, z);
    return 0;
}