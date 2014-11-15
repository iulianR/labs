#include <stdio.h>

int count(int b, int a[], int n)
{
        if (n < 0)
            return 0;
        else
            if (a[n - 1] == b)
                return 1 + count(b, a, n - 1);
            else
                return count(b, a, n - 1);
}

int main()
{
    int n = 8, a[] = {5, 2, 5, 4, 3, 3, 5, 5}, b = 5;
    printf("nr = %d\n", count(b, a, n));
    return 0;
}
