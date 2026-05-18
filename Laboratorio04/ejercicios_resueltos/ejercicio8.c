#include <stdio.h>
int main() {
    int a = 5;

    // simulando referencias con punteros
    int *S = &a;
    int **S0 = &S;
    int ***S1 = &S0;

    printf("a = %d\n", a);
    printf("*S = %d\n", *S);
    printf("**S0 = %d\n", **S0);
    printf("***S1 = %d\n", ***S1);
    return 0;
}