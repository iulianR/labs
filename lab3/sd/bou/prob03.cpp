#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nod {
	int val;
	struct nod * next;
} Nod;

void adaugare(nod *& lst, int x)
{
	if (lst == NULL) {
		lst = (Nod*) malloc (sizeof(Nod));
		lst->val = x;
		lst->next = lst;
	} else {
		Nod * nou = (Nod*) malloc (sizeof(Nod));
		Nod * aux = lst;
		while (aux->next != lst)
			aux = aux->next;
		nou->val = x;
		nou->next = lst;
		aux->next = nou;
	}
}

void afisare(nod * lst) {
	Nod * aux = lst;
	
	if (lst == NULL) {
		printf("Lista vida\n");
		return;
	}
	while(aux->next != lst) {
            printf("%d ", aux->val);
		aux = aux->next;
	}
      printf("%d\n", aux->val);
}

void skip(nod *& lst, int n) {
	Nod * aux = lst;
	
	int i;
	while (aux != NULL) {
		if (aux->next == aux) {
			// daca mai e doar 1 elem in lista il vom elimina automat
			free(aux);
			lst = NULL;
			return;
		}
		for (i = 0; i < n - 1; i++)
			aux = aux->next;
		Nod * del = aux->next;
		aux->next = aux->next->next;
		if (del == lst)
			// daca elementul eliminat a fost primul mutam capul listei cu o unitate mai departe pentru a putea face afisarea
			lst = lst->next;
		free(del);
		afisare(lst);
	}
}

int main()
{
	Nod* lst = NULL;

	adaugare(lst, 10);
	adaugare(lst, 20);
	adaugare(lst, 30);
	adaugare(lst, 40);
	adaugare(lst, 50);
	adaugare(lst, 60);
	adaugare(lst, 70);
	adaugare(lst, 80);
	adaugare(lst, 90);
	adaugare(lst, 100);
	afisare(lst);

	skip(lst, 9);
	afisare(lst);
	getch();

	return 0;
}
