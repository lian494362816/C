#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_queue.h"
#include "my_tree.h"
#include "my_adt_stack.h"


//Date:2018.3.11
//Program:use macro implement stack


#define INT_MAX 10
#define FLOAT_MAX 5

STACK_CREATE(int, _int, INT_MAX);
STACK_CREATE(float, _float, FLOAT_MAX);

int main(int argc, char *argv[])
{
	int i = 0;
	int IntTmp = 0;
	float FloatTmp = 0.0;

	for (i = 0; i < INT_MAX; i++)
	{
		push_int(i);
	}

	for (i = 0; i < FLOAT_MAX; i++)
	{
		push_float((float) i);
	}

	for (i = 0; i < INT_MAX; i++)
	{
		IntTmp = pop_int();	
		printf("[%d]:%d\n", i, IntTmp);
	}
	printf("================\n");
	for (i = 0; i < FLOAT_MAX; i++)
	{
		FloatTmp = pop_float();
		printf("[%d]:%f\n", i, FloatTmp);
	}


	return MY_SUCCESS;
}
