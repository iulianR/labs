#include <stdio.h>

int putere(int a, int b)
{
	if (b == 0)
		return 1;
	else
		return a * putere(a, b - 1);
}

int suma_puteri(int x, int n)
{
	if (n < 0)
		return 0;
	else
		return putere(x, n) + suma_puteri(x, n - 1);

}


int main()
{
	printf("Rez: %d\n", putere(2, 3));
	printf("Rez2: %d\n", suma_puteri(2, 3));
	return 0;
}
