#include "tree.h"

int
main()
{
	struct Node* root = NULL;

	// --------------------------
	// --- First set of Tests ---
	// --------------------------

	/* Tests 0 - 6 */
	// insert(&root, 5);
	// insert(&root, 8);
	// insert(&root, 2);
	// insert(&root, 9);
	// insert(&root, 7);
	// insert(&root, 1);

	// insert(&root, 11); // Uncomment for Test 5
	// insert(&root, 6);  // Uncomment for Test 6


	// ---------------------------
	// --- Second set of Tests ---
	// ---------------------------

	/* Tests: 7 - 9 */
	// insert(&root, 5);
	// insert(&root, 8);
	// insert(&root, 3);
	// insert(&root, 10);
	// insert(&root, 7);
	// insert(&root, 1);
	// insert(&root, 11);

	// insert(&root, 6); // Uncomment for Test 7 onwards
	// insert(&root, 9); // Uncomment for Test 8
	// insert(&root, 0); // Uncomment for Test 9


	/* Tests: 10 - 15 */
	insert(&root, 5);
	insert(&root, 13);
	insert(&root, 3);
	insert(&root, 15);
	insert(&root, 12);
	insert(&root, 1);
	insert(&root, 16);

	insert(&root, 9);
	insert(&root, 14);

	insert(&root, 8);
	insert(&root, 10);
/*
		5
	2		8
  1	   	  7   9
*/
	visual_print(root);

							/* [Test: 0] */
	// del_node(&root, 2); // Does NOT exist

							/* [Tests: 1, 2 & 3] */
	/* Delete Leaves */
	// del_node(&root, 1);
	// del_node(&root, 7);
	// del_node(&root, 9);

	
							/* [Tests: 4, 5 & 6] */
	/* Delete parent of Leaves  */
	// del_node(&root, 8); // 9(Right one) is a Leaf
	// del_node(&root, 8); // 9(Right one) is NOT a Leaf and 7(Left one) is [Added 11]
	// del_node(&root, 2); // (Right one) doesn't exist and 1(Left one) is a Leaf


							/* [Tests: 7, 8, 9] */
	/* Delete parent of children without either left or right subtree */
	// del_node(&root, 8); // [Added 6]
	// del_node(&root, 8); // Right child has both left and right, but Left child does not
	// del_node(&root, 3);
	// del_node(&root, 13); // Nodes for "Tests: 10 - 15"


	/* Delete parent of children that have both subtrees */
	// del_node(&root, 5); Not Working

	visual_print(root);

	return 0;
}

