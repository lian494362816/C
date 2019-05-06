#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void  __attribute__((noreturn)) b(void)
{
    exit(1);
}

/* int a(int num) */
int a(int num) 
{
    printf("fun in \n");
    if (num < 0)
        b();
    else
        return num * 10;
}

int main(int argc, char *argv[])
{
    a(10); 
    printf("func out \n");

    a(-10);
    printf("func out \n");

    return 0;
}
