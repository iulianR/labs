#include <stdio.h>

int search(int a, int b, int guess)
{
	if (guess == 0) {
		return 0;
	}
	else {
		int mid = (a + b)/2;
		
		printf("%d?\n", mid);
		scanf("%d", &guess);
		
		if (guess == 1)
			return search(mid + 1, b, guess);
		else if (guess == -1)
			return search(a, mid - 1, guess);
		else printf("OK\n");
	}
}

int main()
{
	search(1, 1000, -1);
	return 0;
}
