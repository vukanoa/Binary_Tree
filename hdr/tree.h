#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <limits.h>

// struct Node{
// 	int data;
// 	struct Node* left;
// 	struct Node* right;
// 	int level;
// };

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
	int level;
	int size;
};

// Binary Tree functions
void         insert       (struct Node** root, int data);
void         insert_parent(struct Node** root, int data);
void         insert_size  (struct Node** root, int data);
void         find         (struct Node*  root, int data);
struct Node* find_ret     (struct Node*  root, int data);
void         del_node_iter(struct Node** root, int data);
struct Node* del_node_rec (struct Node*  root, int data);

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
int int_pow           (int base,   int exp);
int calculate_spaces  (int levels, int cur_level);
int check_power_of_two(int number);
int which_power_of_two(int two_pow);
int height_of_tree    ();

int          find_min_data(struct Node* root);
struct Node* find_min     (struct Node* root);
struct Node* get_ith_node (struct Node* root, int i);


// Binary Tree Problems
struct Node*  minimal_tree           (int* array, int left, int right, int size);
struct Node*  minimal_tree_visual    (int* array, int left, int right, int size, int level);
struct Node** list_of_depths         (struct Node* root);
int           check_balanced         (struct Node* root);
int           check_balanced_improved(struct Node* root);
int           validate_BST           (struct Node* root);
struct Node*  successor              (struct Node* root);
struct Node*  common_ancestor_0      (struct Node* first, struct Node* second); // Parents
struct Node*  random_node            (struct Node* root);

#endif //TREE_H
