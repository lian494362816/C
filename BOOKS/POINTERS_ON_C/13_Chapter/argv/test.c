#include <string.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"

//Date 2018.2.14
//Program main argv test

#if 0
int main(int argc, char *argv[])
{
	while(NULL != *++argv)
	{
		printf("%s\n", *argv);
	}

	return 0;
}
#else
int main(int argc, char *argv[])
{
	while('\0' != *++*argv)
	{
		printf("%c ", **argv);
	}
	return 0;
}





#endif

