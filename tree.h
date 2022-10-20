#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

void insert	(struct Node** root, int data);
void find	(struct Node*  root, int data);

/* Orders of printing */

// Recursive priting
void print_preorder(struct Node* root);

#endif //TREE_H
