#include "my_error.h"
#include "my_type.h"
#include "my_tree.h"
#include "my_func.h"

static TreeNode_t    *_gpstTreeNode = NULL;

S32 my_tree_insert(TREE_TYPE Value)
{
	TreeNode_t  *pstNewNode = NULL;
	TreeNode_t  **pstLink = NULL;

	pstLink = &_gpstTreeNode;

	while( (pstNewNode = *pstLink) != NULL)
	{
		if (Value < pstNewNode->Value)
		{
			pstLink = &pstNewNode->left;
		}
		else
		{
			pstLink = &pstNewNode->right;
		}
	}

	pstNewNode = MALLOC(1, TreeNode_t);
	if (NULL == pstNewNode)
	{
		MY_ERROR("malloc failed\n");
		return MY_FAIL;
	}

	pstNewNode->Value = Value;
	pstNewNode->left = NULL;
	pstNewNode->right = NULL;

	*pstLink = pstNewNode;

	return MY_SUCCESS;
}

TreeNode_t * my_tree_find(TREE_TYPE Value)
{
	TreeNode_t *pstCurrent = _gpstTreeNode;

	while (pstCurrent != NULL && pstCurrent->Value != Value)
	{
		if (Value < pstCurrent->Value)
		{
			pstCurrent = pstCurrent->left;
		}
		else
		{
			pstCurrent = pstCurrent->right;
		}
	}

	if (NULL != pstCurrent)
	{
		return pstCurrent;
	}
	else
	{
		MY_INFO("Not find \n");
		return NULL;
	}
}

static void _do_my_tree_pre_order_traverse(TreeNode_t *pstCurrent, void (*callback)(TREE_TYPE Value))
{
	if (pstCurrent != NULL)
	{
		callback(pstCurrent->Value);
		_do_my_tree_pre_order_traverse(pstCurrent->left, callback);
		_do_my_tree_pre_order_traverse(pstCurrent->right, callback);
	}
}

S32 my_tree_pre_order_traverse(void (*callback)(TREE_TYPE Value))
{
	_do_my_tree_pre_order_traverse(_gpstTreeNode, callback);	

	return MY_SUCCESS;
}
