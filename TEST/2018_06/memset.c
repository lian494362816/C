#include <stdio.h>

void * my_memset(void * s,int c,size_t count)
{
	unsigned long *sl = (unsigned long *) s;
	unsigned long cl = 0;
	char *s8;
	int i;

	printf("count:%d\n", count);
	printf("unsigned long:%ld\n", (unsigned long) s);
	printf("sizeof(*sl):%ld\n", sizeof(*sl) - 1);


	if ( ((unsigned long)s & (sizeof(*sl) - 1)) == 0) 
	{
		printf("is 0\n");
	}
	else
	{
		printf("is not 0\n");
	}

	//这里可以确定是32位系统还是64位系统
	/* do it one word at a time (32 bits or 64 bits) while possible */
	if ( ((unsigned long)s & (sizeof(*sl) - 1)) == 0) {
		for (i = 0; i < sizeof(*sl); i++) {
			cl <<= 8;
			cl |= c & 0xff;
		}
		while (count >= sizeof(*sl)) {
			*sl++ = cl;
			count -= sizeof(*sl);
			printf("11\n");
		}
	}
	/* fill 8 bits at a time */
	s8 = (char *)sl;
	while (count--)
	{
		printf("22\n");
		*s8++ = c;
	}
	return s;
}


int main(int argc, char *argv)
{
	char array[10] = {1, 2, 3, 4};	
	int i = 0;	
	my_memset(array, 0, sizeof(array));

	for (i = 0; i < 10; i++)
	{
		printf("[%d]:%d\n", i+1, i);
	}

	return 0;
}


