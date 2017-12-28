#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

//2018.2.4
//测试位端

typedef struct field_s{
	unsigned int onebit : 1;
	unsigned int twobit : 2;
	unsigned int threebit : 3;
}field_t;

int char_prt_by_bit(unsigned char c)
{
	int i = 0;	

	for (i = 0; i < 8; i++)
	{
		printf("%d", (c & 0x80) ? 1: 0);
		c <<= 1;
	}
	
	return 0;
}

int main(int argc, char *argv[])
{
	field_t field;			
	int i = 0;
	int j = 0;
	unsigned char *pChar = NULL;

	memset(&field, 0, sizeof(field_t));

	field.onebit = 0x1;
	field.twobit = 0x3;
	field.threebit = 0x2;

	printf("onebit = %d\n", field.onebit);
	printf("twobit = %d\n", field.twobit);
	printf("threebit = %d\n", field.threebit);

	pChar = (unsigned char *)&field;

	printf("szieof(field_t) = %ld\n", sizeof(field_t));

	pChar += sizeof(field_t) - 1;

	for (i = sizeof(field_t) - 1; i >= 0; i--)
	{
		//for (j = 7; j >= 0; j--)
		//{
		//	printf("%d", *pChar & (0x1 << j));
		//}
		char_prt_by_bit(*pChar);
		printf(" ");
		pChar --;
	}

	printf("\n");


	return 0;
}
