#include <stdio.h>
#include <stdlib.h>


typedef struct nod {
    int val;
    struct nod *next;
} nod;


nod* init (nod *cap)
{
    cap = NULL;
    return cap;
}


int lung (nod *cap)
{
    int nr = 0;
    while (cap != NULL) {
        nr++;
        cap = cap->next;
    }
    return nr;
}


nod* adaugaInceput (nod *cap, int x)
{
    nod *nou = (nod*) malloc (sizeof(nod));
    nou->val = x;
    nou->next = cap;
    cap = nou;
    return cap;
}


void afisList (nod *cap) 
{
    printf ("Elementele listei: ");
    while (cap != NULL) {
        printf ("%d ", cap->val);
        cap = cap->next;
    }
    printf ("\n");
}


nod* adaugaDupaElement (nod *cap, int valpoz, int valnou)
{
    nod *aux = cap;

    while (cap->val != valpoz && cap->next != NULL) 
        cap = cap->next;
    // !!!
    if (cap == NULL) {
        printf ("Error! Elementul %d nu se afla in lista!\n", valpoz);
        return aux;
    }
    // !!!
    nod *nou = (nod*) malloc (sizeof(nod));
    nou->val = valnou;
    nou->next = cap->next;
    cap->next = nou;
    return aux;
}


nod* adaugaSfarsit (nod *cap, int x)
{
    nod *aux = cap;
    if (cap == NULL) {
        nod *nou = (nod*) malloc (sizeof(nod));
        nou->val = x;
        cap = nou;
        return cap;
    }
    while (cap->next != NULL) 
        cap = cap->next;
    nod *nou = (nod*) malloc (sizeof(nod));
    nou->val = x;
    cap->next = nou;
    return aux;
}


nod* modify (nod *cap, int valvechi, int valnou)
{
    nod *aux = cap;
    while (cap->val != valvechi && cap->next != NULL)
        cap = cap->next;
    // !!!
    if (cap->next == NULL) {
        printf ("Error! Elementul %d nu se afla in lista!\n", valvechi);
        return aux;
    }
    // !!!
    cap->val = valnou;
    return aux;
}


nod* stergeInceput (nod *cap)
{
    nod *aux = cap->next;
    free(cap);
    return aux;
}

nod* stergeSfarsit (nod *cap)
{
    nod *aux = cap;
    while (cap->next->next != NULL) 
        cap = cap->next;
    free(cap->next);
    cap->next = NULL;
    return aux;
}

nod* stergeElement (nod *cap, int x)
{
    nod *aux = cap;
    if (cap->val == x) {
        free(cap);
        return cap->next;
    }
    while (cap->next->val != x && cap->next != NULL) {
        if (cap->next->next == NULL) {
            cap = cap->next;
            break;
        }
        cap = cap->next;
    }
    if (cap->next == NULL) {
        printf ("Erorr! Elementul %d nu se afla in lista!\n", x);
        return aux;
    }
    free(cap->next);
    cap->next = cap->next->next;
    return aux;
}


void dealocare(nod *cap)
{
    while (cap != NULL) {
        free(cap);
        cap = cap->next;
    }
}


int main ()
{
    nod *cap;
    
    
    int inf, poz;
    cap = init(cap); //initializare lista
    //introducerea elementelor in lista
    printf("Introduceti noduri in lista. Terminati cu cifra zero.\n");
    printf("Introduceti elementul = ");
    scanf("%d",&inf);
    while(inf != 0) //introducerea se va incheia cu elementul "0"
    {
        cap = adaugaSfarsit(cap,inf); //am ales adaugarea la sfarsit
        printf("Introduceti elementul = ");
        scanf("%d", &inf);
    }
    afisList(cap); //afisarea componentelor listei
    printf("\nLista are %d elemente", lung(cap));
    //adaugarea unui element prin folosirea optiunii de adaugare la inceput
    printf("\nIntroduceti un element pentru a-l adauga la inceput: ");
    scanf("%d", &inf);
    cap = adaugaInceput(cap, inf);
    afisList(cap); //afisarea componentelor listei
    printf("\nLista are %d elemente", lung(cap));
    //exemplificarea adaugarii dupa un element dat
    printf("\nIntroduceti valoarea dupa care doriti sa inserati: ");scanf("%d", &poz);
    printf("Introduceti un element pentru a-l adauga dupa valoarea %d:",poz);
    scanf("%d", &inf);
    cap = adaugaDupaElement(cap, poz, inf);
    afisList(cap); //afisarea componentelor listei
    printf("\nLista are %d elemente", lung(cap));
    //exemplificarea optiunii de modificare a unei valori din lista
    printf("\nIntroduceti valoarea pe care doriti sa o modificati: ");
    scanf("%d", &poz);
    printf("Introduceti noua valoare: ");
    scanf("%d", &inf);
    cap = modify(cap,poz,inf);
    afisList(cap); //afisarea componentelor listei
    printf("\nLista are %d elemente", lung(cap));
    //stergerea primului element din lista
    printf("\nVom sterge primul element din lista \n");
    cap=stergeInceput(cap);
    afisList(cap); //afisarea componentelor listei
    printf("\nLista are %d elemente", lung(cap));
    //stergerea elementului de la sfarsitul listei
    printf("\nVom sterge ultimul element din lista \n");
    cap = stergeSfarsit(cap);
    afisList(cap);
    printf("\nLista are %d elemente", lung(cap));
    //stergerea unei anumite valori din lista
    printf("\nIntroduceti valoarea pe care doriti sa o stergeti: ");
    scanf("%d", &inf);
    cap = stergeElement(cap, inf);
    afisList(cap);
    printf("\nLista are %d elemente", lung(cap));
    //dealocarea listei
    printf("\nVom dealoca lista\n");
    dealocare(cap);
    
    return 0;
}
