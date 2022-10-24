#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	int level;
};

// Binary Tree functions
void insert	 (struct Node** root, int data);
void find	 (struct Node*  root, int data);

void         del_node            (struct Node** root, int data);
struct Node* del_node_recursively(struct Node*  root, int data);

/* Orders of printing */

// Recursive priting
void print_preorder (struct Node* root);
void print_inorder  (struct Node* root);
void print_postorder(struct Node* root);

// Iterative printing
void iter_print_preorder  (struct Node* root);
void iter_print_inorder   (struct Node* root);
void iter_print_postorder (struct Node* root);
void iter_print_levelorder(struct Node* root);

// Visual display of a Binary Tree
void visual_print(struct Node* head);

// Util functions
int int_pow(int base, int exp);
int calculate_spaces(int levels, int head_level);
int check_power_of_two(int number);
int which_power_of_two(int two_pow);

int          find_min_data(struct Node* root);
struct Node* find_min     (struct Node* root);

#endif //TREE_H
