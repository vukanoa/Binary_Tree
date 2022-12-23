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

struct Result{
	struct Node* node;
	int is_ancestor;
};

/* Binary Tree functions */
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

/* Utility functions for visual print */
int int_pow           (int base,   int exp);
int calculate_spaces  (int levels, int cur_level);
int check_power_of_two(int number);
int which_power_of_two(int two_pow);
int height_of_tree    ();


/* Utility functions for Binary Tree Problems */
int            find_min_data    (struct Node* root);
struct Node*   find_min         (struct Node* root);
struct Node*   get_ith_node     (struct Node* root, int i);
struct Node*   go_up            (struct Node* node, int difference);
int            depth            (struct Node* node);
int            covers           (struct Node* root, struct Node* first);
struct Node*   sibling_of       (struct Node* node);
struct Node*   ancestor_helper  (struct Node* root, struct Node* first, struct Node* second);
struct Result* ancestor_helper_4(struct Node* root, struct Node* first, struct Node* second);
void           find_and_replace (struct Node* root, int target, int new_value);
void           deepest_level    (struct Node* root, int* level);
int            tree_height      (struct Node* root_T1);
struct Node*   exist_in_tree    (struct Node* root_T1, int x);
int            equal_trees      (struct Node* root_T1, struct Node* root_T2);


/* Binary Tree Problems */
struct Node*  minimal_tree           (int* array, int left, int right, int size);
struct Node*  minimal_tree_visual    (int* array, int left, int right, int size, int level);
struct Node** list_of_depths         (struct Node* root);
int           check_balanced         (struct Node* root);
int           check_balanced_improved(struct Node* root);
int           validate_BST           (struct Node* root);
struct Node*  successor              (struct Node* root);
struct Node*  common_ancestor_0      (struct Node* first, struct Node* second); // Parents
struct Node*  common_ancestor_1      (struct Node* first, struct Node* second); // Parents
struct Node*  common_ancestor_2      (struct Node* root,  struct Node* first, struct Node* second); // Parents
struct Node*  common_ancestor_3      (struct Node* root,  struct Node* first, struct Node* second);  // w/o Parents
struct Node*  common_ancestor_4      (struct Node* root,  struct Node* first, struct Node* second);  // w/o Parents
int           check_subtree          (struct Node* root_T1, struct Node* root_T2);
struct Node*  random_node            (struct Node* root);

#endif //TREE_H
