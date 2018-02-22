#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_stack.h"


//Date:2017.2.19
//Program:static stack

int main(int argc, char *argv[])
{
	S32 i = 0;
	STACK_TYPE tmp;

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
	
	return MY_SUCCESS;
}
