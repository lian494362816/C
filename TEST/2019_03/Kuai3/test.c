#include <stdio.h>
#include "array.h"
#define BIG (1)
#define SMALL (-1)
#define NONE 0

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int max = 0;
    int result = 0;
    int forecast = 0;
    int yes_count = 0;
    int no_count = 0;
    int none_count = 0;

    max = sizeof(a)/sizeof(a[10]);
    printf("max:%d \n", max);

    for (i = 0; i < max;)
    {
        //计算预测值的大小
        j = 0;
        while(a[i][j] != 0)
        {
            if (a[i][j] > 10)
            {
                forecast += BIG;
            }
            else
            {
                forecast += SMALL;
            }
            j++;
        }

        //计算结果
        i++;
        j = 0;
        result = 0;
        while(a[i][j] != 0)
        {
            result += a[i][j];
            j++;
        }

        if (forecast > 0)
        {
            printf("big, result:%d ", result);
            if (result > 10)
            {
                printf("Yes \n");
                yes_count ++;
            }
            else
            {
                printf("No \n");
                no_count ++;
            }
        }
        else if (forecast < 0)
        {
            printf("small: result:%d ", result);
            if (result <= 10)
            {
                printf("Yes \n");
                yes_count ++;
            }
            else
            {
                printf("No \n");
                no_count ++;
            }
        }
        else
        {
            printf("None: result:%d \n", result);
            none_count ++;
        }

        i++;
        forecast = NONE;
    }

    printf("Yes:%d, No:%d, None:%d \n", yes_count, no_count, none_count);

    return 0;
}
