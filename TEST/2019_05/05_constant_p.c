#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 10; 

    if (__builtin_constant_p(i))
        printf("i is a constant\n");
    else
        printf("i is not constant\n");


    if (__builtin_constant_p(10))
        printf("10 is a constant\n");
    else
        printf("10 is not constant\n");

    return 0;
}
