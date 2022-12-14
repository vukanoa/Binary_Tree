#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tree.h"

#define EMPTY_STACK -1
#define LAST_LEVEL_SPACES 3

int height_tree = -1;

/* Binary Tree Functions */
void
insert(struct Node** root, int data)
{
	// Make a new Node
	struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp->data  = data;
	tmp->left  = NULL;
	tmp->right = NULL;
	tmp->level = 0;

	int level = 0;

	// Check if the Tree is Empty
	if ((*root) == NULL)
	{
		if (level + 1 > height_tree)
			height_tree = level + 1;

		(*root) = tmp;
	}
	else
	{
		struct Node* prev = NULL;
		struct Node* cur  = (*root);

		while (cur != NULL)
		{
			level++;
			prev = cur;

			if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}

		tmp->level = level;
		if (level + 1 > height_tree)
			height_tree = level + 1;


		if (data < prev->data)
			prev->left = tmp;
		else
			prev->right = tmp;
	}
}


void
insert_parent(struct Node** root, int data)
{
	// Make a new Node
	struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp->data   = data;
	tmp->left   = NULL;
	tmp->right  = NULL;
	tmp->parent = NULL;
	tmp->level  = 0;

	int level = 0;

	// Check if the Tree is Empty
	if ((*root) == NULL)
	{
		if (level + 1 > height_tree)
			height_tree = level + 1;

		(*root) = tmp;
	}
	else
	{
		struct Node* prev = NULL;
		struct Node* cur  = (*root);

		while (cur != NULL)
		{
			level++;
			prev = cur;

			if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}

		tmp->level = level;
		if (level + 1 > height_tree)
			height_tree = level + 1;


		if (data < prev->data)
			prev->left = tmp;
		else
			prev->right = tmp;

		tmp->parent = prev;
	}
}


void
insert_size(struct Node** root, int data)
{
	// Make a new Node
	struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp->data  = data;
	tmp->left  = NULL;
	tmp->right = NULL;
	tmp->level = 0;
	tmp->size  = 1;

	int level = 0;

	// Check if the Tree is Empty
	if ((*root) == NULL)
	{
		if (level + 1 > height_tree)
			height_tree = level + 1;

		(*root) = tmp;
	}
	else
	{
		struct Node* prev = NULL;
		struct Node* cur  = (*root);

		while (cur != NULL)
		{
			level++;
			prev = cur;

			if (data < cur->data)
			{
				cur->size++;
				cur = cur->left;
			}
			else
			{
				cur->size++;
				cur = cur->right;
			}
		}

		tmp->level = level;
		if (level + 1 > height_tree)
			height_tree = level + 1;


		if (data < prev->data)
			prev->left = tmp;
		else
			prev->right = tmp;
	}


}


void
find(struct Node* root, int data)
{
	while (root != NULL)
	{
		if (root->data == data)
		{
			printf("\n\tnode %d does exist in the tree!\n\n", data);
			return;
		}

		if (data < root->data)
			root = root->left;
		else
			root = root->right;
	}

	printf("\n\tnode %d does not exist in the tree!\n\n", data);
}


struct Node*
find_ret(struct Node*  root, int data)
{
	while (root != NULL)
	{
		if (root->data == data)
			return root;

		if (data < root->data)
			root = root->left;
		else
			root = root->right;
	}

	return NULL;
}


