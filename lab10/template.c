#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n, m;
	int **a;
} Graph;

void initG(Graph &g, int n)
{
	int i;
	g.n = n;
	g.m = 0;
	g.a = (int**) malloc ((n + 1) * sizeof(int*));

	for (i = 1; i <= n; i++)
		g.a[i] = (int*) calloc ((n + 1) * sizeof(int));
}

void addArc(Graph &g, int x, int y)
{
	g.a[x][y] = 1;
	g.m++;
}

int arc(Graph g, int x, int y)
{
	return g.a[x][y];
}

void delArc(Graph &g, int x, int y)
{
	g.a[x][y] = 0;
	g.m--;
}

void delNod(Graph &g, int x) {
	int i;
	for (i = 1; i <= g.n; i++) {
		delArc(g, x, i);
		delArc(g, i, x);
	}
}

int main()
{

	return 0;
}