#include <stdio.h>

int main(int argc, char *argv[])
{
    int x = 10; 

#if 1
    while(x --> 0)
    {
        printf("x:%d\n", x);
    }

#else
    for (x-=1; x >= 0; x --)
    {
        printf("x:%d\n", x);
    }

#endif
    return 0;
}
