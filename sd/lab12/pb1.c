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

int hash(char *s){
    int i, sum = 0;
    for ( i = 0; i < strlen(s); i++)
        sum = sum + (i + 1)*s[i];
    return sum % H;
}
 
void initD(Map d){
    int i;
    for (i = 0; i < H; i++)
        d[i] = NULL;
}
 
void printD(Map d){
    nod *p;
    int i;
    for(i = 0; i < H; i++){
        p = d[i];
        printf("Pentru cheia %d\n", i);
        while(p != NULL){
            printf("\t %s: %d\n",p->cuv,p->nr);
            p = p->leg;
            }
        }
}
 
nod *cautD(Map d, char *c){
    int k = hash(c);
    nod *p;
    p = d[k];
    if (p == NULL)
        return NULL;
    while ( p != NULL){
        if(strcmp(p->cuv,c) == 0)
            return p;
        p = p->leg;
        }
    return NULL;
}
 
void putD(Map d, char *c, int nr){
    nod *p, *q;
    int i;
    p = cautD(d,c);
    if (p != NULL)
        (p->nr) ++;
    else{
        q = (nod *)malloc(sizeof(nod));
        q->cuv = strdup(c);
        q->nr = nr;
        i = hash(c);
        q->leg = d[i];
        d[i] = q;
        }
}
 
int getD(Map d, char *c){
    nod *p = cautD(d,c);
    if (p == NULL)
        return 0;
    else
        return p->nr;
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
