#include <stdio.h>

// 模拟uboot的go 命令
// uboot的go命令就是定义一个函数指针,给函数指针赋值，最后调用这这个函数指针

int do_main(int (*entry)(int, char *[]), int argc, char *argv[])
{
    return entry(argc, argv);
}

int hello(void)
{
    printf("hello \n");
}

int main(int argc, char *argv[])
{
    void *p = hello; 

    do_main(p, 0, NULL);

    return 0;
}
