#include <stdio.h>
#include <conio.h>

int count(int b, int a[], int n)
{
    if(n == 0)
        return 0;
    else if (a[n] == b)
        return 1 + count(b, a, n - 1);
    else
        return count(b, a, n - 1);
}

int main()
{
    int a[8] = {2, 5, 7, 9, 6, 5, 5, 11}, b =5;
    printf("%d\n", count(b, a, 7));
    return 0;
}
