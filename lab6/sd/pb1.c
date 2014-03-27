#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10

typedef struct nod {
	int data;
	struct nod * next;
} nod;

void dispQueue(nod* &q)
{
	nod* aux = q;
    while (aux != NULL) {
        printf ("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int isEmpty(nod *& q)
{
	if (q == NULL)
		return 1;
	return 0;
}

void enQueue(nod *& q, int x)
{
	nod* aux, *nou = (nod*) malloc (sizeof(nod));

	nou->data = x;
	if (q == NULL) {
		nou->next = q;
		q = nou;
	} else {
		aux = q;
		while (aux->next != NULL)
			aux = aux->next;
		nou->next = aux->next;
		aux->next = nou;
	}
}

int deQueue(nod *& q)
{
	nod * temp = (nod*) malloc (sizeof(nod));
	if (isEmpty(q))
		return 0;
	int data = q->data;
	temp = q;
	q = q->next;
	free(temp);
	return data;
}

int main()
{
	int nr = 0, j, x;
	nod * queue[10];
	int i, array[100];
	for (i = 0; i < 10; i++)
		queue[i] = NULL;
	srand(time(NULL));

	int max = -9999;
	for (i = 0; i < N; i++) {
		array[i] = rand()%1000;
		if (array[i] > max)
			max = array[i];
	}

	printf("Numerele inainte de sortare: \n");
	for (j = 0; j < 10; j++)
		printf("%d ", array[j]);
	printf("\n");

	while (max != 0) {
		nr++;
		max = max/10;
	}
	int m = 10, n = 1, k = 0;
	for (i = 0; i < nr; i++) {
		k =0;
		for (j = 0; j < N; j++) {
			x = array[j] % m;
			x = x / n;
			enQueue(queue[x], array[j]);
		}
		for (j = 0; j < 10; j++) {
			while (!isEmpty(queue[j])) {
				array[k] = deQueue(queue[j]);
				k++;
			}
		}
		m  = m*10;
		n = n * 10;
	}

	printf("Numerele dupa de sortare: \n");
	for (j = 0; j < 10; j++)
		printf("%d ", array[j]);
	printf("\n");

	return 0;
}