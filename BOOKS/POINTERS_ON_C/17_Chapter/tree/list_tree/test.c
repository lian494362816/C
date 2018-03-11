#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_queue.h"
#include "my_tree.h"


//Date:2018.2.22
//Program:static tree test


#define MAX 7

static TREE_TYPE _gTree[MAX] = {30, 20, 40, 10, 21, 32, 42};

static void test_callback(TREE_TYPE Value)
{
	printf("Value = %d\n", Value);
}

int main(int argc, char *argv[])
{
	S32 i = 0;
	TreeNode_t *pstNode = NULL;

	for (i = 0; i < MAX; i++)
	{
		my_tree_insert(_gTree[i]);
	}

	for (i = 0; i < MAX; i++)
	{
		pstNode = my_tree_find(_gTree[i]);

		if (NULL != pstNode)
		{
			printf("%d\n", pstNode->Value);
		}
	}

	printf("=============\n");

	my_tree_pre_order_traverse(test_callback);

	return MY_SUCCESS;
}
