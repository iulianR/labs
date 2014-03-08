#include <stdio.h>
#include <conio.h>

int first(int b, int a[], int i, int j)
{
    if (i == j) {
        return -1;
    }
    if (a[i] == b) {
        return i;
    }
    else {
        return first(b, a, i + 1, j);
    }
}

int main()
{
    int a[8] = {2, 5, 7, 9, 6, 5, 5, 11}, b = 5;
    int i = 0, j = 8;
    printf("a = %d\n", first(b, a, 0, 8));
    return 0;
}

