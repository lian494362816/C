#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
 
int main(int argc, char *argv[])
{
	int pd[2];		
	int ret;
	char char_write = 'a';
	char char_read;

	ret = pipe(pd);
	if (0 != ret)
	{
		printf("pipe failed\n");
		return  -1;
	}

	write(pd[1], &char_write, sizeof(char));

	//read master after write, if not read will wait
	read(pd[0], &char_read, sizeof(char));
	printf("read = %c\n", char_read);

	return 0;
}
