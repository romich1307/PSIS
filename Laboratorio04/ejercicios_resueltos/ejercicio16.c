#include <stdio.h>
void incrementar(void *data, int ptrsize) {
if (ptrsize == sizeof(char)) {
    char *ptrchar;
    // casteo a puntero char
    ptrchar = (char*) data;
    (*ptrchar)++;
    printf("El puntero apunta a un char\n");
}
else if (ptrsize == sizeof(int)) {
    int *ptrint;
    // casteo a puntero int
    ptrint = (int*) data;
    (*ptrint)++;
    printf("El puntero apunta a un int\n");
}
}
void alumno() {
    char c = 'x';
    int i = 10;
    incrementar(&c, sizeof(c));
    printf("Nuevo valor de c: %c\n", c);
    incrementar(&i, sizeof(i));
    printf("Nuevo valor de i: %d\n", i);
}
int main() {
    alumno();
    return 0;
}