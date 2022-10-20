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
