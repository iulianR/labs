#include <stdio.h>

int divsSum(int n, int div);
void split(int v[], int n, int v1[], int *n1, int v2[], int *n2);

int main()
{
    int v[] = {28, 21, 6, 10}, n = 4, v1[4], v2[4], n1 = 0, n2 = 0;
    split(v, n - 1, v1, &n1, v2, &n2);
    int i;
    for (i = 0; i < n1; i ++)
        printf("%d ", v1[i]);
		//printf("BLA");
    printf("\n");
    for (i = 0; i < n2; i++)
        printf("%d ", v2[i]);
    printf("\n");
    return 0;
}

int divsSum(int n, int div)
{
    if (div == 0)
        return 0;
    else
        if (n % div == 0)
            return div + divsSum(n, div - 1);
        else
            return divsSum(n, div - 1);
}

void split(int v[], int n, int *v1, int *n1, int *v2, int *n2)
{
    if (n < 0)
        return;
    else {
        if (v[n] == divsSum(v[n], v[n] - 1)) {
            v1[*n1] = v[n];
			(*n1)++;
            split(v, n - 1, v1, n1, v2, n2);
        }
        else {
            v2[*n2] = v[n];
			(*n2)++;
            split(v, n - 1, v1, n1, v2, n2);
        }
    }
}
