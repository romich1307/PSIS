#include <stdio.h>
struct marks
{
    int num;
};
void Set(struct marks *m, int temp)
{
    m->num = temp;
}
void display(struct marks m)
{
    printf("num = %d\n", m.num);
}
int main()
{
    struct marks m1;
    Set(&m1, 9);
    display(m1);
    return 0;
}