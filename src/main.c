#include "tree.h"
#define ZERO_LEVEL 0


int
main()
{
	struct Node* root = NULL;

	// ==========================================
	// ================= TEST 1 =================
	// ==========================================	
	// insert(&root, 6);
	// insert(&root, 3);
	// insert(&root, 9);
	// insert(&root, 1);
	// insert(&root, 5);
	// insert(&root, 7);
	// insert(&root, 11);

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n");
	// printf("\t============================\n");
	// printf("\t======= VALIDATE BST =======\n");
	// printf("\t============================\n");
	// printf("\n\n");

	// if (validate_BST(root) != INT_MIN)
	// 	printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	// else
	// 	printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");




	// ==========================================
	// ================= TEST 2 =================
	// ==========================================	
	// insert(&root, 6);
	// insert(&root, 3);
	// insert(&root, 9);
	// insert(&root, 1);
	// insert(&root, 5);
	// insert(&root, 7);
	// insert(&root, 11);

	// struct Node* change = root->left; // 3 => 8
	// change->data = 8;

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n");
	// printf("\t============================\n");
	// printf("\t======= VALIDATE BST =======\n");
	// printf("\t============================\n");
	// printf("\n\n");

	// if (validate_BST(root) != INT_MIN)
	// 	printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	// else
	// 	printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");


	// ==========================================
	// ================= TEST 3 =================
	// ==========================================
	// insert(&root, 15);
	// insert(&root, 9);
	// insert(&root, 11);
	// insert(&root, 10);
	// insert(&root, 14);
	// insert(&root, 13);
	// insert(&root, 5);
	// insert(&root, 2);
	// insert(&root, 1);
	// insert(&root, 3);
	// insert(&root, 7);
	// insert(&root, 25);
	// insert(&root, 22);
	// insert(&root, 28);
	// insert(&root, 18);
	// insert(&root, 0);

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n");
	// printf("\t============================\n");
	// printf("\t======= VALIDATE BST =======\n");
	// printf("\t============================\n");
	// printf("\n\n");

	// if (validate_BST(root) != INT_MIN)
	// 	printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	// else
	// 	printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");



	// ==========================================
	// ================= TEST 4 =================
	// ==========================================
	// insert(&root, 15);
	// insert(&root, 9);
	// insert(&root, 11);
	// insert(&root, 10);
	// insert(&root, 14);
	// insert(&root, 13);
	// insert(&root, 5);
	// insert(&root, 2);
	// insert(&root, 1);
	// insert(&root, 3);
	// insert(&root, 7);
	// insert(&root, 25);
	// insert(&root, 22);
	// insert(&root, 28);
	// insert(&root, 18);
	// insert(&root, 0);

	// struct Node* change = root->right->left; // 22 => 16
	// change->data = 16;

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n");
	// printf("\t============================\n");
	// printf("\t======= VALIDATE BST =======\n");
	// printf("\t============================\n");
	// printf("\n\n");

	// if (validate_BST(root) != INT_MIN)
	// 	printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	// else
	// 	printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");



	// ==========================================
	// ================= TEST 5 =================
	// ==========================================
	// insert(&root, 15);
	// insert(&root, 9);
	// insert(&root, 11);
	// insert(&root, 10);
	// insert(&root, 14);
	// insert(&root, 13);
	// insert(&root, 5);
	// insert(&root, 2);
	// insert(&root, 1);
	// insert(&root, 3);
	// insert(&root, 3); // Duplicates
	// insert(&root, 7);
	// insert(&root, 25);
	// insert(&root, 22);
	// insert(&root, 28);
	// insert(&root, 18);
	// insert(&root, 0);

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n");
	// printf("\t============================\n");
	// printf("\t======= VALIDATE BST =======\n");
	// printf("\t============================\n");
	// printf("\n\n");

	// if (validate_BST(root) != INT_MIN)
	// 	printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	// else
	// 	printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");



	// ==========================================
	// ================= TEST 6 =================
	// ==========================================
	// insert(&root, 15);
	// insert(&root, 9);
	// insert(&root, 11);
	// insert(&root, 10);
	// insert(&root, 14);
	// insert(&root, 13);
	// insert(&root, 5);
	// insert(&root, 2);
	// insert(&root, 1);
	// insert(&root, 3);
	// insert(&root, 3); // Duplicates
	// insert(&root, 7);
	// insert(&root, 25);
	// insert(&root, 22);
	// insert(&root, 28);
	// insert(&root, 18);
	// insert(&root, 0);

	// struct Node* change = root->left; // 9 -> 5    |NOT a BST|
	// change->data = 5;

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n");
	// printf("\t============================\n");
	// printf("\t======= VALIDATE BST =======\n");
	// printf("\t============================\n");
	// printf("\n\n");

	// if (validate_BST(root) != INT_MIN)
	// 	printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	// else
	// 	printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");



	// ==========================================
	// ================= TEST 7 =================
	// ==========================================
	// insert(&root, 15);
	// insert(&root, 9);
	// insert(&root, 11);
	// insert(&root, 10);
	// insert(&root, 14);
	// insert(&root, 13);
	// insert(&root, 5);
	// insert(&root, 2);
	// insert(&root, 1);
	// insert(&root, 3);
	// insert(&root, 3); // Duplicates
	// insert(&root, 7);
	// insert(&root, 25);
	// insert(&root, 22);
	// insert(&root, 28);
	// insert(&root, 18);
	// insert(&root, 0);

	// struct Node* change = root->left; // 9 -> 11    |INDEED a BST|
	// change->data = 11;

	// printf("\n\nTree:\n");
	// visual_print(root);

	// printf("\n\n");
	// printf("\t============================\n");
	// printf("\t======= VALIDATE BST =======\n");
	// printf("\t============================\n");
	// printf("\n\n");

	// if (validate_BST(root) != INT_MIN)
	// 	printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	// else
	// 	printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");



	// ==========================================
	// ================= TEST 8 =================
	// ==========================================
	insert(&root, 15);
	insert(&root, 9);
	insert(&root, 11);
	insert(&root, 10);
	insert(&root, 14);
	insert(&root, 13);
	insert(&root, 5);
	insert(&root, 2);
	insert(&root, 1);
	insert(&root, 3);
	insert(&root, 3); // Duplicates
	insert(&root, 7);
	insert(&root, 25);
	insert(&root, 22);
	insert(&root, 28);
	insert(&root, 18);
	insert(&root, 0);

	struct Node* change = root->left; // 9 -> 14    |NOT a BST|
	change->data = 14;

	printf("\n\nTree:\n");
	visual_print(root);

	printf("\n\n");
	printf("\t============================\n");
	printf("\t======= VALIDATE BST =======\n");
	printf("\t============================\n");
	printf("\n\n");

	if (validate_BST(root) != INT_MIN)
		printf("\tTree is INDEED a BST(Binary Search Tree)!\n\n");
	else
		printf("\tTree is NOT a BST(Binary Search Tree)!\n\n");

	return 0;
}
