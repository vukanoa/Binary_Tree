#include <stdlib.h>
#include <math.h>
#include "tree.h"
#define EMPTY_STACK -1
#define HEIGHT 4
#define POSITION_BEFORE_QUEUE -1
#define LAST_LEVEL_SPACES 3

int height_tree;

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
		(*root) = tmp;
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
	
	printf("%d ", root->data);

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
del_node(struct Node** root, int data)
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
del_node_recursively(struct Node* root, int data)
{
	if (root == NULL)
		return NULL;
	else if (data < root->data)
		root->left = del_node_recursively(root->left, data);
	else if (data > root->data)
		root->right = del_node_recursively(root->right, data);
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
			root->right = del_node_recursively(root->right, tmp->data);
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
