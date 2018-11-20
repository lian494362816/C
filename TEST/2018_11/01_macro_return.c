#include <stdio.h>

#define EXEC(func, ret_val) ({\
        int _ret = 0;\
        _ret = func;\
        if (ret_val != _ret )\
        {\
            printf("%s\n", #func);\
            printf("fail:%d\n", _ret);\
            return _ret;\
        }\
    })
int hello1(int i)
{
    return 0;
}

int hello2(int i)
{
    return 1;
}

int main(int argc, char *argv)
{
    EXEC(hello1(10), 0);
    EXEC(hello2(20), 0);
    
    return 0;
}
