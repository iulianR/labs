#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10

typedef struct nod {
	int val;
	struct nod* next;
	struct nod* prev;
} Nod;

void adauga (Nod* &l, int x)
{
	Nod* aux, *nou = (Nod*) malloc (sizeof(Nod));

	nou->val = x;
	if (l == NULL) {
		nou->next = l;
		nou->prev = NULL;
		l = nou;
	} else {
		aux = l;
		while (aux->next != NULL)
			aux = aux->next;
		nou->next = aux->next;
		nou->prev = aux;
		aux->next = nou;
	}
}

void afisare(Nod* l)
{
    while (l != NULL) {
        printf ("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

void reverse(Nod *& l)
{	
	Nod *end = l;
	while (end->next != NULL)
		end = end->next;

	Nod *aux = l;
	while (aux != NULL) {
		Nod* temp = aux->next;
		aux->next = aux->prev;
		aux->prev = temp;

		if (temp == NULL) {
			end = l;
			l = aux;
		}
	aux = temp;
	}
}

// void reversee (Nod* &l)
// {
// 	Nod* temp = NULL;
// 	Nod* aux = l;

// 	while (aux != NULL)
// 	{
// 		temp = aux->next;
// 		aux->next = aux->prev;
// 		aux = aux->next;
// 	}

// 	if (temp != NULL)
// 		l = temp->next;
// }

int main()
{
	Nod *lst = NULL;
	int i;

	srand(time(NULL));

	for (i = 0; i < n; i++)
		adauga(lst, rand() % 100);

	printf ("Elementele listei: ");
	afisare(lst);

	reverse(lst);
	printf ("Elementele listei inversate: ");
	afisare(lst);

	return 0;
}