void
del_node_iter(struct Node** root, int data)
{
	if ((*root) == NULL)
	{
		printf("\n\t\tTree is Empty! Unable to delete Node %d\n\n", data);
		return;
	}

	if ((*root)->data == data && (*root)->left == NULL && (*root)->right == NULL)
	{
		printf("\n\t\tRoot %d was successfully removed!", (*root)->data);
		(*root) = NULL;
		return;
	}

	struct Node* prev = NULL;
	struct Node* cur = (*root);

	while (cur != NULL)
	{
		if (cur->data == data)
		{
			/* Case 1: Delete Leaves */
			if (cur->left == NULL && cur->right == NULL)
			{
				if (prev->left == cur)
					prev->left = NULL;
				else
					prev->right = NULL;
			}
			/* Case 2: Delete parent with one child */
			else if (cur->left == NULL && cur->right != NULL)
			{
				if (prev->left == cur)
					prev->left = cur->right;
				else
					prev->right = cur->right;
			}
			else if (cur->left != NULL && cur->right == NULL)
			{
				if (prev->left == cur)
					prev->left = cur->left;
				else
					prev->right = cur->left;
			}
			/* Case 3: Delete parent with both left and right child */
			else
			{
				cur->data = find_min_data(cur->right);
				int tmp_data = cur->data;

				prev = cur;
				cur = cur->right;

				if (cur->data == tmp_data)
					prev->right = NULL;
				else
				{
					while (cur->data != tmp_data)
					{
						prev = cur;
						cur = cur->left;
					}
					prev->left = NULL;
				}
			}
			free(cur);
			cur = NULL;
		}
		else
		{
			prev = cur;
			if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;

			if (cur == NULL)
			{
				printf("\n\t\tNode %d does NOT exist in the Tree!\n", data);
				return;
			}
		}
	}

	printf("\n\t\tNode %d has been successfuly removed and the Tree remained sorted!\n\n", data);
}


struct Node*
del_node_rec(struct Node* root, int data)
{
	if (root == NULL)
		return NULL;
	else if (data < root->data)
		root->left = del_node_rec(root->left, data);
	else if (data > root->data)
		root->right = del_node_rec(root->right, data);
	else
	{
		// Case 1: No children
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		// Case 2: Either Left or Right child does NOT exist
		else if (root->left == NULL)
		{
			struct Node* tmp = root;
			root = root->right;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			struct Node* tmp = root;
			root = root->left;
			free(tmp);
		}
		// Case 3: Both children exist
		else
		{
			struct Node* tmp = find_min(root->right);
			root->data = tmp->data;
			root->right = del_node_rec(root->right, tmp->data);
		}
	}

	return root;
}


/* Orders of printing */

// Recursive printing
void
print_preorder(struct Node* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);

	if (root->left != NULL)
		print_preorder(root->left);

	if (root->right != NULL)
		print_preorder(root->right);
}


void
print_inorder(struct Node* root)
{
	if (root == NULL)
		return;

	if (root->left != NULL)
		print_inorder(root->left);

	printf("%d|%d| ", root->data, root->size);

	if (root->right != NULL)
		print_inorder(root->right);
}


void
print_postorder(struct Node* root)
{
	if (root == NULL)
		return;

	if (root->left != NULL)
		print_postorder(root->left);

	if (root->right != NULL)
		print_postorder(root->right);

	printf("%d ", root->data);
}


// Iterative printing
void
iter_print_preorder(struct Node* root)
{
	if (root == NULL)
		return;

	int sp = EMPTY_STACK;
	struct Node** stack = malloc(sizeof(struct Node*) * 500);

	stack[++sp] = root;
	while (sp != EMPTY_STACK)
	{
		root = stack[sp--];
		printf("%d ", root->data);

		if (root->right != NULL)
			stack[++sp] = root->right;

		if (root->left != NULL)
			stack[++sp] = root->left;
	}
	free(stack);
}


void
iter_print_inorder(struct Node* root)
{
	if (root == NULL)
		return;

	int sp = EMPTY_STACK;
	int height = tree_height(root);

	struct Node** stack = malloc(sizeof(struct Node*) * height);

	for(;;)
	{
		if (root != NULL)
		{
			stack[++sp] = root;
			root = root->left;
		}
		else
		{
			if (sp == EMPTY_STACK)
				break;

			root = stack[sp--];
			printf("%d ", root->data);
			root = root->right;
		}
	}
	free(stack);
}


