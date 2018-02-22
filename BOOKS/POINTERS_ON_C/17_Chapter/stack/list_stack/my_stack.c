#include "my_stack.h"
#include "my_error.h"
#include "my_type.h"
#include "my_func.h"


typedef struct StackNode_s{
STACK_TYPE   value;
struct StackNode_s *next;
}StackNode_t;

StackNode_t  *_gpstStackNode = NULL;

static S32 stack_is_empty(void)
{
	return NULL == _gpstStackNode;
}

STACK_TYPE stack_pop(void)
{
	S32 s32Value = 0;
	StackNode_t *pstFirstNode = NULL;

	if (stack_is_empty())
	{
		MY_ERROR("stack is empty\n");
		return MY_FAIL;
	}

	pstFirstNode = _gpstStackNode;
	s32Value = pstFirstNode->value;

	_gpstStackNode = pstFirstNode->next;

	return s32Value;
}

void stack_push(STACK_TYPE value)
{
	StackNode_t *pstNewNode = NULL;

	pstNewNode = MALLOC(1, StackNode_t);
	if (NULL == pstNewNode)
	{
		MY_ERROR("malloc failed\n");
	}

	pstNewNode->next = _gpstStackNode;
	pstNewNode->value = value;

	_gpstStackNode = pstNewNode;
}

STACK_TYPE stack_top(void)
{
	if (stack_is_empty())
	{
		MY_ERROR("stack is empty\n");
		return MY_FAIL;
	}

	return _gpstStackNode->value;
}

S32 stack_create(U32 u32Size)
{
	return MY_SUCCESS;
}

S32 stack_destroy(void)
{
	while(!stack_is_empty())
	{
		stack_pop();
	}

	return MY_SUCCESS;
}


