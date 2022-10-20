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
	printf("Preorder: (Recursive)\n\t");
	print_preorder(root);
	printf("\n");
	printf("Preorder: (Iterative)\n\t");
	iter_print_preorder(root);
	printf("\n\n");

	printf("Inorder:\n\t");
	print_inorder(root);
	printf("\n");
	printf("Inorder: (Iterative)\n\t");
	iter_print_inorder(root);
	printf("\n\n");

	printf("Postorder:\n\t");
	print_postorder(root);
	printf("\n");
	printf("Postorder: (Iterative)\n\t");
	iter_print_postorder(root);
	printf("\n\n");


/*
		5
	2		8
	  3	  7   9
*/
	return 0;
}
