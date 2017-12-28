#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>

#define MAX 1000000

int main(int argc, char *argv[])
{
	int array[MAX];
	int *p = NULL;

	for (p = array; p < array + MAX; p++)
	{
		*p = 0;	
	}
		
	return 0;
}
