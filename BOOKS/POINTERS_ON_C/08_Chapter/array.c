#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>

#define MAX 1000000

int main(int argc, char *argv[])
{
	int array[MAX];
	int i;

	for (i = 0; i < MAX; i++)
	{
		array[i] = 0;
	}

	return 0;
}
