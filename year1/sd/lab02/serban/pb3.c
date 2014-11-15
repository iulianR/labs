#include <stdio.h>

void cut(int v[], int n, int a, int b)
{
    if (a == b) {
		printf("%d\n", v[a]);
        return;
	}
    else {
        if ((n - 1)%2 == 0) {
			//cut(
			cut(v, n/2, a, n/2);
			cut(v, n/2, n/2 + 1, b);
		}
		else
			cut(v, n/2, a, n/2);
			cut(v, n/2, n/2 + 2, b);
    }
}

int main()
{
    int n = 9, v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, a = 0, b = 8;
    cut(v, n, a, b);
    return 0;
}