void
iter_print_postorder(struct Node* root)
{
	if (root == NULL)
		return;

	int height = tree_height(root);
	int sp_1 = EMPTY_STACK;
	int sp_2 = EMPTY_STACK;

	struct Node** stack_1 = malloc(sizeof(struct Node*) * pow(2, height));
	struct Node** stack_2 = malloc(sizeof(struct Node*) * pow(2, height));

	stack_1[++sp_1] = root;

	while (sp_1 != EMPTY_STACK)
	{
		root = stack_1[sp_1--];
		stack_2[++sp_2] = root;

		if (root->left != NULL)
			stack_1[++sp_1] = root->left;

		if (root->right != NULL)
			stack_1[++sp_1] = root->right;
	}

	while (sp_2 != EMPTY_STACK)
	{
		root = stack_2[sp_2--];
		printf("%d ", root->data);
	}
	free(stack_1);
	free(stack_2);
}


void
iter_print_levelorder(struct Node* root)
{
	if (root == NULL)
		return;

	int front = -1;
	int rear  = -1;

	int queue_size = int_pow(2, height_tree - 1);
	struct Node** queue = malloc(sizeof(struct Node*) * queue_size);

	printf("\t");
	for(;;)
	{
		printf("%d ", root->data);

		if (root->left != NULL)
		{
			rear = (rear + 1) % queue_size;
			queue[rear] = root->left;
		}

		if (root->right != NULL)
		{
			rear = (rear + 1) % queue_size;
			queue[rear] = root->right;
		}

		if (front == rear && queue[front] == NULL)
			break;

		front = (front + 1) % queue_size;
		root = queue[front];
		queue[front] = NULL;
	}
	printf("\n");
	free(queue);
}


/* Visual display of a Binary Tree */
void
visual_print(struct Node* root)
{
	// Base case
	if (root == NULL)
	{
		printf("\n\tTree is Empty!\n\n");
		return;
	}
	else if (root != NULL && root->left == NULL && root->right == NULL)
	{
		printf("\n\t%d\n\n", root->data);
		return;
	}

	// Queue
	struct Node** queue = malloc(sizeof(struct Node*) * (int_pow(2, height_tree + 1)));	// +1 because Leaves have NULL nodes
	int front = 1; // Root is processed in First Iteration
	int rear  = 0;

	// Util variables
	int num_of_spaces = 0;
	int first_part = 0;
	int places_between = 0;
	int spaces = 0;
	int cur_level = 0;


	// Fill the Queue
	queue[rear++] = root;
	while (front < (int_pow(2, height_tree)))
	{
		if (root == NULL)
		{
			root = queue[front++];

			queue[rear++] = NULL;
			queue[rear++] = NULL;

			continue;
		}

		// Left
		if (root->left != NULL)
			queue[rear++] = root->left;
		else
			queue[rear++] = NULL;

		// Right
		if (root->right != NULL)
			queue[rear++] = root->right;
		else
			queue[rear++] = NULL;

		root = queue[front++];
	}

	front = 0;
	rear = int_pow(2, height_tree);
	while (front < rear - 1)
	{
		root = queue[front];
		cur_level = which_power_of_two(front+1); // 0

		if (front == 0) // First level
		{
			num_of_spaces = calculate_spaces(height_tree, root->level);
			first_part = num_of_spaces;

			// Spaces before root Node
			while (first_part--)
				printf("%2c", ' ');

			printf("%2d", root->data); // root Node itself

			// Spaces after root Node
			while (num_of_spaces--)
				printf("%2c", ' ');

			front++;
		}
		else if (check_power_of_two(front + 1)) /* Other levels */
		{
			if (which_power_of_two(front + 1) == height_tree - 1) /* If it's a LAST level */
			{
				printf("\n");
				front++;
				if (root == NULL)
					printf("%2c", ' ');
				else
					printf("%2d", root->data);

				places_between = int_pow(2, cur_level) - 1;
				num_of_spaces = calculate_spaces(height_tree, cur_level);
				first_part = num_of_spaces;

				while (places_between)
				{
					spaces = num_of_spaces;

					// Every odd place
					if (places_between % 2 != 0)
					{
						while (spaces--)
							printf("%2c", ' ');
					}
					else
							printf("%2c", ' ');

					if (queue[front] == NULL)
						printf("%2c", ' ');
					else
					{
						root = queue[front];
						printf("%2d", root->data);
					}

					front++;
					places_between--;
				}
			}
			else /* NOT a Last level */
			{
				printf("\n");
				front++;

				num_of_spaces = calculate_spaces(height_tree, cur_level);
				first_part = num_of_spaces;
				while (first_part--)
						printf("%2c", ' ');

				/*
					If Level is NOT First nor Last then we have
					[first_part] then [(depends)*places_between] then [same as first_part]

					=== for HEIGHT: 5 ===
					NOT -> 0) 23 x 23
					       1) 11 x 23 x 11
					       2)  5 x 11 x 11 x 11 x 5
					       3)  2 x 5  x 5  x 5  x 5  x 5  x 5  x 5  x 5  x 2
					NOT -> 4)  0 x 3  x 1  x 3  x 1  x 3  x 1  x 3  x 1  x 3  x 1  x 3  x 1  x 3  x 1  x 3  x 0
				*/

				first_part = num_of_spaces; /* Number of spaces before first element on the level */

				if (root == NULL)
					printf("%2c", ' ');
				else
					printf("%2d", root->data);

				/*
					=== for HEIGHT: 5 ===
					Level 0) NOT
					Level 1) places_between = 1
					Level 2) places_between = 3
					Level 3) places_between = 8
					Level 4) NOT [This is the Last level for HEIGHT: 5]
				*/
				places_between = int_pow(2, cur_level) - 1;

				/*
					=== for HEIGHT: 5 ===
					Level 0) NOT
					Level 1) num_of_spaces = 23
					Level 2) num_of_spaces = 11
					Level 3) num_of_spaces = 5
					Level 4) NOT [This is the Last level for HEIGHT: 5]
				*/
				num_of_spaces = calculate_spaces(height_tree, cur_level - 1);

				while (places_between)
				{
					spaces = num_of_spaces;
					while (spaces--)
						printf("%2c", ' ');

					if (queue[front] == NULL)
						printf("%2c", ' ');
					else
					{
						root = queue[front];
						printf("%2d", root->data);
					}

					front++;
					places_between--;
				}

				while (first_part--)
					printf("%2c", ' ');
			}
		}
	}

	free(queue);

	printf("\n\n");
}


