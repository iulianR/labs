#include <stdio.h>
#include <stdlib.h>

int i = 0;
int vector_parcurgere[200];

typedef struct nod {
	int valoare;
	nod *fiu_stanga;
	nod *fiu_dreapta;
} nod;

void inserare_nod(nod *& cap, int x)
{
	if (cap == NULL) {
		cap = (nod*) malloc (sizeof(nod));
		cap->fiu_stanga = NULL;
		cap->valoare = x;
		cap->fiu_dreapta = NULL;
	} else {
		if (x < cap->valoare)
			inserare_nod(cap->fiu_stanga, x);
		else
			inserare_nod(cap->fiu_dreapta, x);
	}
}

void preordine(nod * cap)
{
	if (cap == NULL)
		return;
	else {
	printf("%d ", cap->valoare);
	preordine(cap->fiu_stanga);
	preordine(cap->fiu_dreapta);
	}
}

void inordine(nod * cap)
{
	if (cap == NULL)
		return;
	inordine(cap->fiu_stanga);
	printf("%d ", cap->valoare);
	inordine(cap->fiu_dreapta);
}

void postordine(nod * cap)
{
	if (cap == NULL)
		return;
	postordine(cap->fiu_stanga);
	postordine(cap->fiu_dreapta);
	printf("%d ", cap->valoare);
}

// nod * find(nod * cap, int x)
// {
// 	if (cap == NULL || cap->valoare == x)
// 		return cap;
// 	else if (x < cap->valoare)
// 		return find(cap->fiu_stanga, x);
// 	else if (x > cap->valoare)
// 		return find(cap->fiu_dreapta, x);
// }

void find (nod *&cap, int num, nod *&parent, nod *&x, int *found)
{
    nod *q ;

    q = cap;
    *found = 0 ;
    parent = NULL ;

    while ( q != NULL )
    {
        /* if the node to be deleted is found */
	if ( q -> valoare == num )
        {
            *found = 1 ;
            x = q ;
            return ;
        }

        parent = q ;

        if ( q -> valoare > num )
            q = q -> fiu_stanga ;
        else
            q = q -> fiu_dreapta ;
    }
}

void sterge_subarbore(nod *& cap, int x)
{
	if (cap == NULL)
		return;
	if (cap->valoare == x) {
		cap->fiu_stanga = NULL;
		cap->fiu_dreapta = NULL;
		return;
	}
	else if (x < cap->valoare)
		return sterge_subarbore(cap->fiu_stanga, x);
	else if (x > cap->valoare)
		return sterge_subarbore(cap->fiu_dreapta, x);
}

void sterge_nod(nod *& cap, int num)
{
	int found;
	nod *parent, *x, *x_succesor;

	if (cap == NULL) {
		printf("\n Empty");
		return;
	}
	parent = x = NULL;

	// Cauta nodul
	find (cap, num, parent, x, &found);

	//Daca nu este gasit
	if (found == 0) {
		printf("\n Nodul nu a fost gasit");
		return;
	}

	//Daca are doi succesori
	if (x->fiu_stanga != NULL && x->fiu_dreapta != NULL) {
		parent = x;
		x_succesor = x->fiu_dreapta;

		while (x_succesor->fiu_stanga != NULL) {
			parent = x_succesor;
			x_succesor = x_succesor->fiu_stanga;
		}

		x->valoare = x_succesor->valoare;
		x = x_succesor;
	}

	//Daca nu are succesori
	if (x->fiu_stanga == NULL && x->fiu_dreapta == NULL) {
		if (parent ->fiu_dreapta == x)
			parent->fiu_dreapta == NULL;
		else
			parent->fiu_stanga == NULL;
		free(x);
		return;
	}

	//Daca are doar fiu dreapta
	if (x->fiu_stanga == NULL && x->fiu_dreapta != NULL) {
		if (parent->fiu_stanga == x)
			parent->fiu_stanga = x->fiu_dreapta;
		else
			parent->fiu_dreapta = x->fiu_dreapta;
		free(x);
		return;
	}

	//Daca are doar fiu stanga
	if (x->fiu_stanga != NULL && x->fiu_dreapta == NULL) {
		if (parent->fiu_stanga == x)
			parent->fiu_stanga = x->fiu_stanga;
		else
			parent->fiu_dreapta = x->fiu_stanga;
		free(x);
		return;
	}
}


int main()
{
	nod * tree = NULL;
	int valori[21] = {50, 20, 70, 10, 25, 5, 15,
					1, 7, 12, 18, 22, 30, 27,
					40, 60, 55, 65, 80, 75, 100};
	int i;
	for(i = 0; i < 21; i++)
		inserare_nod(tree, valori[i]);
int valoare;
char raspuns;
int terminat = 0;
	while (!terminat)
	{
		// afisarea meniului aplicatiei
		printf("\n i - inserare nod in arbore");
		printf("\n s - stergere nod din arbore");
		printf("\n b - stergere subarbore");
		printf("\n p - parcurgere arbore in preordine");
		printf("\n o - parcurgere arbore in inordine");
		printf("\n a - parcurgere arbore in postordine");
		printf("\n t - terminare program");
		printf("\n Alegeti operatia dorita : ");
		raspuns = getchar();
		switch (raspuns)
		{
			case 'i':
				printf("\n inserare nod in arbore");
				// citirea valorii nodului de inserat
				printf("\n introduceti valoarea nodului : ");
				scanf("%d",&valoare);
				// apelarea functiei de inserare nod
				inserare_nod(tree, valoare);
				break;
			case 's':
				printf("\n stergere nod din arbore");
				// citirea valorii nodului de sters
				printf("\n introduceti valoarea nodului de sters : ");
				scanf("%d",&valoare);
				// apelarea functiei de stergere nod
				sterge_nod(tree, valoare);
				break;
			case 'b':
				printf("\n stergere subarbore");
				// citirea valorii nodului pentru care se vor sterge toate nodurile subarborelui
				printf("\n introduceti valoarea nodului care reprezinta radacina subarborelui de sters : ");
				scanf("%d",&valoare);
				// apelarea functiei de stergere subarbore
				sterge_subarbore(tree, valoare);
				break;
			case 'p':
				printf("\n parcurgere arbore in preordine");
				printf("\n vectorul de parcurgere a arborelui in preordine : ");
				// apelarea functiei de parcurgere arbore inpreordine
				preordine(tree);
				//afisarea vectorului de parcurgere a arborelui in preordine
				break;
			case 'o':
				printf("\n parcurgere arbore in inordine");
				printf("\n vectorul de parcurgere a arborelui in inordine : ");
				//apelarea functiei de parcurgere a arborelui in inordine
				inordine(tree);
				//afisarea vectorului de parcurgere a arborelui in inordine
				break;
			case 'a':
				printf("\n parcurgere arbore in postordine");
				printf("\n vectorul de parcurgere a arborelui in postordine : ");
				//apelarea functiei de parcurgere a arborelui in postordine
				postordine(tree);
				// afisarea vectorului de parcurgere a arborelui in postordine
				break;
			case 't':
				terminat = 1;
				break;
			default:
				printf("\n operatie aleasa gresit");
		}
		getchar();
	}
	return 0;
}
