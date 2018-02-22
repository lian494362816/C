#ifndef __MY_STACK_H_

#include <stdio.h>
#include "my_type.h"

#define STACK_TYPE int

S32 stack_create(U32 u32Size);
S32 stack_destroy(void);

void stack_push(STACK_TYPE value);
STACK_TYPE stack_pop(void);
STACK_TYPE stack_top(void);

#endif //__MY_STACK_H_
