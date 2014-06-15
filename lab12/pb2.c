#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define H 13

typedef struct nod {
	char *cuv;
	int nr;
	struct nod *leg;
} nod;

typedef nod * Map [H];

int hash (char *s)
{
	int i, sum = 0;
	for (i = 0; i < strlen(s); i++)
		sum = sum + (i + 1) * s[i];
	return sum % H;
}

void initD (Map d)
{
	for (int i = 0; i < H; i++) {
		d[i] = NULL;
	}
}

nod* cautD (Map d, char *c)
{
	int key = hash(c);
	//if (d[key]->nr == 0)
		//return d[key];
	if (d[key] == NULL)
		return NULL;
	nod *temp = d[key];
	while (temp != NULL)
	{
		if (!strcmp(temp->cuv, c))
			return temp;
		temp = temp->leg;
	}
	return NULL;
}

void putD (Map d, char *c, int nr)
{
	nod *temp = cautD(d, c);
	if (temp != NULL)
		(temp->nr)++;
	else {
		nod *new_node = (nod *) malloc (sizeof(nod));
		new_node->cuv = strdup(c);
		new_node->nr = nr;
		int key = hash(c);
		new_node->leg = d[key];
		d[key] = new_node;
	}
}

void printD (Map d)
{
	for (int i = 0; i < H; i++) {
		while (d[i]->leg != NULL) {
			printf("%s %d\n", d[i]->cuv, d[i]->nr);
			d[i] = d[i]->leg;
		}
	}
}

int getD (Map d, char *c)
{
	//int key = hash(c);
	nod *temp = cautD(d, c);
	if (temp == NULL)
		return 0;
	else
		return temp->nr;
}

int main () {
	char numef[20], buf[128], * q;
	Map dc;
	int nra;
	FILE *f;
	printf ("Introduceti numele fisierului : ");
	scanf ("%s", numef);
	f = fopen (numef, "r");
	initD (dc);
	while ( fscanf ( f, "%s", buf) > 0) {
		q = strdup (buf);
		// creare adresă pentru şirul citit
		nra = getD (dc, q);
		// calculează număr de apariţii cuvânt
		if (nra == 0)
		// dacă e prima apariţie
			putD (dc, q, 1);
			// pune cuvântul în tabela de dispersie
		else
		// dacă nu e prima apariţie
			putD (dc, q, nra + 1);
			// modifică numărul de apariţii ale cuvântului
		}
	printD (dc);
	return 0;
}
