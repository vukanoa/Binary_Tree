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

	printf("\n");
	printf("Preorder:\n\t");
	print_preorder(root);
	printf("\n\n");

	printf("Inorder:\n\t");
	print_inorder(root);
	printf("\n\n");

	printf("Postorder:\n\t");
	print_postorder(root);
	printf("\n\n");
	return 0;
}
