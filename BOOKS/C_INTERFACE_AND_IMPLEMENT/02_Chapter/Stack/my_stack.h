#ifndef __MY_STACK_H
#define __MY_STACK_H

#include "my_type.h"

#define T Stack_T
typedef struct T *T;

T Stack_New(void);
S32 Stack_Empty(T Stk);
S32 Stack_Push(T Stk, void *Data);
void * Stack_Pop(T Stk);
S32 Stack_Free(T *Stk);
S32 Stack_Print(T stStack);


#undef T

#endif //__MY_STACK_H
