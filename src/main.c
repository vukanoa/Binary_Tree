#include <time.h>
#include "tree.h"
#define ZERO_LEVEL 0


int
main()
{
	struct Node* root = NULL;

	printf("\n\n");
	printf("\t==============================\n");
	printf("\t======= PATHS WITH SUM =======\n");
	printf("\t==============================\n\n");


	// ==========================================
	// ================= TEST 0 =================
	// ==========================================

	insert(&root, 21);
	insert(&root, 27);
	insert(&root, 24);
	insert(&root, 32);
	insert(&root, 17);
	insert(&root, 19);
	insert(&root, 15);
	insert(&root, 18);
	insert(&root, 22);
	insert(&root, 23);
	insert(&root, 24);
	insert(&root, 30);
	insert(&root, 34);
	insert(&root, 33);

	find_and_replace(root, 21, 7);
	find_and_replace(root, 27, 9);
	find_and_replace(root, 24, -1);
	find_and_replace(root, 32, 3);
	find_and_replace(root, 17, 4);
	find_and_replace(root, 15, 2);
	find_and_replace(root, 19, -6);
	find_and_replace(root, 15, 2);
	find_and_replace(root, 18, 8);
	find_and_replace(root, 22, -4);
	find_and_replace(root, 23, 2);
	find_and_replace(root, 24, -2);
	find_and_replace(root, 30, 4);
	find_and_replace(root, 34, 6);
	find_and_replace(root, 33, 4);

	printf("\n\nTree:\n");
	visual_print(root);

	int target = 13;

	/* Solution */
	int result = paths_with_sum(root, target);

	printf("\n\tResult: %d\n\n", result);



	// ==========================================
	// ================= TEST 1 =================
	// ==========================================

	// insert(&root, 21);
	// insert(&root, 27);
	// insert(&root, 32);
	// insert(&root, 17);
	// insert(&root, 19);
	// insert(&root, 15);
	// insert(&root, 20);
	// insert(&root, 9);
	// insert(&root, 16);

	// find_and_replace(root, 21, 10);
	// find_and_replace(root, 27, -3);
	// find_and_replace(root, 32, 11);
	// find_and_replace(root, 17, 5);
	// find_and_replace(root, 15, 3);
	// find_and_replace(root, 19, 2);
	// find_and_replace(root, 15, 2);
	// find_and_replace(root, 20, 1);
	// find_and_replace(root,  9, 3);
	// find_and_replace(root, 16, -2);

	// printf("\n\nTree:\n");
	// visual_print(root);

	// int target = 8;

	// /* Solution */
	// int result = paths_with_sum(root, target);

	// printf("\n\tResult: %d\n\n", result);

	return 0;
}
