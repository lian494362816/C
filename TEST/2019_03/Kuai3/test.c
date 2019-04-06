#include <stdio.h>
#include "array.h"
#include "combination.h"

#define SIGNAL (0)
#define BOTH (1)

#define BIG (1)
#define SMALL (-1)
#define NONE 0
#define MAX_ARRAY (42)
#define STRING_SIZE (30)

enum combination_e      {
    signal = 0,
    both = 1,
    big = 2,
    small = 3,
    end = 4,
};

static  char combination_str[][STRING_SIZE] = {
    [signal] = {"signal"},
    [both] = {"both"},
    [big] = {"big"},
    [small] = {"small"},
};

struct conbination_forecast {
    enum combination_e  comb1;
    enum combination_e  comb2;
    char *str1;
    char *str2;
};

struct conbination_forecast comb[16] = {0};
//add 10 * num
/* double price_array[10] = { 10.00, 30.00, 70.00, 150.00, 310.00, 630.00, 1270.00, 2550.00, 5110.00, 10230.00}; */

//add 20 * num
/* double price_array[10] = { 20.00, 60.00, 140.00, 300.00, 620.00, 1260.00, 2540.00, 5100.00, 10220.00, 20460.00}; */

//add 5 * num
/* double price_array[10] = { 5.00, 15.00, 35.00, 75.00, 155.00, 315.00, 635.00, 1275.00, 2555.00, 5115.00}; */

//add 2 * num
double price_array[10] = { 2.00, 6.00, 14.00, 30.00, 62.00, 126.00, 254.00, 510.00, 1022.00, 2046.00};

/* 计算预测值的大小 */
int cal_forecast_big_small(int input[][10], int array_num, int *output)
{
    int i = 0;
    int j = 0;
    //{4,6,11,8}， {2, 2, 3}
    for (i = 0; i < array_num;)
    {
        j = 0;
        while(input[i][j] != 0)
        {
            if (input[i][j] > 10)
            {
                *output += BIG;
            }
            else
            {
                *output += SMALL;
            }
            j++;
        }


        if (*output >= BIG)
        {
            *output = BIG;
        }
        else if (*output <= SMALL)
        {
            *output = SMALL;
        }
        else
        {
            *output = NONE;
        }
        i += 2;
        output ++;
    }
    return 0;
}

/* 计算实际结果*/
int cal_result(int input[][10], int array_num, int *output)
{
    int i = 0;
    int j = 0;

    //{4,6,11,8}， {2, 2, 3}
    for (i = 0; i < array_num;)
    {
        i ++;
        j = 0;
        while(a[i][j] != 0)
        {
            *output += a[i][j];
            j++;
        }
        output ++;
        i ++;
    }

    return 0;
}

/* 计算单双*/
int cla_signal_both(int *input, int array_num, int *output)
{
    int i = 0;

    for (i = 0; i < array_num; i++)
    {
        if (input[i] % 2)
        {
            output[i] = SIGNAL;
        }
        else
        {
            output[i] = BOTH;
        }
    }

    return 0;
}

/*  计算大小*/
int cal_big_small(int *input, int array_num, int *output)
{
    int i = 0;

    for (i = 0; i < array_num; i++)
    {
        if (input[i] > 10)
        {
            output[i] = BIG;
        }
        else
        {
            output[i] = SMALL;
        }
    }

    return 0;
}

int compare(int comb, int big_small, int signal_both)
{
    int ret  = 0;
    switch(comb)
    {
        case signal:
        //printf("signal:%d \n", signal_both);
        if (SIGNAL == signal_both)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
        break;

    case both:
        if (BOTH == signal_both)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
        break;

    case big:
        if (BIG == big_small)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }

        break;

    case small:
        if (SMALL == big_small)
        {
            ret = 1;
        }
        else
        {
            ret= 0;
        }

        break;

    default:
        printf("comb error:%d \b", comb);
        ret = -1;
        break;
    }

    return ret;
}

