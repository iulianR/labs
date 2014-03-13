#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 5
typedef struct nod {
	int val;
	struct nod* next;
} Nod;

void adauga(Nod* &l, int x)
{
	Nod* aux, *nou = (Nod*) malloc (sizeof(Nod));

	nou->val = x;
	if (l == NULL) {
		nou->next = l;
		l = nou;
	} else {
		aux = l;
		while (aux->next != NULL)
			aux = aux->next;
		nou->next = aux->next;
		aux->next = nou;
	}
}

void afisList (Nod *l) 
{
    while (l != NULL) {
        printf ("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

void merge(Nod* &cap1, Nod* cap2, int x)
{
	int i;
	Nod* aux1 = cap1, *aux2 = cap2;

	for (i = 1; i < x; i++) {
		aux1 = aux1->next;
	}
	Nod* temp = aux1->next;
	aux1->next = cap2;
	while (aux2->next != NULL)
		aux2 = aux2->next;

	aux2->next = temp;
	//aux2 = cap2;
}

int main()
{
	Nod *CapLista1 = NULL, *CapLista2 = NULL;
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		adauga(CapLista1, rand() % 100);
		adauga(CapLista2, rand() % 100);
	}

	printf ("Elementele listei 1: \n");
	afisList(CapLista1);
	printf ("Elementele listei 2: \n");
	afisList(CapLista2);
	printf("\n");
	int x = 2;
	merge(CapLista1, CapLista2, 2);

	printf ("Elementele listei 1 dupa inserarea la pozitia %d: \n", x);
	afisList(CapLista1);
	printf ("Elementele listei 2: \n");

	i = 0;
	while (i < n) {
        printf ("%d ", CapLista2->val);
        CapLista2 = CapLista2->next;
        i++;
    }
    printf("\n");
 //   afisList(CapLista2);
	return 0;
}