/* Utility functions for visual print */
int
int_pow(int base, int exp)
{
	int result = 1;
	while(exp)
	{
		result *= base;
		exp--;
	}

	return result;
}


int
calculate_spaces(int height, int cur_level)
{
	if (cur_level + 2 > height)
		return LAST_LEVEL_SPACES;

	int num_1 = int_pow(2, (height - cur_level));
	int num_2 = int_pow(2, (height - cur_level - 2));

	return num_1 - num_2 - 1;
}


int
check_power_of_two(int number)
{
	if (number == 0)
		return 0; // NOT a power of two

	while (number != 1)
	{
		if (number % 2 != 0)
			return 0; // NOT a power of two

		number /= 2;
	}

	return 1; // INDEED a power of two
}


int
which_power_of_two(int number)
{
	if (number % 2 != 0 && number != 1) /* If Odd number except number 1, since number 1 is 2^0 */
		return 0; // NOT a power of two

	int cnt = 0;
	for(;;)
	{
		if (number == int_pow(2, cnt))
			break;

		if (int_pow(2, cnt) > number) /* If Even number and NOT a power of two */
			return 0; // NOT a power of two

		cnt++;
	}

	return cnt; // Return the power of two of a given number
}


int height_of_tree()
{
	return height_tree;
}


/* Utility functions for Binary Tree Problems */
int
find_min_data(struct Node* root)
{
	while (root->left != NULL)
		root = root->left;

	return root->data;
}


struct Node*
find_min(struct Node* root)
{
	while (root->left != NULL)
		root = root->left;

	return root;
}


struct Node*
get_ith_node(struct Node* root, int i)
{
	int left_size = root->left ? root->left->size : 0;

	if (i < left_size)
		return get_ith_node(root->left, i);
	else if (i == left_size)
		return root;
	else
		return get_ith_node(root->right, i - (left_size + 1));
}


