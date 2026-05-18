#include <stdio.h>
struct Record
{
    int x;
};
int main()
{
    struct Record s = {7};
    printf("%d\n", s.x);
    return 0;
}