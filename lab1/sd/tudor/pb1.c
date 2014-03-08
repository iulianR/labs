#include <stdio.h>

int multipli(int n, int v[], int div)
{
    if (n < 0)
        return 0;
    else if (v[n - 1] % div == 0)
        return 1 + multipli(n - 1, v, div);
    else
        return multipli(n - 1, v, div);
}

int main()
{
    int v[5] = {12, 35, 45, 6, 5}, n = 5, div = 5;
    printf("nr = %d\n", multipli(n, v, div));
    return 0;
}