struct Node*
go_up(struct Node* node, int difference)
{
	while (difference > 0 && node != NULL)
	{
		node = node->parent;
		difference--;
	}

	return node;
}


int
depth(struct Node* node)
{
	int depth = 0;
	while (node != NULL)
	{
		node = node->parent;
		depth++;
	}

	return depth;
}


int
covers(struct Node* root, struct Node* first)
{
	if (root == NULL)
		return 0;

	if (root == first)
		return 1;

	return covers(root->left, first) || covers(root->right, first);
}


struct Node*
sibling_of(struct Node* node)
{
	if (node == NULL || node->parent == NULL)
		return NULL;

	struct Node* parent = node->parent;

	return parent->left == node ? parent->right : parent->left;
}


struct Node*
ancestor_helper(struct Node* root, struct Node* first, struct Node* second)
{
	if (root == NULL || root == first || root == second)
		return root;

	int first_is_on_left  = covers(root->left, first);
	int second_is_on_left = covers(root->left, second);

	/* Nodes are on different sides */
	if (first_is_on_left != second_is_on_left)
		return root;

	struct Node* child_side = first_is_on_left ? root->left : root->right;

	return ancestor_helper(child_side, first, second);
}


struct Result*
ancestor_helper_4(struct Node* root, struct Node* first, struct Node* second)
{
	struct Result* result = (struct Result*) malloc(sizeof(struct Result));
	result->node = NULL;
	result->is_ancestor = 0;

	if (root == NULL)
		return result;

	if (root == first && root == second)
	{
		result->node = root;
		result->is_ancestor = 1;

		return result;
	}

	result->node = NULL;
	result->is_ancestor = 0;

	struct Result* result_x = ancestor_helper_4(root->left, first, second);
	if (result_x->is_ancestor)
		return result_x;

	struct Result* result_y = ancestor_helper_4(root->right, first, second);
	if (result_y->is_ancestor)
		return result_y;

	result->node = root;
	result->is_ancestor = 1;
	if (result_x->node != NULL && result_y->node != NULL)
		return result;
	else if (root == first || root == second)
	{
		/*
			If we're currently at first or second, and we also found one of
			those nodes in a subtree, then this is truly an ancestor and the
			flag should be true
		*/
		int is_ancestor = result_x->node != NULL || result_y->node != NULL;

		result->node = root;
		result->is_ancestor = is_ancestor;

		return result;
	}
	else
	{
		if (result_x->node != NULL)
			result->node = result_x->node;
		else
			result->node = result_y->node;

		result->is_ancestor = 0;

		return result;
	}
}


void
find_and_replace(struct Node* root, int target, int new_value)
{
	if (root == NULL)
		return;

	int front = -1;
	int rear  = -1;

	int root_height_tree = tree_height(root);

	int queue_size = int_pow(2, root_height_tree - 1);
	struct Node** queue = malloc(sizeof(struct Node*) * queue_size);

	for(;;)
	{
		if (root->data == target)
		{
			root->data = new_value;
			return;
		}


		if (root->left != NULL)
		{
			rear = (rear + 1) % queue_size;
			queue[rear] = root->left;
		}

		if (root->right != NULL)
		{
			rear = (rear + 1) % queue_size;
			queue[rear] = root->right;
		}

		if (front == rear && queue[front] == NULL)
			break;

		front = (front + 1) % queue_size;
		root = queue[front];
		queue[front] = NULL;
	}
	free(queue);
}


void
deepest_level(struct Node* root, int* level)
{
	if (root == NULL)
		return;

	if (root->level > *level)
		*level = root->level;

	if (root->left != NULL)
		deepest_level(root->left, level);

	if (root->right != NULL)
		deepest_level(root->right, level);
}


int
tree_height(struct Node* root)
{
	int level = 0;
	deepest_level(root, &level);

	return level + 1;
}


