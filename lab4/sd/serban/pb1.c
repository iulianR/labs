#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int val;
	struct nod* next;
} Nod;

void adauga(Nod* &l, int x)
{
	Nod* aux, *nou = (Nod*) malloc (sizeof(Nod));

	nou->val = x;
	if (l == NULL || x <= l->val) {
		nou->next = l;
		l = nou;
	} else {
		aux = l;
		while (aux->next != NULL && aux->next->val < x)
			aux = aux->next;
		nou->next = aux->next;
		aux->next = nou;
	}
}

void afisList (nod *l) 
{
    printf ("Elementele listei: ");
    while (l != NULL) {
        printf ("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}

int main()
{
	Nod* lst = NULL;
	adauga(lst, 10);
	adauga(lst, 15);
	adauga(lst, 20);
	adauga(lst, 30);
	adauga(lst, 25);
	adauga(lst, 35);
	adauga(lst, 45);
	adauga(lst, 13);
	afisList(lst);
	return 0;
}