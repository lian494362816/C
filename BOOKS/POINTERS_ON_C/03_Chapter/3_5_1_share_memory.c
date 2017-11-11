#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	{
		int a = 10;
		int b = 20;
		printf("a = %d, %p\n", a, &a);
		printf("b = %d, %p\n", b, &b);
	}

	printf("==========================\n");

	{
		int a = 30;
		printf("a = %d, %p\n", a, &a);
	}
	return 0;
}