/*尝试 单 双 大 小 各种组合 */
int my_try(int *big_small, int *signal_both, int array_num, int *output)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp_yes = 0;
    int tmp_no = 0;

    int yes_continue = 0;
    int yes_continue_tmp = 0;
    int no_continue = 0;
    int no_continue_tmp = 0;

    int ret = 0;

    for (i = 0; i < end; i++)
    {
        for (j = 0; j < end; j++)
        {
            tmp_yes = 0;
            tmp_no = 0;

            yes_continue = 0;
            yes_continue_tmp = 0;
            no_continue = 0;
            no_continue_tmp = 0;

            comb[0].comb1 = i;
            comb[0].str1 = combination_str[i];

            comb[0].comb2 = j;
            comb[0].str2 = combination_str[j];

            /* printf("%-8s,%-8s ", comb[0].str1, comb[0].str2); */
            printf("\"%s\";\"%s\"; ", comb[0].str1, comb[0].str2);
            for (k = 0; k < array_num;)
            {
                //printf("k:%d ", k);
                ret = compare(comb[0].comb1, big_small[k], signal_both[k]);
                if (1 == ret )
                {
                    tmp_yes ++;
                    yes_continue_tmp ++;
                    if (no_continue_tmp > no_continue)
                    {
                        no_continue = no_continue_tmp;
                    }
                    no_continue_tmp = 0;
                }
                else if (0 == ret)
                {
                    tmp_no ++;
                    no_continue_tmp ++;
                    if (yes_continue_tmp > yes_continue)
                    {
                        yes_continue = yes_continue_tmp;
                    }
                    yes_continue_tmp = 0;
                }
                else
                {
                    return -1;
                }

                k++;
                if (k >= array_num)
                {
                    break;
                }
                //printf("k:%d ", k);
                ret = compare(comb[0].comb2, big_small[k], signal_both[k]);
                if (1 == ret )
                {
                    tmp_yes ++;
                    yes_continue_tmp ++;
                    if (no_continue_tmp > no_continue)
                    {
                        no_continue = no_continue_tmp;
                    }
                    no_continue_tmp = 0;
                }
                else if (0 == ret)
                {
                    tmp_no ++;
                    no_continue_tmp ++;
                    if (yes_continue_tmp > yes_continue)
                    {
                        yes_continue = yes_continue_tmp;
                    }
                    yes_continue_tmp = 0;
                }
                else
                {
                    return -1;
                }
                k++;
            }
            /* printf(";yes:%-2d, no:%-2d \n", tmp_yes, tmp_no); */
           printf("    yes;%-2d;yes_cntinue;%-2d;no;%-2d;no_continue;%2d \n", tmp_yes, yes_continue, tmp_no, no_continue);
        }
    }


    return 0;
}

int main(int argc, char *argv[])
{
    int max = 0;
    int i = 0;
    int forecast_big_small[MAX_ARRAY] = {0};
    int result[MAX_ARRAY] = {0};
    int signal_both[MAX_ARRAY] = {0};
    int big_small[MAX_ARRAY] = {0};

    int forecast_yes = 0;
    int forecast_no = 0;
    int forecast_none = 0;

    int big_cnt = 0;
    int small_cnt = 0;

    int both_cnt = 0;
    int signal_cnt = 0;

    max = sizeof(a)/sizeof(a[10]);

    printf("max:%d \n", max);

    cal_forecast_big_small(a, max, forecast_big_small);
    for (i = 0; i < max / 2; i++)
    {
        //printf("[%d]:%d\n ", i + 1, forecast_big_small[i]);
    }

    cal_result(a, max, result);
    for (i = 0; i < max / 2; i++)
    {
        //printf("[%d]:%d\n ", i + 1, result[i]);
    }

    cla_signal_both(result, max /2, signal_both);
    for (i = 0; i < max / 2; i++)
    {
        //printf("[%d]:%d\n ", i + 1, signal_both[i]);
    }

    cal_big_small(result, max /2, big_small);
    for (i = 0; i < max / 2; i++)
    {
        //printf("[%d]:%d\n ", i + 1, big_small[i]);
    }

    for (i = 0; i < max / 2; i++)
    {
        //printf("[%d] result:%d, signal_both:%d, big_small:%d \n", i, result[i], signal_both[i], big_small[i] );
    }

    for (i = 0; i < max / 2; i++)
    {
         /* 计算预测的准确性 */
        //printf("result:%d, big_small:%d, forecast_big_small:%d \n", result[i], big_small[i], forecast_big_small[i]);
        if (NONE == forecast_big_small[i])
        {
            forecast_none ++;
        }
        else if(big_small[i] == forecast_big_small[i])
        {
            forecast_yes ++;
        }
        else
        {
            forecast_no ++;
        }

        /* 计算单双的个数 */
        if (BOTH == signal_both[i])
        {
            both_cnt ++;
        }
        else
        {
            signal_cnt ++;
        }


        /* 计算大小的个数 */
       if (BIG == big_small[i])
       {
            big_cnt ++;
       }
       else
       {
            small_cnt ++;
       }
    }

    printf("Yes:%2d, No:%2d, None:%2d ", forecast_yes, forecast_no, forecast_none);
    printf(";Signal:%2d, Both:%2d ", signal_cnt, both_cnt);
    printf(";Big:%2d, Small:%2d ", big_cnt, small_cnt);

    printf("\n");

    my_try(big_small, signal_both, max / 2, NULL);

    return 0;

}
