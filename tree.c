#include <stdlib.h>
#include "tree.h"

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
