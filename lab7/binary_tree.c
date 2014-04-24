#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod {
	char data;
	nod *left;
	nod *right;
} tree;

void insert(tree *&root, char x)
{
	if (root == NULL)
		root = new_node(x);
	if (root->data == x)
		return;
	else {
		if (root->data > x) {
			if (root->left == NULL)
				root->left = new_node(x);
			else
				insert(root->left, x);
		}
		else {
			if (root->right == NULL)
				root->right = new_node(x);
			else
				insert(root->right, x);
		}
	}
}


int main()
{
	tree *root = NULL;
	insert(root, 'a');
	return 0;
}