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

void initPQ (PQ & a)
{
	a.n = 0;
}

int emptyPQ (PQ & a)
{
	if (a.n >= 2)
		return 1;
	return 0;
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

Nod *build (char c[], short f[], int n)
{
	char ch = '0';
	PQ q;
	initPQ(q);
	for (int i = 0; i < 6; i++)
		addPQ(q, make (c[i],f[i],0,0));
	while (q.n >= 2) {
		Nod *left = delPQ(q);
		Nod *right = delPQ(q);
		int z = left->fr + right->fr;
		addPQ(q, make(++ch, z, left, right));
	}
	return delPQ(q);
}

void write (Nod *r, int ns)
{
	if (r != 0)
	{
		printf("%*c %c(%2d)\n", ns, ' ', r->ch, r->fr);
		write(r->left, ns + 3);
		write(r->right, ns + 3);
	}
}

int base_two(int cod)
{
	int r, i = 1, b = 0;
	while (cod != 0)
	{
		r = cod%2;
		cod/=2;
		b += r * i;
		i *= 10;
	}
	return b;
}

void afcod (Nod* r, int cod, int len) {
	char s[10];
	// la primul apel cod=len=0
	// pentru a memora codul Huffman
	if (r==NULL) return;
	if ( r->left==NULL && r->right==NULL) {
		// dacă nod frunză
		int temp = base_two(cod);
		printf ("%c : %0*d \n", r->ch, len, temp);
	}
	else {
		afcod ( r->left, 2*cod+0,len+1);
		afcod ( r->right, 2*cod+1,len+1);
	}
}
int main () {
	Nod* t;
	int i, n = 6;
	char ch[] = {'a','b','c','d','e','f'};
	short fr[] = {36,14,12,10,20,8};
	// creare arbore
	t = build (ch, fr, n);
	printf("\n");
	write (t, 0); // afișare arbore
	afcod (t, 0, 0);
}