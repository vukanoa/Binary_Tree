#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

void insert	(struct Node** root, int data);

#endif //TREE_H
