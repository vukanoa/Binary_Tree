#include "tree.h"

int
main()
{
	struct Node* root = NULL;

	/* Tests 1 - 9 */
	// insert(&root, 5);
	// insert(&root, 8);
	// insert(&root, 2);
	// insert(&root, 9);
	// insert(&root, 7);
	// insert(&root, 1);

	// insert(&root, 11); // Test 5
	// insert(&root, 6); // Test 6


	/* Tests: 10 - 18 */
	insert(&root, 5);
	insert(&root, 8);
	insert(&root, 3);
	insert(&root, 10);
	insert(&root, 7);
	insert(&root, 1);

	insert(&root, 11);
	insert(&root, 6);
	insert(&root, 9);
	insert(&root, 0);


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

							/* [Tests: 1, 2 & 3] */
	/* Delete Leaves */
	// del_node(&root, 1);
	// del_node(&root, 7);
	// del_node(&root, 9);

	
							/* [Tests: 4, 5 & 6] */
	/* Delete parent of Leaves  */
	// del_node(&root, 8); // 9(Right one) is a Leaf // Test 4
	// del_node(&root, 8); // 9(Right one) is NOT a Leaf and 7(Left one) is [Added 11]
	// del_node(&root, 2); // (Right one) doesn't exist and 1(Left one) is a Leaf


							/* [Tests: 7, 8, 9] */
	/* Delete parent of children without left or right subtree */
	// del_node(&root, 8); // Added 6
	// del_node(&root, 8); // 2nd set of Tests
	// del_node(&root, 8); // Right child has both left and right, but Left child does not
	del_node(&root, 2);

	visual_print(root);


	return 0;
}
