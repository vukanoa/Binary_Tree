#include "tree.h"

int
main()
{
	struct Node* root = NULL;

	insert(&root, 7);
	insert(&root, 12);
	insert(&root, 5);
	insert(&root, 18);
	insert(&root, 10);
	insert(&root, 3);
	insert(&root, 9);
	insert(&root, 11);
	insert(&root, 15);
	insert(&root, 21);
	insert(&root, 13);
	insert(&root, 16);
	insert(&root, 4);
	insert(&root, 2);
	insert(&root, 1);

	// Print before deletion
	visual_print(root);

	// =================================
	// ============= TESTS =============
	// =================================

	/* CASE 1: Delete Leaves */
	// del_node(&root, 1);
	// del_node(&root, 4);
	// del_node(&root, 9);
	// del_node(&root, 11);
	// del_node(&root, 13);
	// del_node(&root, 16);
	// del_node(&root, 21);



	/* CASE 2: Delete parent of children without either left or right subtree */
	// del_node(&root, 2);
	// del_node(&root, 5);
	// del_node(&root, 10); // Comment line 15 // insert(&root, 11); // Uncomment after



	/* CASE 3: Delete parent of children that have both subtrees */
	// del_node(&root, 3);
	// del_node(&root, 10);
	// del_node(&root, 15);
	// del_node(&root, 18);
	// del_node(&root, 12);
	del_node(&root, 7); // Delete Root



								/* Special cases */
	/* Non-existent Node */
	// del_node(&root, 6);

	/* Empty Tree */
	// Comment lines [8 - 22] // Including 8 and 22
	// del_node(&root, 3);
	

	printf("\n\n\n");

	// Print after deletion
	visual_print(root);

	return 0;
}
