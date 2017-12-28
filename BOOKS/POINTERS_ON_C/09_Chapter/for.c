#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	j ++;
	printf("j = %d\n", j);

	return 0;
}
