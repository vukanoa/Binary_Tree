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
	insert(&root, 1);
/*
		5
	2		8
  1	   	  7   9
*/
	printf("\n");
	printf("Level order: (Iterative)\n\t");
	iter_print_levelorder(root);
	printf("\n\n");

	visual_print(root);


	return 0;
}
