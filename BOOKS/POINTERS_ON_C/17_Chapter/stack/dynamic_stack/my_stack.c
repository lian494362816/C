#include "my_stack.h"
#include "my_error.h"
#include "my_type.h"
#include "my_func.h"

static S32 _gStackElement = -1;
static U32 _gStackSize = 0;
static STACK_TYPE  *_gpStack = NULL;

S32 stack_create(U32 u32Size)
{
	if (0 == _gStackSize)
	{
		_gStackSize = u32Size;	
	}

	_gpStack = MALLOC(_gStackSize, STACK_TYPE);
	if (NULL == _gpStack)
	{
		MY_ERROR("malloc failed\n");
		return MY_FAIL;
	}

	return MY_SUCCESS;
}

S32 stack_destroy(void)
{
	if (0 != _gStackSize)
	{
		free(_gpStack);
		return MY_SUCCESS;
	}

	MY_INFO("free failed\n");
	return MY_FAIL;
}

static S32 stack_is_full(void)
{
	return _gStackElement == _gStackSize -1;	
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

	return _gpStack[_gStackElement--];
}

void stack_push(STACK_TYPE value)
{
	if (stack_is_full())
	{
		MY_ERROR("stack is full\n");
		return ;
	}

	_gStackElement ++;
	_gpStack[_gStackElement] = value;
}

STACK_TYPE stack_top(void)
{
	if (stack_is_empty())
	{
		MY_ERROR("stack is empty\n");
		return MY_FAIL;
	}

	return _gpStack[_gStackElement];
}
