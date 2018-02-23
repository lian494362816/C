#include "my_error.h"
#include "my_type.h"
#include "my_tree.h"
#include "my_func.h"

//N 从1开始
//节点N的双亲为N/2
//节点N的左孩子为2N
//节点N的右孩子为2N + 1

#define TREE_MAX (100 + 1)

static TREE_TYPE _gaTree[TREE_MAX];

static S32 my_tree_child_left(S32 s32Value)
{
	return 2 * s32Value;
}

static S32 my_tree_child_right(S32 s32Value)
{
	return 2 * s32Value + 1;
}

S32 my_tree_insert(TREE_TYPE Value)
{
	S32 s32Current = 1;	

	if (0 == Value)
	{
		MY_ERROR("Value is not legal\n");
		return MY_FAIL;
	}

	while(_gaTree[s32Current] != 0)
	{
		if (Value < _gaTree[s32Current])
		{
			s32Current = my_tree_child_left(s32Current);
		}
		else
		{
			s32Current = my_tree_child_right(s32Current);	
		}
	}

	if (s32Current >= TREE_MAX)
	{
		MY_ERROR("Out of range\n");
		return MY_FAIL;
	}

	_gaTree[s32Current] = Value;

	return MY_SUCCESS;
}

S32 my_tree_find(TREE_TYPE Value)
{
	S32 s32Current = 1;	

	while(_gaTree[s32Current] != Value && s32Current < TREE_MAX)
	{
		if (Value < _gaTree[s32Current])
		{
			s32Current = my_tree_child_left(s32Current);
		}
		else
		{
			s32Current = my_tree_child_right(s32Current);	
		}
	}

	if (s32Current >= TREE_MAX)
	{
		MY_ERROR("Out of range\n");
		return MY_FAIL;
	}

	return s32Current;
}

static void _do_my_tree_pre_order_traverse(S32 s32Current, void (*callback)(TREE_TYPE Value))
{
	if (s32Current < TREE_MAX && _gaTree[s32Current] != 0)
	{
		callback(_gaTree[s32Current]);

		_do_my_tree_pre_order_traverse(my_tree_child_left(s32Current), callback);
		_do_my_tree_pre_order_traverse(my_tree_child_right(s32Current), callback);
	}
}

S32 my_tree_pre_order_traverse(void (*callback)(TREE_TYPE Value))
{
	_do_my_tree_pre_order_traverse(1, callback);
	
	return MY_SUCCESS;
}
