#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N1 5
#define N2 5

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

// void merge(Nod* &cap1, Nod* cap2, int x)
// {
// 	int i;
// 	Nod* aux1 = cap1, *aux2 = cap2;

// 	for (i = 1; i < x; i++) {
// 		aux1 = aux1->next;
// 	}
// 	Nod* temp = aux1->next;
// 	aux1->next = cap2;
// 	while (aux2->next != NULL)
// 		aux2 = aux2->next;

// 	aux2->next = temp;
// 	//aux2 = cap2;
// }

void merge(Nod* &cap1, Nod* cap2)
{
	Nod *aux1 = cap1, *aux2 = cap2;

	while (aux1->next != NULL) {
		aux1 = aux1->next;
	}
	aux1->next = aux2;
	aux2->prev = aux1;
	while (aux2->next != NULL) {
		aux2 = aux2->next;
	}

}

void elim_duplicate1(Nod *& cap)
{
	Nod *aux, *temp, *dup;
	aux = cap;

	while (aux != NULL && aux->next != NULL) {
		temp = aux;
		while (temp->next != NULL) {
			if (aux->val == temp->next->val) {
				dup = temp->next;
				temp->next = temp->next->next;
				free(dup);
			} else {
				temp = temp->next;
			}
		}
		aux = aux->next;
	}
}

int main()
{
	Nod *lst1 = NULL, *lst2 = NULL;
	int i, x;
	srand(time(NULL));
	for (i = 0; i <= N1; i++)
		adauga(lst1, rand() % 20);
	for (i = 0; i <= N2; i++)
		adauga(lst2, rand() % 20);
	afisare(lst1);
	afisare(lst2);

	merge(lst1, lst2);
	//printf("Introduceti elementul ce trebuie sters din lista: ");
	//scanf("%d", &x);
	//sterge(lst, x);
	printf("Lista formata prin concatenare\n");
	afisare(lst1);

	printf("Lista dupa eliminarea elementelor duplicate\n");
	elim_duplicate1(lst1);
	afisare(lst1);

	return 0;
}