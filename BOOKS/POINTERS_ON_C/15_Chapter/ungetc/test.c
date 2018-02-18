#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"


//Date 2018.2.18
//Program ungetc function test

int main(int argc, char *argv[])
{
	
	char ch;

	while( (ch = getchar()) != EOF  && isdigit(ch) )
	{
		putchar(ch);
	}

	ungetc(ch, stdin);

	return 0;
}
