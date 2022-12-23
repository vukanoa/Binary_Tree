#include <time.h>
#include "tree.h"
#define ZERO_LEVEL 0


int
main()
{
	struct Node* root_T1 = NULL;
	struct Node* root_T2 = NULL;

	printf("\n\n");
	printf("\t=============================\n");
	printf("\t======= CHECK SUBTREE =======\n");
	printf("\t=============================\n\n");

	// ==========================================
	// ================= TEST 0 =================
	// ==========================================

	/* T1 */
	// insert(&root_T1, 20);
	// insert(&root_T1, 25);
	// insert(&root_T1, 22);
	// insert(&root_T1, 27);
	// insert(&root_T1, 21);
	// insert(&root_T1, 23);
	// insert(&root_T1, 7);
	// insert(&root_T1, 4);
	// insert(&root_T1, 3);
	// insert(&root_T1, 5);
	// insert(&root_T1, 10);
	// insert(&root_T1, 12);
	// insert(&root_T1, 11);

	// printf("\n\nT1:\n");
	// visual_print(root_T1);


	// /* T2 */
	// insert(&root_T2, 7);
	// insert(&root_T2, 4);
	// insert(&root_T2, 3);
	// insert(&root_T2, 5);
	// insert(&root_T2, 10);
	// insert(&root_T2, 12);
	// insert(&root_T2, 11);

	// printf("\n\n\n\nT2:\n");
	// visual_print(root_T2);

	// printf("Result:");

	// if (check_subtree(root_T1, root_T2))
	// 	printf("\n\tT2 is INDEED a subtree of T1!\n\n");
	// else
	// 	printf("\n\tT2 is NOT a subtree of T1!\n\n");



	// ==========================================
	// ================= TEST 1 =================
	// ==========================================

	/* T1 */
	// insert(&root_T1, 20);
	// insert(&root_T1, 25);
	// insert(&root_T1, 22);
	// insert(&root_T1, 27);
	// insert(&root_T1, 21);
	// insert(&root_T1, 23);
	// insert(&root_T1, 7);
	// insert(&root_T1, 4);
	// insert(&root_T1, 3);
	// insert(&root_T1, 5);
	// insert(&root_T1, 10);
	// insert(&root_T1, 12);
	// insert(&root_T1, 11);

	// printf("\n\nT1:\n");
	// visual_print(root_T1);

	// /* T2 */
	// insert(&root_T2, 7);
	// insert(&root_T2, 4);
	// insert(&root_T2, 3);
	// insert(&root_T2, 5);
	// insert(&root_T2, 10);
	// insert(&root_T2, 12);
	// insert(&root_T2, 11);

	// find_and_replace(root_T2, 5, 6);

	// printf("\n\n\n\nT2:\n");
	// visual_print(root_T2);

	// printf("Result:");

	// if (check_subtree(root_T1, root_T2))
	// 	printf("\n\tT2 is INDEED a subtree of T1!\n\n");
	// else
	// 	printf("\n\tT2 is NOT a subtree of T1!\n\n");




	// ==========================================
	// ================= TEST 2 =================
	// ==========================================

	/* T1 */
	// insert(&root_T1, 21);
	// insert(&root_T1, 25);
	// insert(&root_T1, 22);
	// insert(&root_T1, 27);
	// insert(&root_T1, 17);
	// insert(&root_T1, 19);
	// insert(&root_T1, 20);
	// insert(&root_T1, 18);
	// insert(&root_T1, 15);
	// insert(&root_T1, 16);
	// insert(&root_T1, 13);

	// find_and_replace(root_T1, 21, 1);
	// find_and_replace(root_T1, 25, 6);
	// find_and_replace(root_T1, 22, 2);
	// find_and_replace(root_T1, 27, 15);
	// find_and_replace(root_T1, 17, 7);
	// find_and_replace(root_T1, 15, 8);
	// find_and_replace(root_T1, 19, 3);
	// find_and_replace(root_T1, 13, 9);
	// find_and_replace(root_T1, 16, 4);
	// find_and_replace(root_T1, 18, 2);
	// find_and_replace(root_T1, 20, 5);

	// printf("\n\nT1:\n");
	// visual_print(root_T1);

	// /* T2 */
	// insert(&root_T2, 21);
	// insert(&root_T2, 25);
	// insert(&root_T2, 22);
	// insert(&root_T2, 27);
	// insert(&root_T2, 17);
	// insert(&root_T2, 19);
	// insert(&root_T2, 15);

	// find_and_replace(root_T2, 21, 7);
	// find_and_replace(root_T2, 25, 3);
	// find_and_replace(root_T2, 27, 5);
	// find_and_replace(root_T2, 22, 2);
	// find_and_replace(root_T2, 17, 8);
	// find_and_replace(root_T2, 15, 9);
	// find_and_replace(root_T2, 19, 4);

	// printf("\n\n\n\nT2:\n");
	// visual_print(root_T2);

	// printf("Result:");

	// if (check_subtree(root_T1, root_T2))
	// 	printf("\n\tT2 is INDEED a subtree of T1!\n\n");
	// else
	// 	printf("\n\tT2 is NOT a subtree of T1!\n\n");




	// ==========================================
	// ================= TEST 3 =================
	// ==========================================

	/* T1 */
	insert(&root_T1, 21);
	insert(&root_T1, 25);
	insert(&root_T1, 22);
	insert(&root_T1, 27);
	insert(&root_T1, 17);
	insert(&root_T1, 19);
	insert(&root_T1, 20);
	insert(&root_T1, 18);
	insert(&root_T1, 15);
	insert(&root_T1, 16);
	insert(&root_T1, 13);

	find_and_replace(root_T1, 21, 1);
	find_and_replace(root_T1, 25, 6);
	find_and_replace(root_T1, 22, 2);
	find_and_replace(root_T1, 27, 15);
	find_and_replace(root_T1, 17, 7);
	find_and_replace(root_T1, 15, 8);
	find_and_replace(root_T1, 19, 3);
	find_and_replace(root_T1, 13, 9);
	find_and_replace(root_T1, 16, 4);
	find_and_replace(root_T1, 18, 2);
	find_and_replace(root_T1, 20, 5);

	printf("\n\nT1:\n");
	visual_print(root_T1);

	/* T2 */
	insert(&root_T2, 21);
	insert(&root_T2, 25);
	insert(&root_T2, 22);
	insert(&root_T2, 27);
	insert(&root_T2, 17);
	insert(&root_T2, 19);
	insert(&root_T2, 15);

	find_and_replace(root_T2, 21, 7);
	find_and_replace(root_T2, 25, 3);
	find_and_replace(root_T2, 27, 5);
	find_and_replace(root_T2, 22, 2);
	find_and_replace(root_T2, 17, 8);
	find_and_replace(root_T2, 15, 9);
	find_and_replace(root_T2, 19, 4);

	// Difference from the previous Test
	find_and_replace(root_T2, 8, 6);

	printf("\n\n\n\nT2:\n");
	visual_print(root_T2);

	printf("Result:");

	if (check_subtree(root_T1, root_T2))
		printf("\n\tT2 is INDEED a subtree of T1!\n\n");
	else
		printf("\n\tT2 is NOT a subtree of T1!\n\n");


	return 0;
}
