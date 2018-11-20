#include <stdio.h>

int main(int argc, char *argv)
{
    int a[10] = {0}; 
    int *p1 = a;
    int *p2 = a;
    p2++;

    printf("%d\n", p2 - p1);

    return 0;
}