struct Node*
exist_in_tree(struct Node* root_T1, int x) // Level order check
{
	if (root_T1 == NULL)
		return 0;

	int front = -1;
	int rear  = -1;

	int root_T1_height_tree = tree_height(root_T1);

	int queue_size = int_pow(2, root_T1_height_tree - 1);
	struct Node** queue = malloc(sizeof(struct Node*) * queue_size);

	for(;;)
	{
		/* If it exists, return that node */
		if (root_T1->data == x)
			return root_T1;

		if (root_T1->left != NULL)
		{
			rear = (rear + 1) % queue_size;
			queue[rear] = root_T1->left;
		}

		if (root_T1->right != NULL)
		{
			rear = (rear + 1) % queue_size;
			queue[rear] = root_T1->right;
		}

		if (front == rear && queue[front] == NULL)
			break;

		front = (front + 1) % queue_size;
		root_T1 = queue[front];
		queue[front] = NULL;
	}
	free(queue);

	return NULL;
}


int
equal_trees(struct Node* root_T1, struct Node* root_T2) // Preorder compare
{
	if (root_T1 == NULL && root_T2 == NULL)
		return 1;
	else if (root_T1 == NULL && root_T2 != NULL)
		return 0;
	else if (root_T1 != NULL && root_T2 == NULL)
		return 0;
	else if (root_T1->data != root_T2->data) // Check current roots
		return 0;

	if (equal_trees(root_T1->left, root_T2->left) && equal_trees(root_T1->right, root_T2->right))
		return 1;

	return 0;
}


int
subtree(struct Node* root_T1, struct Node* root_T2)
{
	if (root_T1 == NULL) // Big tree empty & subtree still not found
		return 0;
	else if (root_T1->data == root_T2->data && equal_trees(root_T1, root_T2))
		return 1;

	return subtree(root_T1->left, root_T2) || subtree(root_T1->right, root_T2);
}


void
preorder_count_paths(struct Node* root, int* total, int target)
{
	if (root == NULL)
		return;

	int sum = 0;
	count_paths(root, &sum, total, target);

	if (root->left != NULL)
		preorder_count_paths(root->left, total, target);

	if (root->right != NULL)
		preorder_count_paths(root->right, total, target);
}


void
count_paths(struct Node* root, int* sum, int* total, int target)
{
	if (root == NULL)
		return;

	(*sum) += root->data;

	if ((*sum) == target)
		(*total)++;

	count_paths(root->left , sum, total, target);
	count_paths(root->right, sum, total, target);

	(*sum) -= root->data;
}


/* Binary Tree Problems */
struct Node*
minimal_tree(int* array, int left, int right, int size) // Original Algorithm
{
	// Base case
	if (array == NULL)
		return NULL;

	struct Node* root = (struct Node*) malloc(sizeof(struct Node));
	root->data = array[left + size/2];
	root->left = NULL;
	root->right = NULL;

	if (left >= right || size == 1) // Leaf
		return root;

	if (left < right)
		root->left = minimal_tree(array, left, left + size/2 - 1, size/2);

	if ((left + size/2)  < right)
		root->right = minimal_tree(array, left + size/2 + 1, right, right - (left+size/2 + 1) + 1); // size/2 - 1 doesn't work for every case

	return root;
}


struct Node*
minimal_tree_visual(int* array, int left, int right, int size, int level) // My tweak with node->level
{
	// Base case
	if (array == NULL)
		return NULL;

	// So that you can have multiple Tests run subsequently in one program
	if (left == 0 && right == size-1)
		height_tree = 0;

	struct Node* root = (struct Node*) malloc(sizeof(struct Node));
	root->data = array[left + size/2];
	root->left = NULL;
	root->right = NULL;
	root->level = level;

	if (left >= right || size == 1) // Leaf
	{
		if (height_tree < level + 1)
			height_tree = level + 1;

		return root;
	}

	if (left < right)
		root->left = minimal_tree_visual(array, left, left + size/2 - 1, size/2, level + 1);

	if ((left + size/2)  < right)
		root->right = minimal_tree_visual(array, left + size/2 + 1, right, right - (left+size/2 +1) + 1, level + 1);

	return root;
}


