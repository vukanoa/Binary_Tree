#include "tree.h"
#define ZERO_LEVEL 0


int
main()
{
	struct Node* root = NULL;

	// ==========================================
	// ================= TEST 1 =================
	// ==========================================	
	insert(&root, 6);
	insert(&root, 3);
	insert(&root, 9);
	insert(&root, 1);
	insert(&root, 5);
	insert(&root, 7);
	insert(&root, 11);

	printf("\n\nTree:\n");
	visual_print(root);

	printf("\n\n\n");
	printf("\t==============================\n");
	printf("\t======= LIST OF DEPTHS =======\n");
	printf("\t==============================\n");

	struct Node** array_pointers = list_of_depths(root);

	for (int i = 0; i < height_of_tree(); i++)
	{
		root = array_pointers[i];
		printf("\n\nLevel %d:\n\t", i);
		while (root)
		{
			if (root->right == NULL)
				printf("%d", root->data);
			else
				printf("%d -> ", root->data);

			root = root->right;
		}
	}
	printf("\n\n\n");



	// ==========================================
	// ================= TEST 2 =================
	// ==========================================	
	// insert(&root, 6);

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n\n");
	// printf("\t==============================\n");
	// printf("\t======= LIST OF DEPTHS =======\n");
	// printf("\t==============================\n");

	// struct Node** array_pointers = list_of_depths(root);

	// for (int i = 0; i < height_of_tree(); i++)
	// {
	// 	root = array_pointers[i];
	// 	printf("\n\nLevel %d:\n\t", i);
	// 	while (root)
	// 	{
	// 		if (root->right == NULL)
	// 			printf("%d", root->data);
	// 		else
	// 			printf("%d -> ", root->data);

	// 		root = root->right;
	// 	}
	// }
	// printf("\n\n\n");



	// ==========================================
	// ================= TEST 3 =================
	// ==========================================	
	// insert(&root, 6);
	// insert(&root, 3);
	// insert(&root, 9);
	// insert(&root, 1);
	// insert(&root, 5);
	// insert(&root, 7);
	// insert(&root, 11);
	// insert(&root, 12);
	// insert(&root, 13);
	// insert(&root, 8);

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n\n");
	// printf("\t==============================\n");
	// printf("\t======= LIST OF DEPTHS =======\n");
	// printf("\t==============================\n");

	// struct Node** array_pointers = list_of_depths(root);

	// for (int i = 0; i < height_of_tree(); i++)
	// {
	// 	root = array_pointers[i];
	// 	printf("\n\nLevel %d:\n\t", i);
	// 	while (root)
	// 	{
	// 		if (root->right == NULL)
	// 			printf("%d ", root->data);
	// 		else
	// 			printf("%d -> ", root->data);

	// 		root = root->right;
	// 	}
	// }
	// printf("\n\n\n");



	// ==========================================
	// ================= TEST 4 =================
	// ==========================================	
	// insert(&root, 6);
	// insert(&root, 3);
	// insert(&root, 9);
	// insert(&root, 1);
	// insert(&root, 5);
	// insert(&root, 7);
	// insert(&root, 11);
	// insert(&root, 15);
	// insert(&root, 18);
	// insert(&root, 8);
	// insert(&root, 4);
	// insert(&root, 14);
	// insert(&root, 13);

	// printf("\nTree:\n\n");
	// visual_print(root);

	// printf("\n\n\n");
	// printf("\t==============================\n");
	// printf("\t======= LIST OF DEPTHS =======\n");
	// printf("\t==============================\n");

	// struct Node** array_pointers = list_of_depths(root);

	// for (int i = 0; i < height_of_tree(); i++)
	// {
	// 	root = array_pointers[i];
	// 	printf("\n\nLevel %d:\n\t", i);
	// 	while (root)
	// 	{
	// 		if (root->right == NULL)
	// 			printf("%d ", root->data);
	// 		else
	// 			printf("%d -> ", root->data);

	// 		root = root->right;
	// 	}
	// }
	// printf("\n\n\n");

	return 0;
}
