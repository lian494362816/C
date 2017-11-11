#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void signal_func(int sig)
{
	printf("signal is trigger\n");
}

int main(int argc, char *argv[])
{
	signal(SIGINT, signal_func);	

	while('q'!= getchar())
	{
		sleep(1);
	}

	return 0;
}
