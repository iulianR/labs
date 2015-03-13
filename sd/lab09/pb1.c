#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 12

typedef struct {
	int v[M];
	int n;
} PQ;

void initPQ (PQ & a)
{
	a.n = 0;
}

void swap (PQ & a, int i, int j)
{
	int t;
	t = a.v[i];
	a.v[i] = a.v[j];
	a.v[j] = t;
}

void addPQ (PQ & a, int x)
{
	int k;
	k = a.n++;
	a.v[k] = x;
	int temp;
	if (k % 2 == 0)
		temp = k/2 - 1;
	else
		temp = k/2;
	while (k > 0 && a.v[temp] > x) {
		swap(a, k, temp);
		k = temp;
		if (temp % 2 == 0)
			temp = temp/2 - 1;
		else
			temp = temp/2;
	}
}

void printPQ(PQ & a)
{
	for (int i = 0; i < a.n; i++)
		printf("%d ", a.v[i]);
	printf("\n");
}

int emptyPQ(PQ & a)
{
	return !a.n;
}

int valmin(PQ & a, int k);
void heapify (PQ & a, int k);

// int valmin(PQ & a, int k)
// {
// 	int st, dr;
// 	if (k == 0) {
// 		st = 1; dr = 2;
// 	}
// 	else {
// 		st = 2 * k; dr = st + 1;
// 	}
// 	int m = k;
// 	if (st <= a.n && a.v[st] < a.v[m])
// 		m = st;
// 	else if (dr <= a.n && a.v[dr] < a.v[m])
// 		m = dr;
// 	return m;
// }

void heapify (PQ & a, int k)
{
	int st, dr, m, aux;
	if (k == 0) {
		st = 1; dr = 2;
	}
	else {
		st = 2 * k; dr = 2 *k + 1;
	}
	m = k;
	if (st <= a.n && a.v[st] < a.v[m])
		m = st;
	if (dr <= a.n && a.v[dr] < a.v[m]) {
		m = dr;
	}
	if (m != k) {
		swap(a, k, m);
		heapify(a, m);
	}
}

// void heapify (PQ & a, int k)
// {
// 	int m = valmin(a, k);
// 	if (m != a.v[k])
// 		swap (a, k, m);
// 		heapify(a, m);
// }

int delPQ(PQ & a)
{
	int x = a.v[0];
	a.v[0] = a.v[a.n-1];
	a.n--;
	heapify(a, 0);
	return x;
}

int main()
{
	PQ pq;
	int x[10] = {3,8,2,9,7,1,5,4,6,0};
	int i;
	initPQ (pq);
	for (i = 0; i < 10; i++) {
		addPQ (pq, x[i]);
		printPQ (pq);
	}
	//printPQ (pq);
	while ( ! emptyPQ (pq)) {
		//break;
		printPQ (pq);
		printf ("min = %d\n",delPQ (pq));
	}
	return 0;
}