#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"


//Date 2018.2.18
//Program scanf arguments test

int main(int argc, char *argv[])
{
	S32 i = 100;
	S32 s32Ret = 0;

	//s32Ret = scanf("%o", &i);// 八进制
	//s32Ret = scanf("%d", &i);// 十进制
	s32Ret = scanf("%x", &i);// 十六进制

	if (s32Ret < 0)
	{
		MY_ERROR("scanf errror\n");
		return MY_FAIL;
	}
	printf("%d\n", i);

	return 0;
}