struct Node**
list_of_depths(struct Node* root)
{
	// Base case
	if (root == NULL)
		return NULL;

	int queue_size = int_pow(2, height_tree) - 1; // Nodes in a Perfect Tree
	struct Node** queue = malloc(sizeof(struct Node*) * queue_size);

	struct Node** array_of_lists = malloc(sizeof(struct Node*) * height_tree);

	int front = 1;
	int rear  = 0;

	queue[rear++] = root;
	while (front <= rear)
	{
		if (root->left)
			queue[rear++] = root->left;

		if (root->right)
			queue[rear++] = root->right;

		root = queue[front++];
	}

	front = 0;
	struct Node* tail = NULL; /* Normal order in Lists */
	while (front < rear)
	{
		if (array_of_lists[queue[front]->level] == NULL)
		{
			/* Normal order in Lists */
			tail = array_of_lists[queue[front]->level] = queue[front];

			/* Reverse order in Lists */
			// array_of_lists[queue[front]->level] = queue[front];

			queue[front]->left  = NULL;
			queue[front]->right = NULL;
		}
		else
		{
			queue[front]->left  = NULL;
			queue[front]->right = NULL;

			/* Normal order in Lists */
			tail->right = queue[front];
			tail = tail->right;

			/* Reverse order in Lists */
			// struct Node* tmp = array_of_lists[queue[front]->level];
			// array_of_lists[queue[front]->level] = queue[front];
			// array_of_lists[queue[front]->level]->right = tmp;
		}
		front++;
	}
	printf("\n");

	return array_of_lists;
}


int
check_balanced(struct Node* root) // O(NlogN)
{
	// Base case
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	int left  = check_balanced(root->left);
	int right = check_balanced(root->right);

	if (abs(left - right) < 2)
		return (left > right) ? left+1 : right+1;

	return 0;
}


/* Time  Complexity: O(n) */
/* Space Complexity: O(h) where 'h' is a height of tree */
int
check_balanced_improved(struct Node* root)
{
	// Base case
	if (root == NULL)
		return -1;

	int left = check_balanced_improved(root->left);
	if (left == INT_MIN)
		return INT_MIN;

	int right = check_balanced_improved(root->right);
	if (right == INT_MIN)
		return INT_MIN;

	if (abs(left - right) < 2)
		return (left > right) ? left+1 : right+1;

	return INT_MIN;
}


int
validate_BST(struct Node* root)
{
	// Base case
	if (root == NULL)
		return 1; // Empty Tree is a BST

	/* Left */
	int left = validate_BST(root->left);
	if (left == INT_MIN)
		return INT_MIN;

	if (root->left && root->data <= root->left->data)
		return INT_MIN;


	/* Right */
	int right = validate_BST(root->right);
	if (right == INT_MIN)
		return INT_MIN;

	if(root->right && root->data > root->right->data)
		return INT_MIN;

	return 1;
}


struct Node*
successor(struct Node* node)
{
	// Base case
	if (node == NULL)
		return NULL;

	if (node->right == NULL && node->parent == NULL)
		return NULL;

	if (node->right == NULL && node == node->parent->left)
		return node->parent;

	struct Node* parent;

	if (node->right != NULL)
	{
		// Return left most child
		parent = node;
		node = node->right;
		while (node != NULL)
		{
			parent = node;
			node = node->left;
		}

		return parent;
	}

	parent = node->parent;
	while(parent != NULL)
	{
		// Find the parent whose current node is his left child
		if (node == parent->left)
			return parent;

		node = parent;
		parent = parent->parent;
	}

	return parent;
}


