#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_error.h"
#include "my_func.h"
#include "my_queue.h"
#include "my_type.h"
#include "my_stack.h"

#define T Stack_T
#define STACK_CHECK_ID 0xff


struct Stack_T{
	S32 s32Count;
	S32 s32Id;//check the Stack is crate by Stack_New func
	struct elem{
		void *pData;
		struct elem *pLink;
	}*head;
};

static S32 Stack_Check(T stStack)
{
	CHECK_POINTER(stStack);

	if (STACK_CHECK_ID != stStack->s32Id)
	{
		MY_ERROR("The Stack is not create by Stack_New\n");
		return MY_FAIL;
	}
	
	return MY_SUCCESS;
}

T Stack_New(void)
{
	T stStack;

	stStack = MALLOC(1, T);
	CHECK_POINTER(stStack);

	stStack->s32Count = 0;
	stStack->s32Id = STACK_CHECK_ID; //for check
	stStack->head = NULL;

	return stStack;
}

S32 Stack_Empty(T stStack)
{
	S32 s32Ret = MY_SUCCESS;

	CHECK_POINTER(stStack);

	s32Ret = Stack_Check(stStack);
	if (MY_SUCCESS != s32Ret)
	{
		return s32Ret;
	}

	return 0 == stStack->s32Count;
}

S32 Stack_Push(T stStack, void *pData)
{
	struct elem *pstNew = NULL;
	S32 s32Ret = MY_SUCCESS;

	CHECK_POINTER(stStack);

	s32Ret = Stack_Check(stStack);
	if (MY_SUCCESS != s32Ret)
	{
		return s32Ret;
	}

	pstNew = MALLOC(1, struct elem);
	CHECK_POINTER(pstNew);

	pstNew->pLink = stStack->head;
	pstNew->pData = pData;
	stStack->head = pstNew;
	stStack->s32Count++;

	return MY_SUCCESS;
}

S32 Stack_Print(T stStack)
{
	S32 s32Ret= MY_SUCCESS;
	struct elem *pstTmp1;
	struct elem *pstTmp2;
	
	CHECK_POINTER(stStack);

	s32Ret = Stack_Check(stStack);
	if (MY_SUCCESS != s32Ret)
	{
		return s32Ret;
	}

	for (pstTmp1 = stStack->head; pstTmp1; pstTmp1 = pstTmp2)
	{
		pstTmp2 = pstTmp1->pLink;
		printf("%d\n", *(int *)(pstTmp1->pData));
	}

	return s32Ret;
}

void * Stack_Pop(T stStack)
{
	struct elem *pstOld = NULL;
	S32 s32Ret = MY_SUCCESS;
	//void *pData = NULL;

	CHECK_POINTER(stStack);

	s32Ret = Stack_Check(stStack);
	if (MY_SUCCESS != s32Ret)
	{
		return NULL;
	}

	if (stStack->s32Count <= 0)
	{
		MY_ERROR("Statck is empty\n");
		return NULL;
	}

	pstOld = stStack->head;
	//pData = pstOld->pData;
	stStack->head = pstOld->pLink;
	stStack->s32Count --;
	FREE(pstOld);	

	//return pData;
	return NULL;
}

S32 Stack_Free(T *pstStack)
{
	struct elem *pstTmp1 = NULL;
	struct elem *pstTmp2 = NULL;
	S32 s32Ret = MY_SUCCESS;

	CHECK_POINTER(pstStack);
	CHECK_POINTER(*pstStack);

	s32Ret = Stack_Check(*pstStack);
	if (MY_SUCCESS != s32Ret)
	{
		return MY_FAIL;
	}

	for (pstTmp1 = (*pstStack)->head; pstTmp1; pstTmp1 = pstTmp2)
	{
		pstTmp2 = pstTmp1->pLink;
		FREE(pstTmp1);
	}

	FREE(pstStack);

	return s32Ret;
}

#undef T
