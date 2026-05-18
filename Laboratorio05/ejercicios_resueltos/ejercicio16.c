#include <stdio.h>
struct Student
{
    int roll;
};
void inicializar(struct Student *s, int x)
{
    s->roll = x;
}
int main()
{
    struct Student s;
    inicializar(&s, 2);
    printf("%d\n", s.roll);
    return 0;
}