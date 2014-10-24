#include <stdio.h>

void space(int);

int main()
{
    int n = 1254;
    space(n);
    return 0;
}

void space(int n)
{
    if (!n)
        return;
    space(n/10);
    printf("%d ", n%10);
}
