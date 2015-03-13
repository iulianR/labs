#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct nod {
	float val;
	struct nod * next;
} nod;

void push(nod * &stack, float x) {
	nod * nou = (nod*) malloc (sizeof(nod));
	nou->val = x;
	nou->next = stack;
	stack = nou;
}

float pop(nod *& stack) {
	nod * temp = (nod*) malloc (sizeof(nod));
	if (stack == NULL)
		return 0;
	float val = stack->val;
	temp = stack;
	stack = stack->next;
	free(temp);
	return val;
}

void disp(nod* &stack)
{
	nod* aux = stack;
    while (aux != NULL) {
        printf ("%.2f ", aux->val);
        aux = aux->next;
    }
    printf("\n");
}

float compute(float op1, float op2, char sign)
{
	switch(sign) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '/':
			return op1/op2;
		case '*':
			return op1 * op2;
	}
}

int main()
{
	nod * stack = NULL;
	char string[] = "X";
	char s[20];
	scanf("%s", s);
	int n = strlen(s);
	int i;
	float op1, op2;
	float result;
	for (i = n - 1; i >= 0; i--) {
		if (isdigit(s[i])) {
			string[0] = s[i];
			push(stack, (float)atoi(string));
		}
		else {
			op1 = pop(stack);
			op2 = pop(stack);
			result = compute(op1, op2, s[i]);
			push(stack, result);
		}
	}
	printf("Rezultatul este: \n");
	disp(stack);
}