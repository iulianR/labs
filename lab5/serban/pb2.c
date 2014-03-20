#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 10

typedef struct nod {
	int val;
	struct nod * prev;
	struct nod * next;
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

void sterge(Nod *& l, int x)
{
	Nod* aux = l;
	if (aux->val == x) {
		l = l->next;
		free(aux);
		return;
	}

	while (aux->next->val != x && aux->next != NULL) {
		if (aux->next->next == NULL) {
			aux = aux->next;
			break;
		}
		aux = aux->next;
	}
	if (aux->next == NULL) {
		printf("Elementul %d nu se afla in lista!\n", x);
	}
	else {
		free(aux->next);
		aux->next = aux->next->next;
	}
}

int main()
{
	Nod *lst = NULL;
	int i, x;
	srand(time(NULL));
	for (i = 0; i <= N; i++)
		adauga(lst, rand() % 100);
	afisare(lst);

	printf("Introduceti elementul ce trebuie sters din lista: ");
	scanf("%d", &x);
	sterge(lst, x);
	afisare(lst);

	return 0;
}