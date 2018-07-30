#include <stdio.h>

//program:测试bbs 段占用的代码的空间
//date:2018.06.02

//bbs 指的是未初始化和初始化为0的全局或静态变量, 
//只是记录一下数据的大小，因此不会占用程序空间


int array[1024 * 1024] = {0};

int main(int argc, char *argv[])
{
	return 0;
}
