#include <stdio.h>

int suma(int v[], int a, int b)
{
	if (b < a)
		return 0;
	else 
		return v[b - 1] + suma(v, a, b - 1);
}


int main()
{
	int v[] = {1, 2, -3, 0, 2, 1, 10}, n = 6, a = 2, b = 5;
	printf("Suma = %d\n", suma(v, a, b));
	return 0;
}
