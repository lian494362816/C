#include "my_stack.h"
#include "my_error.h"
#include "my_type.h"

static STACK_TYPE *_gpStack = NULL;
static U32		  _gStackSize = 0;
static S32		  _gStack  

S32 stack_create(U32 u32Size);
S32 stack_destroy(void);

static S32 stack_is_full(void)
{
	return _gStackElement == STACK_MAX -1;	
}

static S32 stack_is_empty(void)
{
	return _gStackElement == -1;
}

STACK_TYPE stack_pop(void)
{
	if (stack_is_empty())
	{
		MY_ERROR("stack is empty\n");
		return MY_FAIL;
	}

	return _gStack[_gStackElement--];
}

void stack_push(STACK_TYPE value)
{
	if (stack_is_full())
	{
		MY_ERROR("stack is full\n");
		return ;
	}

	_gStackElement ++;
	_gStack[_gStackElement] = value;
}

STACK_TYPE stack_top(void)
{
	if (stack_is_empty())
	{
		MY_ERROR("stack is empty\n");
		return MY_FAIL;
	}

	return _gStack[_gStackElement];
}
