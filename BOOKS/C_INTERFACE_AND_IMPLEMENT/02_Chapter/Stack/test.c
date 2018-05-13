#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_queue.h"
#include "my_stack.h"


//Date:2018 3 25
//Program: ADT Stack test



//T Stack_New(void);
//S32 Stack_Empty(T Stk);
//S32 Stack_Push(T Stk, void *Data);
//void * Stack_Pop(T Stk);
//S32 Stack_Free(T *Stk);


int main(int argc, char *argv[])
{
	Stack_T pstStack = NULL;
	S32 s32i = 0;
	S32 *ps32Tmp = NULL;

	pstStack = Stack_New();
	CHECK_POINTER(pstStack);

	for (s32i = 0; s32i < 10; s32i++)
	{
		Stack_Push(pstStack, &s32i);
	}

	Stack_Print(pstStack);

	for (s32i = 0; s32i < 10; s32i++)
	{
		ps32Tmp = Stack_Pop(pstStack);//return null
		printf("%p\n", ps32Tmp);
	}

	Stack_Free(&pstStack);

	return MY_SUCCESS;
}
