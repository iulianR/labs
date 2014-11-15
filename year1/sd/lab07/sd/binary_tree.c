#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	node *left;
	node *right;
} node;

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

void inorder(node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(node *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

node * min(node *root)
{
	if (root == NULL) {
		printf("empty\n");
		return NULL;
	}
	if (root->left == NULL)
		return root;
	else
		return min(root->left);
}

node * max(node *root)
{
	if (root == NULL) {
		printf("empty\n");
		return NULL;
	}
	if (root->right == NULL)
		return root;
	else
		return max(root->right);
}

node * delete_node(node *&root, int x)
{
	//node not found
	if (root == NULL)
		return root;
	if (root->data > x)
		root->left = delete_node(root->left, x);
	else {
		if (root->data < x)
			root->right = delete_node(root->right, x);
		else { // node found
			node *temp = NULL;
			// 2 sons
			if (root->left && root->right) {
				node *temp = min(root->right);
				root->data = temp->data;
				root->right = delete_node(root->right, temp->data);
			}
			else { // 1 son
				node *temp = root;
				if (root->left != NULL)
					root = root->left;
				else
					root = root->right;
			}
			free(temp);
		}
	}
	return root;
}

int main() {
	node *tree = NULL;
	insert(tree, 10);
	insert(tree, 30);
	insert(tree, 20);
	insert(tree, 11);
	insert(tree, 32);
	insert(tree, 25);
	insert(tree, 15);
	insert(tree, 3);
	insert(tree, 50);

	delete_node(tree, 30);
	delete_node(tree, 3);

	preorder(tree);
	printf("\n");
	inorder(tree);
	printf("\n");
	postorder(tree);
	printf("\n");
	return 0;
}