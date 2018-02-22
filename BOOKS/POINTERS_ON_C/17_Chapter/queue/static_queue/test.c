#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_queue.h"


//Date:2018.2.20
//Program:static queue test

#define QUEUE_SIZE 100

int main(int argc, char *argv[])
{
	S32 i = 0;
	S32 tmp = 0;

	for (i = 0; i < QUEUE_SIZE; i++)
	{
		my_queue_insert(i);
	}

	for (i = 0; i < QUEUE_SIZE; i++)
	{
		tmp = my_queue_delete();
		printf("%d ", tmp);

		if (0 == (i % 10))
		{
			printf("\n");
		}
	}

	printf("\n");

	return MY_SUCCESS;
}
