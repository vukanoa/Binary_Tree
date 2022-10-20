#include <stdlib.h>
#include <math.h>
#include "tree.h"
#define EMPTY_STACK -1
#define TREE_HEIGHT 4
#define QUEUE_FRONT 0

void
insert(struct Node** root, int data)
{
	// Make a new Node
	struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp->data  = data;
	tmp->left  = NULL;
	tmp->right = NULL;

	// Check if the Tree is Empty
	if ((*root) == NULL)
		(*root) = tmp;
	else
	{
		struct Node* prev = NULL;
		struct Node* cur  = (*root);

		while (cur != NULL)
		{
			prev = cur;

			if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}

		if (data < prev->data)
			prev->left = tmp;
		else
			prev->right = tmp;
	}
}


void
find(struct Node* root, int data)
{
	while (root != NULL)
	{
		if (root->data == data)
		{
			printf("\n\tNode %d does exist in the Tree!\n\n", data);
			return;
		}

		if (data < root->data)
			root = root->left;
		else
			root = root->right;
	}

	printf("\n\tNode %d does NOT exist in the Tree!\n\n", data);
}


void
print_preorder(struct Node* root)
{
	if (root == NULL)
		return;
	
	printf("%d ", root->data);

	if (root->left != NULL)
		print_preorder(root->left);

	if (root->right != NULL)
		print_preorder(root->right);
}


void
print_inorder(struct Node* root)
{
	if (root == NULL)
		return;
	
	if (root->left != NULL)
		print_inorder(root->left);
	
	printf("%d ", root->data);

	if (root->right != NULL)
		print_inorder(root->right);
}


void
print_postorder(struct Node* root)
{
	if (root == NULL)
		return;
	
	if (root->left != NULL)
		print_postorder(root->left);
	
	if (root->right != NULL)
		print_postorder(root->right);
	
	printf("%d ", root->data);
}


void
iter_print_preorder(struct Node* root)
{
	if (root == NULL)
		return;

	int sp = EMPTY_STACK;
	struct Node** stack = malloc(sizeof(struct Node*) * 500);

	stack[++sp] = root;
	while (sp != EMPTY_STACK)
	{
		root = stack[sp--];
		printf("%d ", root->data);

		if (root->right != NULL)
			stack[++sp] = root->right;

		if (root->left != NULL)
			stack[++sp] = root->left;
	}
	free(stack);
}


void
iter_print_inorder(struct Node* root)
{
	if (root == NULL)
		return;
	
	int sp = EMPTY_STACK;
	struct Node** stack = malloc(sizeof(struct Node*) * TREE_HEIGHT);

	for(;;)
	{
		if (root != NULL)
		{
			stack[++sp] = root;
			root = root->left;
		}
		else
		{
			if (sp == EMPTY_STACK)
				break;

			root = stack[sp--];
			printf("%d ", root->data);
			root = root->right;
		}
	}
	free(stack);
}


void
iter_print_postorder(struct Node* root)
{
	if (root == NULL)
		return;
	
	int sp_1 = EMPTY_STACK;
	int sp_2 = EMPTY_STACK;
	struct Node** stack_1 = malloc(sizeof(struct Node*) * pow(2, TREE_HEIGHT));
	struct Node** stack_2 = malloc(sizeof(struct Node*) * pow(2, TREE_HEIGHT));

	stack_1[++sp_1] = root;

	while (sp_1 != EMPTY_STACK)
	{
		root = stack_1[sp_1--];
		stack_2[++sp_2] = root;

		if (root->left != NULL)
			stack_1[++sp_1] = root->left;

		if (root->right != NULL)
			stack_1[++sp_1] = root->right;
	}

	while (sp_2 != EMPTY_STACK)
	{
		root = stack_2[sp_2--];
		printf("%d ", root->data);
	}
	free(stack_1);
	free(stack_2);
}

void
iter_print_levelorder(struct Node* root)
{
	if (root == NULL)
		return;
	
	int front = QUEUE_FRONT;
	int rear  = QUEUE_FRONT;
	struct Node** queue = malloc(sizeof(struct Node*) * pow(2, TREE_HEIGHT - 1));
	
	for(;;)
	{
		printf("%d ", root->data);

		if (root->left != NULL)
			queue[rear++] = root->left;

		if (root->right != NULL)
			queue[rear++] = root->right;

		if (front == rear)
			break;

		root = queue[front++];
	}
	free(queue);
}
