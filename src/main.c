#include "tree.h"
#define ZERO_LEVEL 0


int
main()
{
	struct Node* root = NULL;

	// ==========================================
	// ================= TEST 1 =================
	// ==========================================
	
	int size = 16;
	int array[size];

	// Fill the array
	for (int i = 0; i < size; i++)
		array[i] = i + 1;

	/* Minimal Tree */
	root = minimal_tree(array, 0, size-1, size);

	printf("\n\nMinimal Tree:\n\t\t");
	print_inorder(root);
	printf("\n\n\n");

	/* Minimal Tree Visual */
	root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	printf("\n\nMinimal Tree Visual:\n\n");
	visual_print(root);



	// ==========================================
	// ================= TEST 2 =================
	// ==========================================
	// size = 7;
	// array[0] = 1;
	// array[1] = 3;
	// array[2] = 5;
	// array[3] = 6;
	// array[4] = 7;
	// array[5] = 9;
	// array[6] = 11;

	// /* Minimal Tree */
	// root = minimal_tree(array, 0, size-1, size);

	// printf("\n\nMinimal Tree:\n\t\t");
	// print_inorder(root);
	// printf("\n\n\n");

	// /* Minimal Tree Visual */
	// root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	// printf("\n\nMinimal Tree Visual:\n\n");
	// visual_print(root);



	// ==========================================
	// ================= TEST 3 =================
	// ==========================================
	// size = 4;
	// array[0] = 1;
	// array[1] = 4;
	// array[2] = 7;
	// array[3] = 9;

	// /* Minimal Tree */
	// root = minimal_tree(array, 0, size-1, size);

	// printf("\n\nMinimal Tree:\n\t\t");
	// print_inorder(root);
	// printf("\n\n\n");

	// /* Minimal Tree Visual */
	// root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	// printf("\n\nMinimal Tree Visual:\n\n");
	// visual_print(root);



	// ==========================================
	// ================= TEST 4 =================
	// ==========================================
	// size = 9;

	// // Fill the array
	// for (int i = 0; i < size; i++)
	// 	array[i] = i + 1;

	// /* Minimal Tree */
	// root = minimal_tree(array, 0, size-1, size);

	// printf("\n\nMinimal Tree:\n\t\t");
	// print_inorder(root);
	// printf("\n\n\n");

	// /* Minimal Tree Visual */
	// root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	// printf("\n\nMinimal Tree Visual:\n\n");
	// visual_print(root);


	return 0;
}
