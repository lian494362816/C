#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0; 

    for (i = 0; i < 10; i++)
    {
        switch(i)
        {
            case 1 ... 3:
                printf("i:%d \n", i);
                break;

            case 7 ... 9:
                printf("i:%d \n", i);
                break;

            fsdkfj:
                break;
            
            default:
                printf("default \n");
                break;
        }
    }
           
    return 0;
}
