#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nod {
	int val;
	struct nod *next;
} nod;

nod* creeare (nod *cap)
{
	cap = NULL;
	return cap;
}

void adauga (nod* & cap, int x)
{
	nod *aux, *nou;
	nou = (nod*) malloc (sizeof(nod));
	nou->val = x;
	if (cap == NULL || x <= cap->val) {
		nou->next = cap;
		cap = nou;
		return;
	}
	aux = cap;
	while (aux->next != NULL && aux->next->val < x)
		aux = aux->next;
	nou->next = aux->next;
	aux->next = nou;
}

void afisare(nod *cap)
{
	while (cap != NULL) {
		printf ("%d ", cap->val);
		cap = cap->next;
	}
	printf ("\n");
}

int count_appearances(nod *cap, int x)
{
	int nr = 0;
	while (cap != NULL) {
		if (cap->val == x)
			nr++;
		cap = cap->next;
	}
	return nr;
}

int main ()
{
	nod *lst;
	lst = creeare(lst);

	adauga(lst, 10);
	adauga(lst, 20);
	adauga(lst, 30);
	adauga(lst, 0);
	adauga(lst, 1);
	adauga(lst, 11);
	adauga(lst, 10);
	adauga(lst, 10);
	afisare(lst);

	printf ("Nr %d apare de %d ori in lista\n", 10, count_appearances(lst, 10));
      printf ("Nr %d apare de %d ori in lista\n", 30, count_appearances(lst, 30));
      printf ("Nr %d apare de %d ori in lista\n", 0, count_appearances(lst, 0));
      printf ("Nr %d apare de %d ori in lista\n", 1001, count_appearances(lst, 1001));

	getch();
	return 0;
}
