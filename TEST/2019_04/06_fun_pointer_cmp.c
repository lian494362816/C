#include <stdio.h>

static int __def_hello(void)
{
    printf("__def_hello\n");
    return -1;
}

int hello_init(void) __attribute__((weak, alias("__def_hello")));

int main(int argc, char *argv[])
{
    if (__def_hello == hello_init)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    __def_hello();
    hello_init();
    
    return 0;
}
