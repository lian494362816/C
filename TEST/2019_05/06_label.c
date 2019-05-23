#include <stdio.h>

#define num(x) ({ \
    __label__ here;\
    if (x > 0) \
    {\
        printf("x:%d \n", x);\
    }\
    else\
    {\
        goto here;\
    }\
here:\
    printf("out \n"); \
})

int main(int argc, char *argv[])
{
    num(1); 
    num(-1);

    return 0;
}
