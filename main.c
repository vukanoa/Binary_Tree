#include "tree.h"

int
main()
{
	struct Node* root = NULL;

	insert(&root, 5);
	insert(&root, 8);
	insert(&root, 2);
	insert(&root, 9);
	insert(&root, 7);

	find(root, 8);
	find(root, 6);

	printf("\n\t");
	print_preorder(root);
	printf("\n\n");

	return 0;
}
