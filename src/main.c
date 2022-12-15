#include <time.h>
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
	printf("\t=================================\n");
	printf("\t======= COMMON ANCESTOR 2 =======\n");
	printf("\t=================================\n\n");

	// ==========================================
	// ================= TEST 0 =================
	// ==========================================

	struct Node* p = find_ret(root, 2);
	struct Node* q = find_ret(root, 14);

	/* Solution */
	struct Node* ancestor = common_ancestor_2(root, p, q);

	printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 1 =================
	// ==========================================

	// struct Node* p = find_ret(root, 28);
	// struct Node* q = find_ret(root, 13);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 2 =================
	// ==========================================

	// struct Node* p = find_ret(root, 9);
	// struct Node* q = find_ret(root, 14);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 3 =================
	// ==========================================

	// struct Node* p = find_ret(root, 3);
	// struct Node* q = find_ret(root, 7);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 4 =================
	// ==========================================

	// struct Node* p = find_ret(root, 0);
	// struct Node* q = find_ret(root, 28);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 5 =================
	// ==========================================

	// struct Node* p = find_ret(root, 7);
	// struct Node* q = find_ret(root, 10);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 6 =================
	// ==========================================

	// struct Node* p = find_ret(root, 18);
	// struct Node* q = find_ret(root, 28);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 7 =================
	// ==========================================

	// struct Node* p = find_ret(root, 11);
	// struct Node* q = find_ret(root, 1);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);



	// ==========================================
	// ================= TEST 8 =================
	// ==========================================

	// struct Node* p = find_ret(root, 13);
	// struct Node* q = find_ret(root, 28);

	// /* Solution */
	// struct Node* ancestor = common_ancestor_2(root, p, q);

	// printf("\n\t[%d & %d] => Common Ancestor: %d\n\n", p->data, q->data, ancestor->data);





	return 0;
}
