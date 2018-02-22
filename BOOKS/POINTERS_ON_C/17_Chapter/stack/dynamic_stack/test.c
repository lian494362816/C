#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_stack.h"


//Date:2017.2.20
//Program:dynamic stack test

#define STACK_MAX 100


int main(int argc, char *argv[])
{
	S32 i = 0;
	STACK_TYPE tmp;

	stack_create(STACK_MAX);

	for (i = 0; i < STACK_MAX; i++)
	{
		stack_push(i);
	}

	for (i = 0; i < STACK_MAX; i++)
	{
		tmp = stack_pop();
		printf("%-4d ", tmp);
		if ( 0 == (i % 10))
		{
			printf("\n");
		}
	}
	printf("\n");

//	printf("%d\n", stack_top());
	
	stack_destroy();

	return MY_SUCCESS;
}
