#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_queue.h"


//Date:2018.2.20
//Program:dynamic queue test

#define QUEUE_SIZE 100

int main(int argc, char *argv[])
{
	S32 i = 0;
	S32 tmp = 0;

	my_queue_create();

	for (i = 0; i < QUEUE_SIZE; i++)
	{
		my_queue_insert(i);
	}

	my_queue_destroy();

	my_queue_create();

	for (i = 0; i < QUEUE_SIZE; i++)
	{
		my_queue_insert(i);
	}

	// my_queue_test();

	for (i = 0; i < QUEUE_SIZE; i++)
	{
		tmp = my_queue_delete();
		printf("%-4d ", tmp);

		if (0 == ((i+1) % 10))
		{
			printf("\n");
		}
	}

	my_queue_test();

	printf("\n");

	return MY_SUCCESS;
}
