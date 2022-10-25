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

	printf("\n\n\tMinimal Tree:\n\t\t\t");
	print_inorder(root);
	printf("\n\n\n");

	/* Minimal Tree Visual */
	root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	printf("\n\n\tMinimal Tree Visual:\n\n");
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

	// printf("\n\n\tMinimal Tree:\n\t\t\t");
	// print_inorder(root);
	// printf("\n\n\n");

	// /* Minimal Tree Visual */
	// root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	// printf("\n\n\tMinimal Tree Visual:\n\n");
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

	// printf("\n\n\tMinimal Tree:\n\t\t\t");
	// print_inorder(root);
	// printf("\n\n\n");

	// /* Minimal Tree Visual */
	// root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	// printf("\n\n\tMinimal Tree Visual:\n\n");
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

	// printf("\n\n\tMinimal Tree:\n\t\t\t");
	// print_inorder(root);
	// printf("\n\n\n");

	// /* Minimal Tree Visual */
	// root = minimal_tree_visual(array, 0, size-1, size, ZERO_LEVEL);

	// printf("\n\n\tMinimal Tree Visual:\n\n");
	// visual_print(root);


	return 0;
}


	/* TEST 1 */
	/* 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 */
	/*
								9
					5                       13
			3            7           11              15
		 2     4      6     8    10      12      14      16
	   1

	*/


	/* TEST 2 */
    /* 1 3 5 6 7 9 11 */
	/*
				6
			5       9
		  1   3   7   11
	*/


	/* TEST 3 */
	/* 1 4 7 9 */
	/*
				4
			1       7
					  9
	*/

	
	/* TEST 4 */
	/* 1 2 3 4 5 6 7 8 9 */
	/*
					5
			  3           8
		   2     4     7     9
		 1           6
	*/