struct Node*
common_ancestor_0(struct Node* first, struct Node* second)
{
	int difference = first->level - second->level;

	if (difference > 0)
	{
		while (difference--)
			first = first->parent;
	}
	else if (difference < 0)
	{
		difference = -difference;
		while (difference--)
			second = second->parent;
	}

	/* Now they are at esecondual level */
	while (first != NULL && second != NULL && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return first == NULL || second == NULL ? NULL : first;
}


struct Node*
common_ancestor_1(struct Node* first, struct Node* second)
{
	int difference = depth(first) - depth(second);

	struct Node* shallower = difference > 0 ? second : first;
	struct Node* deeper    = difference > 0 ? first  : second;

	deeper = go_up(deeper, abs(difference));

	/* Find where paths intersect(They are at the same level now) */
	while (shallower != NULL && deeper != NULL && shallower != deeper)
	{
		shallower = shallower->parent;
		deeper    = deeper->parent;
	}

	return shallower == NULL || deeper == NULL ? NULL : shallower;
}


/* Time  Complexity: O(t)

	Where 't' is the size of the subtree for the first commong ancestor.
	O(n) in the worst case, where 'n' is the number of nodes in the tree.
*/
/* Space Complexity: O(d)

	Where 'd' is the level of the deeper node. That many recursive calls
	will be called to find it.
*/
struct Node*
common_ancestor_2(struct Node* root,  struct Node* first, struct Node* second)
{
	/* Check if either node is NOT in the tree, or if one answers the other */
	if (!covers(root, first) || !(covers(root, second)))
		return NULL;
	else if (covers(first, second))
		return first;
	else if (covers(second, first))
		return second;

	/* Traverse upwards untill you find a node that covers 'second' */
	struct Node* sibling = sibling_of(first);
	struct Node* parent  = first->parent;

	while (!covers(sibling, second))
	{
		sibling = sibling_of(parent);
		parent  = parent->parent;
	}

	return parent;
}


/* Time  Complexity: O(n)

	This algorithm runs in O(n) time on a balanced tree. This is because
	'covers' is called on 2n nodes in the first call (n nodes for the left
	side, and n nodes for the right side).

	After that, the algorithm branches left or right, at which point 'covers'
	will be called on (2n/2) nodes, then (2n/4), and so on.

	This results in a runtime of O(n)
*/
/* Space Complexity: O(d)

	Where 'd' is the level of the deeper node. That many recursive calls
	will be called to find it.
*/
struct Node*
common_ancestor_3(struct Node* root, struct Node* first, struct Node* second)
{
	/* If either node is NOT in the tree */
	if (!covers(root, first) || !covers(root, second))
		return NULL;

	return ancestor_helper(root, first, second);
}


/* Time  Complexity:
	In the previous (common_ancestor_3) 'covers' searches all nodes under
	root first and second, including the nodes in each
	subtree(root->left, root->right). Then it picks one of those subtrees and
	searches all of its nodes.

	Each subtree is searched over and over again.

	We may recognize that we should only need to search the entire tree once to
	find 'first' and 'second'. We should then be able to "bubble up" the
	findings to earlier nodes in the stack.

	The basic logic is the same as the earlier solution.
*/
struct Node*
common_ancestor_4(struct Node* root,  struct Node* first, struct Node* second)
{
	struct Result* result = ancestor_helper_4(root, first, second);

	if (result->is_ancestor)
		return result->node;

	return NULL;
}


int
check_subtree(struct Node* root_T1, struct Node* root_T2)
{
	/* Since it doesn't have to be a BST do a levelorder check*/
	root_T1 = exist_in_tree(root_T1, root_T2->data);

	if (root_T1 == NULL)
		return 0;

	return equal_trees(root_T1, root_T2);
}


int
check_subtree_2(struct Node* root_T1, struct Node* root_T2)
{
	// The empty tree is always a subtree
	if (root_T2 == NULL)
		return 1;

	return subtree(root_T1, root_T2);
}


struct Node*
random_node(struct Node* root)
{
	if (root == NULL)
		return NULL;

	srand(time(NULL));
	int i = rand() % root->size;

	return get_ith_node(root, i);
}


/* Time  Complexity: O(n *logn) in a balanced tree
   Time  Complexity: O(n^2) in an unbalanced tree
*/
/* Space Complexity: O(logn) in a balanced tree
   Space Complexity: O(n) in an unbalanced tree
*/
int
paths_with_sum(struct Node* root, int target)
{
	if (root == NULL)
		return 0;

	int total = 0;
	int sum   = 0;

	preorder_count_paths(root, &total, target);
	// count_paths(root, &sum, &total, target);

	return total;
}
