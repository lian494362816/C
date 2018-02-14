#include <string.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"

//Date 2018.2.14
//Program macro test

int main(int argc, char *argv[])
{
	my_list_t *pList = NULL;

	pList = MALLOC(1, my_list_t);

	pList->s32Value = 10;

	printf("%d\n", pList->s32Value);

	CHECK_POINTER(pList);
//	CHECK_POINTER(NULL);

	printf("file:%s\n", __FILE__);
	printf("line:%d\n", __LINE__);
	printf("date:%s\n", __DATE__);//build date
	printf("time:%s\n", __TIME__);//build time
	printf("ansi:%d\n", __STDC__);//1 follow ANSI C, 0 don't follow ANSI C

	return 0;
}
