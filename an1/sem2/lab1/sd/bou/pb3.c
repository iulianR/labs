#include <stdio.h>

int euclid(a, b) 
{
	if (a == b)
		return a;
	else if (b != 0)
		if (a > b)
			return euclid(a - b, b);
		else
			return euclid(a, b - a);
}
int main()
{
	printf("rez = %d\n", euclid(30, 10));
	return 0;
}
