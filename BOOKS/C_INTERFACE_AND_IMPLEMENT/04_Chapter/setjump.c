#include <stdio.h>
#include <setjmp.h>

jmp_buf Test_FailFunc;
static int Test_Handle = 1;


/*程序执行流程
 * hello() -> longjmp->setjmp->hello
 *
 * 1, 第一次会直接跳过 setjmp(Test_FailFunc), 打印111, 222
 * 2, 进入hello(),打印333
 * 3, Test_Hanlde = 1, 执行longjmp(Test_FailFunc,1), 这里的1代表setjmp返回值是1，跳到 setjmp(Test_FailFunc)), 打印444, 222
 * 4, 再进入hello(), 打印3333
 * 5, Test_handle = 0, 完成hello, 打印555
 */

static void hello(void)
{
	printf("333\n");

	if (Test_Handle)
	{
		Test_Handle = 0;
		longjmp(Test_FailFunc, 1);
	}
	
}

int main(int argc, char *argv)
{
	/* Test_Handle = 1; */
	printf("111\n");
	if (setjmp(Test_FailFunc))
	{
		printf("444\n");
	}

	printf("222\n");
	hello();
	printf("555\n");
		
	return 0;
}
