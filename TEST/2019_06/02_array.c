#include <stdio.h>

#define MAX 10

int main(int argc, char *argv[])
{
    int a[MAX] = { [0 ... (MAX -1)] = 5};
    int i = 0;

    for (i = 0; i < MAX; i++)
    {
        printf("[%d]:%d \n", i, a[i]);
    }


    return 0;
}
