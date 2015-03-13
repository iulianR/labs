#include <stdio.h>

int *pivot, lWall;
void quicksort(int *, int, int);
int partition(int *, int, int);
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int n = 10, v[] = {5, 3, 7, 9, 11, 6, 3, 1, 5, 2};
    quicksort(v, 0, n);
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    return 0;
}

void quicksort(int v[], int l, int r)
{
    if (l < r) {
        pivot = partition(v, l, r);
        quicksort(v, l, pivot - 1);
        quicksort(v, pivot + 1, r);
    }
}

int partition(int v[], int l, int r)
{
    int i;
    pivot = l;
    lWall = l;
    for (i = l + 1; i < r; i++)
        if (v[i] < v[pivot]) {
            lWall = lWall + l;
            swap(v[i], v[lWall]);
    swap(v[l], v[lWall]);
    }
    return lWall;
}
