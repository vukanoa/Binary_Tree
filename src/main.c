#include "tree.h"
#define ZERO_LEVEL 0


int
main()
{
	struct Node* root = NULL;


	insert_parent(&root, 15);
	insert_parent(&root, 9);
	insert_parent(&root, 11);
	insert_parent(&root, 10);
	insert_parent(&root, 14);
	insert_parent(&root, 13);
	insert_parent(&root, 5);
	insert_parent(&root, 2);
	insert_parent(&root, 1);
	insert_parent(&root, 3);
	insert_parent(&root, 7);
	insert_parent(&root, 25);
	insert_parent(&root, 22);
	insert_parent(&root, 28);
	insert_parent(&root, 18);
	insert_parent(&root, 0);


	printf("\n\nTree:\n");
	visual_print(root);

	printf("\n\n");
	printf("\t=========================\n");
	printf("\t======= SUCCESSOR =======\n");
	printf("\t=========================\n");
	printf("\n\n");

	// ==========================================
	// ================= TEST 1 =================
	// ==========================================
	struct Node* leaf = root->left->right->right; // 14
	struct Node* next = successor(leaf);
	if (leaf != NULL)
	{
		if (next != NULL)
			printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
		else
			printf("\tThis node is last in inorder traversal. Successor doesn't exist!\n\n");
	}
	else
		printf("\tNULL node doesn't have successor!\n\n");



	// ==========================================
	// ================= TEST 2 =================
	// ==========================================
	// struct Node* leaf = root->left->right->right->left; // 13
	// struct Node* next = successor(leaf);
	// if (leaf != NULL)
	// {
	// 	if (next != NULL)
	// 		printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
	// 	else
	// 		printf("\tThis node is last in inorder traversal. Successor doesn't exist!\n\n");
	// }
	// else
	// 	printf("\tNULL node doesn't have successor!\n\n");



	// ==========================================
	// ================= TEST 3 =================
	// ==========================================
	// struct Node* leaf = root; // 15
	// struct Node* next = successor(leaf);
	// if (leaf != NULL)
	// {
	// 	if (next != NULL)
	// 		printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
	// 	else
	// 		printf("\tThis node is last in inorder traversal. Successor doesn't exist!\n\n");
	// }
	// else
	// 	printf("\tNULL node doesn't have successor!\n\n");



	// ==========================================
	// ================= TEST 4 =================
	// ==========================================
	// struct Node* leaf = root->right; // 25
	// struct Node* next = successor(leaf);
	// if (leaf != NULL)
	// {
	// 	if (next != NULL)
	// 		printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
	// 	else
	// 		printf("\tThis node is last in inorder traversal. Successor doesn't exist!\n\n");
	// }
	// else
	// 	printf("\tNULL node doesn't have successor!\n\n");



	// ==========================================
	// ================= TEST 5 =================
	// ==========================================
	// struct Node* leaf = root->left->left->left->left->left; // 0
	// struct Node* next = successor(leaf);
	// if (leaf != NULL)
	// {
	// 	if (next != NULL)
	// 		printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
	// 	else
	// 		printf("\tThis node is last in inorder traversal. Successor doesn't exist!\n\n");
	// }
	// else
	// 	printf("\tNULL node doesn't have successor!\n\n");



	// ==========================================
	// ================= TEST 6 =================
	// ==========================================
	// struct Node* leaf = root->left->left->right; // 7
	// struct Node* next = successor(leaf);
	// if (leaf != NULL)
	// {
	// 	if (next != NULL)
	// 		printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
	// 	else
	// 		printf("\tThis node is last in inorder traversal. Successor doesn't exist!\n\n");
	// }
	// else
	// 	printf("\tNULL node doesn't have successor!\n\n");



	// ==========================================
	// ================= TEST 7 =================
	// ==========================================
	// struct Node* leaf = root->right->right; // 28
	// struct Node* next = successor(leaf);
	// if (leaf != NULL)
	// {
	// 	if (next != NULL)
	// 		printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
	// 	else
	// 		printf("\tNode %d is the LAST inorder node. Successor doesn't exist!\n\n", leaf->data);
	// }
	// else
	// 	printf("\tNULL node doesn't have successor!\n\n");



	// ==========================================
	// ================= TEST 8 =================
	// ==========================================
	// struct Node* leaf = NULL;
	// struct Node* next = successor(leaf);
	// if (leaf != NULL)
	// {
	// 	if (next != NULL)
	// 		printf("\tNext inorder node of %d is %d\n\n", leaf->data, next->data);
	// 	else
	// 		printf("\tNode %d is the LAST inorder node. Successor doesn't exist!\n\n", leaf->data);
	// }
	// else
	// 	printf("\tNULL node doesn't have a successor!\n\n");

	return 0;
}
