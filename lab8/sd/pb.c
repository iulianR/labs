#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a, b) a > b ? a : b
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} node;

typedef struct stack {
	struct node *data;
	struct stack *next;
} stack;

typedef struct queue {
	struct node *data;
	struct queue *next;
} queue;

void enqueue(queue *& q, node *elem)
{
	queue * new_element = (queue*) malloc (sizeof(queue));

	new_element->data = elem;
	if (q == NULL) {
		new_element->next = q;
		q = new_element;
	}
	else {
		queue * temp = q;
		while (temp->next != NULL)
			temp = temp->next;
		new_element->next = temp->next;
		temp->next = new_element;
	}
}

node * dequeue(queue *& q)
{
	queue *temp = (queue*) malloc (sizeof(queue));
	if (q == NULL)
		return NULL;

	node *data = q->data;
	temp = q;
	q = q->next;
	free(temp);
	return data;
}

void push(stack *& s, node* elem)
{
	stack * new_element = (stack*) malloc (sizeof(stack));

	new_element->data = elem;
	new_element->next = s;
	s = new_element;
}

node * pop(stack *&s)
{
	stack * to_pop = s;
	node *popped = s->data;
	s = s->next;
	free(to_pop);
	return popped;
}

void insert(node *& root, int x)
{
	if (root == NULL) {
		root = (node*) malloc (sizeof(node));
		root->left = NULL;
		root->data = x;
		root->right = NULL;
	} else {
		if (x < root->data)
			insert(root->left, x);
		else
			insert(root->right, x);
	}
}

void preorder(node *root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void BFS(node *root, queue *&queue)
{
	printf("%d ", root->data);

	if (root->left)
		enqueue(queue, root->left);
	if (root->right)
		enqueue(queue, root->right);

	if (queue == NULL)
		return;
	else
		BFS(dequeue(queue), queue);
}

void DFS(node *root, stack *&stack)
{
	printf("%d ", root->data);

	if (root->right)
		push(stack, root->right);
	if (root->left)
		push(stack, root->left);

	if (stack == NULL)
		return;
	else
		DFS(pop(stack), stack);
}

int count(node *root)
{
	if (root == NULL)
		return 0;
	return count(root->left) + count(root->right) + 1;
}

int count_leaves(node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return count_leaves(root->left) + count_leaves(root->right) + 1;
	else
		return count_leaves(root->left) + count_leaves(root->right);
}

int count_not_leaves(node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return count_not_leaves(root->left) + count_not_leaves(root->right);
	else
		return count_not_leaves(root->left) + count_not_leaves(root->right) + 1;
}

int height(node *root)
{
	if (root == NULL)
		return 1;
	else
		return MAX(height(root->left), height(root->right)) + 1;
}

int sum(node *root)
{
	if (root == NULL)
		return 0;
	return sum(root->left) + sum(root->right) + root->data;
}

int main()
{
	node *tree = NULL;
	stack *stack = NULL;
	queue *queue = NULL;

	insert(tree, 50);
	insert(tree, 75);
	insert(tree, 25);
	insert(tree, 90);
	insert(tree, 35);
	insert(tree, 5);
	insert(tree, 100);
	insert(tree, 80);
	insert(tree, 40);
	insert(tree, 30);
	insert(tree, 7);
	insert(tree, 1);
	insert(tree, 88);
	insert(tree, 77);
	insert(tree, 33);
	insert(tree, 27);
	insert(tree, 10);
	insert(tree, 6);

	printf("Preordine: \n\t");
	preorder(tree);
	printf("\n");

	printf("BFS: \n\t");
	BFS(tree, queue);
	printf("\n");

	printf("DFS: \n\t");
	DFS(tree, stack);
	printf("\n");

	printf("Numar noduri: \n\t");
	printf("%d\n", count(tree));

	printf("Numar frunze: \n\t");
	printf("%d\n", count_leaves(tree));

	printf("Numar noduri care nu sunt frunze: \n\t");
	printf("%d\n", count_not_leaves(tree));

	printf("Inaltime: \n\t");
	printf("%d\n", height(tree));

	printf("Suma valori noduri: \n\t");
	printf("%d\n", sum(tree));
	return 0;
}

