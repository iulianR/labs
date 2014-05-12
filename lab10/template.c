#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
	int n, m;
	int **a;
} Graph;

void initG(Graph &g, int n)
{
	g.n = n;
	g.m = 0;
	g.a = (int**) malloc ((n + 1) * sizeof(int*));

	for (int i = 1; i <= n; i++) {
		g.a[i] = (int*) malloc ((n + 1) * sizeof(int));
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			g.a[i][j] = MAX;
		}
	}
}

void addArc(Graph &g, int x, int y)
{
	g.a[x][y] = 1;
	g.m++;
}

void addWArc(Graph &g, int x, int y, int cost)
{
	g.a[x][y] = cost;
	g.m++;
}

int isArc(Graph g, int x, int y)
{
	return g.a[x][y];
}

void delArc(Graph &g, int x, int y)
{
	g.a[x][y] = 0;
	g.m--;
}

void delNode(Graph &g, int x)
{
	for (int i = 1; i <= g.n; i++) {
		delArc(g, x, i);
		delArc(g, i, x);
	}
}

void printGraph(Graph g)
{
	for (int i = 1; i <= g.n; i++) {
		for (int j = 1; j <= g.n; j++)
			printf("%4d ", g.a[i][j]);
		printf("\n");
	}
}

int *dijkstra(Graph &g, int p[])
{
	int d[g.n], s[g.n];
	for (int i = 1; i <= g.n; i++)
		s[i] = 0;
	int dmin, jmin, i, j;
	for (i = 2; i <= g.n; i++) {
		p[i] = 1; d[i] = isArc(g, 1, i);
	}
	s[1] = 1;
	for (i = 2; i <= g.n; i++) {
		dmin = MAX;
		for (j = 2; j <= g.n; j++)
			if (s[j] == 0 && dmin > d[j]) {
				dmin = d[j]; jmin = j;
			}
		s[jmin] = 1;
		for (j = 2; j <= g.n; j++)
			if (d[j] > d[jmin] + isArc(g, jmin, j)) {
				d[j] = d[jmin] + isArc(g, jmin, j);
				p[j] = jmin;
			}
	}
	for (int i = 1; i <= g.n; i++) {
		printf("s = %d ", s[i]);
		printf("d = %d\n", d[i]);
	}
	return d;
}

int main()
{
	Graph g;
	//initG(g, 7);
	// addWArc(g, 1, 7, 14);
	// addWArc(g, 7, 3, 2);
	// addWArc(g, 7, 5, 9);
	// addWArc(g, 3, 1, 9);
	// addWArc(g, 1, 3, 9);
	// addWArc(g, 2, 1, 7);
	// addWArc(g, 2, 3, 10);
	// addWArc(g, 2, 4, 15);
	// addWArc(g, 4, 2, 15);
	// addWArc(g, 3, 4, 11);
	// addWArc(g, 4, 5, 6);
	// addWArc(g, 5, 6, 5);

	initG(g, 5);
	addWArc(g, 1, 2, 5);
	addWArc(g, 1, 4, 2);
	addWArc(g, 1, 5, 6);
	addWArc(g, 2, 3, 3);
	addWArc(g, 3, 2, 4);
	addWArc(g, 3, 5, 4);
	addWArc(g, 4, 2, 2);
	addWArc(g, 4, 3, 7);
	addWArc(g, 4, 5, 3);
	addWArc(g, 5, 3, 3);

	//printGraph(g);

	int p[200], *d;
	d = dijkstra(g, p);
	printf("\n");
	for (int i = 2; i <= g.n; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
	// for (int i = 1; i <= g.n; i++) {
	// 	printf("%d ", d[i]);
	// }
	//printGraph(g);
	return 0;
}