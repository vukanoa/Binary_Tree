#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tree.h"

#define EMPTY_STACK -1
#define HEIGHT 4
#define POSITION_BEFORE_QUEUE -1
#define LAST_LEVEL_SPACES 3

int height_tree = -1;

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
			printf("\n\tNode %d does exist in the Tree!\n\n", data);
			return;
		}

		if (data < root->data)
			root = root->left;
		else
			root = root->right;
	}

	printf("\n\tNode %d does NOT exist in the Tree!\n\n", data);
}


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
	struct Node** stack = malloc(sizeof(struct Node*) * HEIGHT);

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
	
	int sp_1 = EMPTY_STACK;
	int sp_2 = EMPTY_STACK;
	struct Node** stack_1 = malloc(sizeof(struct Node*) * pow(2, HEIGHT));
	struct Node** stack_2 = malloc(sizeof(struct Node*) * pow(2, HEIGHT));

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
	
	int front = POSITION_BEFORE_QUEUE;
	int rear  = POSITION_BEFORE_QUEUE;

	// This was the error. Glibc doesn't recognize 'pow' for some reason.
	// Plus I allocated less space than I used so I added mod with 'queue_size'

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


int
height_of_tree()
{
	return height_tree;
}

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


int
check_balanced_improved(struct Node* root) // O(N) time, O(H) space[H => height_tree]
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
random_node(struct Node* root)
{
	if (root == NULL)
		return NULL;
	
	srand(time(NULL));
	int i = rand() % root->size;

	return get_ith_node(root, i);
}
