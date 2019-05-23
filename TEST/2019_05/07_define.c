#include <stdio.h>

#define debug1(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define debug2(fmt, args...) printf(fmt, ##args)

int main(int argc, char *argv[])
{
    debug1("hello \n"); 
    debug1("hello %s\n", "word"); 

    debug2("hello \n"); 
    debug2("hello %s\n", "word"); 

    if (1)
    //hello
    printf("123 \n");

    return 0;
}
