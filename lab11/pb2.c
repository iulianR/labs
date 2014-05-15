#include <stdio.h>
#include <stdlib.h>

#define M 20
#define BIG 30000

//typedef char nod;
int x[M], xopt[M];
int Cost[M][M];
int n;
int cmin;

int posibil2 (int k)
{
	if (Cost[x[k - 1]][x[k]] == BIG)
		return 0;
	if (Cost[x[n]][x[1]] < BIG)
		return 1;
	for (int i = 1; i <= k -1; i++)
		if (x[k] != x[i])
			return 1;

}

int posibil(int k )
{
	int ok, i;
	if (Cost[x[k-1]][x[k]] == BIG)
		return 0;
	i = 1;
	for (i = 1; i <= k -1; i++)
		if (x[k] == x[i])
			return 0;
}

void memsol()
{
	int ccmin = 0;
	for (int i = 1; i < n; i++)
		ccmin += Cost[x[i]][x[i + 1]];
	ccmin += Cost[x[n]][x[1]];

	if (ccmin < cmin) {
		for (int i = 1; i <= n; i++)
			xopt[i] = x[i];
		cmin = ccmin;
	}
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", xopt[i]);
	// printf("\n");
}

void cautsol (int k)
{
	int i;
	if (k == n + 1)
		memsol();
	else
		for (i = 1; i <= n; i++) {
			x[k] = i;
			if (posibil (k))
				cautsol(k + 1);
		}
}

void citgraf()
{
	int i, j, cost;
	printf ("Numar de noduri: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			Cost[i][j] = BIG;
	printf("Costuri arce: i, j, cost[i][j] \n");
	while (scanf ("%d%d%d", &i, &j, &cost) == 3)
		Cost[i][j] = Cost[j][i] = cost;
}

int main()
{
	int i;
	cmin = BIG;
	citgraf();
	x[1] = 1;
	cautsol(2);
	printf("Cost minim = %d\n", cmin);
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		printf("%6d ", Cost[i][j]);
	// 	printf("\n");
	// }
	for (int i = 1; i <= n; i++)
		printf("%d-", xopt[i]);
	printf("1");
	printf("\n");
	return 0;
}