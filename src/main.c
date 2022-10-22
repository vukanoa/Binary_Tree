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
	insert(&root, 11);
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

	/* Delete Leaves */
	// del_node(&root, 1);
	// del_node(&root, 7);
	// del_node(&root, 9);

	/* Delete parent of Leaves */
	// del_node(&root, 8); // 9(Right one) is a Leaf
	// del_node(&root, 8); // 9(Right one) is NOT a Leaf and 7(Left one) is [Added 11]
	del_node(&root, 2); // (Right one) doesn't exist and 1(Left one) is a Leaf


	visual_print(root);


	return 0;
}
