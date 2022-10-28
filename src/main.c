#include <time.h>
#include "tree.h"
#define ZERO_LEVEL 0


int
main()
{
	struct Node* root = NULL;

	insert_size(&root, 15);
	insert_size(&root, 9);
	insert_size(&root, 11);
	insert_size(&root, 10);
	insert_size(&root, 14);
	insert_size(&root, 13);
	insert_size(&root, 5);
	insert_size(&root, 2);
	insert_size(&root, 1);
	insert_size(&root, 3);
	insert_size(&root, 7);
	insert_size(&root, 25);
	insert_size(&root, 22);
	insert_size(&root, 28);
	insert_size(&root, 18);
	insert_size(&root, 0);

	// insert_size(&root, 20);
	// insert_size(&root, 10);
	// insert_size(&root, 30);
	// insert_size(&root, 35);
	// insert_size(&root, 15);
	// insert_size(&root, 17);
	// insert_size(&root,  5);
	// insert_size(&root,  7);
	// insert_size(&root,  3);


	printf("\n\nTree:\n");
	visual_print(root);

	printf("\n\n");
	printf("\t===========================\n");
	printf("\t======= RANDOM NODE =======\n");
	printf("\t===========================\n");
	printf("\n\n");

	// ==========================================
	// ================= TEST 0 =================
	// ==========================================

	/* Test Uniformity of Random numbers */

	// int x = 0;
	// srand(time(NULL));
	// int a[9];

	// for (int i = 0; i < 9; i++)
	// 	a[i] = 0;

	// for (int i  = 0; i < 100000; i++)
	// {
	// 	x = rand() % 9;
	// 	a[x]++;
	// }

	// for (int i = 0; i < 9; i++)
	// 	printf("a[%d] = %d\n", i, a[i]);
	


	// ==========================================
	// ================= TEST 1 =================
	// ==========================================
	root = random_node(root);
	printf("\t\tRandom Node: %d\n\n", root->data);



	return 0;
}
