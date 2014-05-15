#include <stdio.h>
#include <stdlib.h>

#define M 20
#define BIG 30000

typedef struct {
	int nrNodes;
	int nrArcs;
	int **a;
} Graph;

void initG (Graph &g, int n)
{
	g.nrNodes = n;
	g.nrArcs = 0;
	g.a = (int**) malloc ((n + 1) * sizeof(int*));
	for (int i = 1; i <= n; i++) {
		g.a[i] = (int*) malloc ((n + 1) * sizeof(int));
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			g.a[i][j] = BIG;
		}
	}
}

void addArc (Graph &g, int v, int w, int cost)
{
	g.a[v][w] = cost;
	g.nrArcs++;
}

void delArc (Graph &g, int v, int w)
{
	g.a[v][w] = BIG;
	g.nrArcs--;
}

int costArc (Graph &g, int v, int w)
{
	return g.a[v][w];
}

void delNode (Graph &g, int x)
{
	for (int i = 1; i <= g.nrNodes; i++) {
		delArc(g, x, i);
		delArc(g, i, x);
	}
}

void readG (Graph &g)
{
	int n;
	scanf("%d", &n);
	initG(g, n);
	int v, w, cost;
	while (1) {
		scanf("%d", &v);
		if (v == 0)
			break;
		scanf("%d %d", &w, &cost);
		addArc(g, v, w, cost);
	}
}

void printG (Graph g)
{
	for (int i = 1; i <= g.nrNodes; i++) {
		for (int j = 1; j <= g.nrNodes; j++)
			printf("%6d ", g.a[i][j]);
		printf("\n");
	}
}

int main()
{
	Graph g;
	readG(g);
	printG(g);
	delNode(g, 3);
	printf("Graful dupa stergerea nodului 3\n");
	printG(g);
	return 0;
}