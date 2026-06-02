#include <stdio.h>

struct Tdato {
    int b;
    char s[100];
};
int main() {
    int x, n, a[10]={1,2,3,4,5,6,7,8,9,0};
    double f;
    char nombre[]="ejercicios ficheros binarios";
    struct Tdato p;
    FILE *f1;
    FILE *f2;
    f1 = fopen("entrada.dat", "r");
    f2 = fopen("salida.dat", "w");
    if (f1==NULL||f2==NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }
    fscanf(f1, "%d", &x);
    fscanf(f1, "%lf", &f);
    for(int i = 0; i < 5; i++) {
        fscanf(f1, "%d", &a[i]);
    }
    fgetc(f1); 
    fgets(nombre, 40, f1); 
    fscanf(f1, "%d ", &p.b);
    fgets(p.s, 100, f1); 
    fprintf(f2, "%d\n", x);
    fprintf(f2, "%lf\n", f);
    for(int i = 0; i < 5; i++) {
        fprintf(f2, "%d ", a[i]);
    }
    fprintf(f2, "\n");
    fprintf(f2, "%s", nombre); 
    fprintf(f2, "%d %s", p.b, p.s); 
    fclose(f1);
    fclose(f2);
    return 0;
}
