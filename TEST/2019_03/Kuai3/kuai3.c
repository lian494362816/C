#include <stdio.h>
#include <string.h>

#define MAX_SIZE (1024)

int main(int argc, char *argv[])
{
    FILE *input = NULL;
    int i = 0;
    unsigned char tmp[1024] = {0};
    char *pos = NULL;
    int line = 0;

    if (argc < 2)
    {
        printf("not input file \n");
        return -1;
    }

    input = fopen(argv[1], "r+");
    if (!input)
    {
        printf("open %s fail \n", argv[1]);
        return -1;
    }

    /* 计算行号 */
    while(!feof(input))
    {
        fgets(tmp, MAX_SIZE, input);
        line ++;
    }
    --line;
    //printf("line:%d \n", line);
    fseek(input, 0, SEEK_SET);

    while(line-- > 0)
    {
        fgets(tmp, MAX_SIZE, input);

        //去掉字符串“追号XX期 中出”
        if (pos = strstr(tmp, "追"))
        {
            *pos = '\n';
            pos ++;
            *pos = '\0';
        }
        //去掉字符串“当期中出！！”
        if (pos = strstr(tmp, "当"))
        {
            *pos = '\n';
            pos ++;
            *pos = '\0';
        }

        /*
        1.去掉字符串中第1"," 改为空格
        2.在推测和结果中间添加";"来分割
        */
        if (pos = strstr(tmp, ","))
        {
            *pos = ' ';
            pos -= 2;
            *pos = ';';
        }

        /*
        去掉字符串中第2"," 改为空格
        */
        if (pos = strstr(tmp, ","))
        {
            *pos = ' ';
        }

       //跳过日期
        pos = strstr(tmp, " ");

        printf("%s", pos);
        pos = NULL;
    }

    fclose(input);

    return 0;
}
