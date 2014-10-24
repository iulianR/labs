#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nod {
	char ch;
	short fr;
	struct nod *left, *right;
} Nod;

typedef struct {
	Nod *v[200];
	int n;
} PQ;

void swap (PQ & a, int i, int j)
{
	Nod* t = a.v[i];
	a.v[i] = a.v[j];
	a.v[j] = t;
}

void addPQ (PQ & a, Nod* x)
{
	int k;
	k = a.n++;
	a.v[k] = x;
	int temp;
	if (k % 2 == 0)
		temp = k/2 - 1;
	else
		temp = k/2;
	while (k > 0 && a.v[temp]->fr > x->fr) {
		swap(a, k, temp);
		k = temp;
		if (temp % 2 == 0)
			temp = temp/2 - 1;
		else
			temp = temp/2;
	}
}

Nod *make (char ch, short fr, Nod* left, Nod* right)
{
	Nod *temp = (Nod*) malloc (sizeof(Nod));
	temp->ch = ch;
	temp->fr = fr;
	temp->left = left;
	temp->right = right;
	return temp;
}

void initPQ (PQ & a)
{
	a.n = 0;
}

int emptyPQ (PQ & a)
{
	return !a.n;
}


void heapify (PQ & a, int k)
{
	int m, left, right;
	if (k == 0) {
		left = 1; right = 2;
	}
	else {
		left = 2 * k; right = 2 *k + 1;
	}
	m = k;
	if (left <= a.n && a.v[left]->fr < a.v[m]->fr)
		m = left;
	if (right <= a.n && a.v[right]->fr < a.v[m]->fr) {
		m = right;
	}
	if (m != k) {
		swap(a, k, m);
		heapify(a, m);
	}
}

Nod* delPQ(PQ & a)
{
	Nod* x = a.v[0];
	a.v[0] = a.v[a.n-1];
	a.n--;
	heapify(a, 0);
	return x;
}

void printPQ(PQ & a)
{
	for (int i = 0; i < a.n; i++)
		printf("%c %d\n", a.v[i]->ch, a.v[i]->fr);
	printf("\n");
}

int main()
{
	char ch[] = {'a','b','c','d','e','f'};
	short fr[] = {36,14,12,10,20,8};
	PQ q;
	initPQ(q);
	for (int i = 0; i < 6; i++)
		addPQ(q, make (ch[i],fr[i],0,0));
		// adauga la coadă adresa nod
	printPQ(q);
	while ( ! emptyPQ(q)){
		Nod* p = delPQ(q);
		printf("%c = %d\n", p->ch, p->fr);
	}
	return 0;
}