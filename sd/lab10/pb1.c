#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int data;
	struct nod* leg;
} *pnod;

typedef struct {
	int n;
	pnod *v;
} Graf;

void initG (Graf &g, int n)
{
	g.n = n;
	g.v = (pnod*) calloc (n + 1, sizeof(pnod));
}

void addM (Graf &g, int x, int y)
{
	pnod nou = (pnod) malloc (sizeof(nod));
	nou->data = y;
	nou->leg = g.v[x];
	g.v[x] = nou; // adaugam la inceput
}

void build (Graf &g, int m, int v[], int w[])
{
	for (int i = 0; i < m; i++) {
		addM(g, v[i], w[i]);
		addM(g, w[i], v[i]);
	}
}

void delV (Graf &g, int v)
{
	for (int i = 1; i <= g.n; i++) {
		pnod p;
		if (i == v) {
			p = g.v[i];
			while (p != NULL) {
				pnod t = p;
				p = p->leg;
				free(t); t = NULL;
			}
			continue;
		}
		for (p = g.v[i]; p != NULL; p = p->leg) {
			if (p->leg == NULL)
				break;
			//printf("%d", p->leg->data);
			if (p->data == v) {
				pnod t = p;
				p = p->leg;
				free(t); t = NULL;
				continue;
			}
			if (p->leg->data == v) {
				pnod t = p->leg;
				p->leg = p->leg->leg;
				free(t);
			}
		}
		//printf("\n");
	}
	// if (g.v[v] != NULL)
	// 	g.v[v]->data = -1;
}

int grad (Graf g, int v)
{
	int nr = 0;
	for (pnod p = g.v[v]; p != NULL; p = p->leg)
		nr++;
	return nr;
}

void grade (Graf g)
{
	for (int i = 1; i <= g.n; i++) {
		printf("%d ", grad(g, i));
	}
	printf("\n");
}

void show(Graf g)
{
	for (int i = 1; i <= g.n; i++) {
		printf("%d: ", i);
		pnod p;
		for (p = g.v[i]; p != NULL; p = p->leg) {
			if (p->data == 0 || p->data > 10)
				continue;
			printf("%d ", p->data);
		}
		printf("\n");
	}
}

void vcover (Graf & g)
{
	int max = -1, nr = 0;
	for (int j = 0; j < 5; j++) {
		for (int i = 1; i <= g.n; i++) {
			if (grad(g, i) > max) {
				max = grad(g, i);
				nr = i;
			}
		}
		printf("%d ", nr);
		delV(g, nr);
		max = -1;
	}
}

int main()
{
	Graf g;
	int n = 9, m = 12;
	int v[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 7, 8};
	int w[] = {2, 4, 3, 5, 6, 5, 7, 6, 8, 9, 8, 9};
	initG(g, n);
	build(g, m, v, w);
	printf("Vecini:\n");
	show(g);
	printf("Grade: \n");
	grade(g);
	delV(g, 5);
	printf("Vecini dupa stergerea nodului 5\n");
	show(g);
	printf("Grade dupa stergerea nodului 5\n2 2 2 2 0 2 2 2 2\n");
	return 0;
}