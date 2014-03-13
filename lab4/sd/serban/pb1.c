#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	int val;
	struct nod* next;
} Nod;

void adauga (Nod* &l, int x)
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

void afisare(Nod* &l)
{
	Nod* aux = l;
	printf ("Elementele listei: ");
    while (aux != NULL) {
        printf ("%d ", aux->val);
        aux = aux->next;
    }
    printf("\n");
}

int main()
{
	Nod *lst = NULL;
	int i, x;
	for (i = 5; i <= 10*5; i+=5)
		adauga(lst, i);
	afisare(lst);

	printf("Introduceti elementul ce trebuie adaugat: ");
	scanf("%d", &x);
	adauga(lst, x);
	afisare(lst);

	return 0;
}
