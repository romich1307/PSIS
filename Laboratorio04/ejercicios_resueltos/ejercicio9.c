#include <stdio.h>
void alumnos(){
    int val[3] = {5, 10, 20};

    int *ptr;
    ptr = val;
    printf("Elementos del arreglo son: ");
    printf("%d %d %d\n", *ptr, *(ptr+1), *(ptr+2));
}

int main(){
    alumnos();
    return 0;
}