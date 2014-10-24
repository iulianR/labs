#include <stdio.h>

int last(int a[], int n, int b)
{
    if (n < 0)
        return -1;
    else
        if (a[n - 1] == b)
            return n - 1;
        else return last(a, n - 1, b);
}

int main()
{
    int n = 8, a[] = {3, 3, 3, 4, 3, 3, 3, 6}, b = 5;
    printf("last: %d\n", last(a, n, b));
    return 0;
}
