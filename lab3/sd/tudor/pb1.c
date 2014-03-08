#include <stdio.h>
#include <stdlib.h>

typedef struct nod {
	char c;
	struct nod * leg;
} nod;

//typedef nod * List;


void print(nod * l);
void add(nod * & l, char a);
nod* search(nod * l, char a);
void delete_el(nod * & l, char a);
void reverse(nod * & l);


int main()
{
	nod * lst;
	lst = (nod*) malloc (sizeof(nod));
	char c;
	add(lst, 'a');
	add(lst, 'b');
	add(lst, 'c');
	add(lst, 'd');
	print(lst);
	printf("Introduceti caracterul pe care doriti sa il cautati in lista: ");
	scanf("%c", &c);
	if (search(lst, c) != NULL)
		printf("Caracter gasit\n");
	else
		printf("Caracterul %c nu se gaseste in lista\n", c);
	//printf("Char to delete: ");
	//scanf("%c", &c);
	delete_el(lst, 'a');
	puts("Lista:");
	print(lst);
	reverse(lst);
	print(lst);
	return 0;
}
	
void print(nod * l)
{
	while (l != NULL) {
		printf("%c ", l->c);
		l = l->leg;
	}
	printf("\n");
}

void add(nod * & l, char a)
{
	nod *nou = (nod*) malloc (sizeof(nod));

	nou->c = a;
	nou->leg = NULL;
	if (l->leg == NULL) {
		l->leg = nou;
	}
	else {
		nod *aux = l;
		while (aux->leg != NULL) {
			aux = aux->leg;
		}
		aux->leg = nou;
		aux = aux->leg;
	}
}	

nod* search(nod * l, char a)
{
	while (l != NULL) {
		if (l->c == a)
			return l;
		else {
		l = l->leg;
		}
	}
	return NULL;
}

void delete_el(nod *& l, char a)
{
	nod *aux = l;
	if (aux->c == a) {
		free(aux);
		aux = aux->leg;
	}
	else {
		while (aux->leg != NULL) {
			if (aux->leg->c == a) {
				free(aux->leg);
				aux->leg = aux->leg->leg;
			}
			else {
				aux = aux->leg;
			}
		}
	}
}

void reverse (nod *& l)
{
	nod * aux;
	nod * nou = NULL;
	while (l != NULL) {
		aux = l->leg;
		l->leg = nou;
		nou = l;
		l = aux;
	}
	l = nou;
}