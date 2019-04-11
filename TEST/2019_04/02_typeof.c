#include <stdio.h>

#define my_max(x,y) ((x)>(y)?(x):(y))

#define kernel_max(x,y) ({\
    typeof(x) _x = (x);\
    typeof(y) _y = (y);\
    (void )(&_x == &_y);\
    _x>_y ? _x:_y;\
})

int main(int argc, char *argv[])
{
    int i = 5;
    int j = 10;
    char c = 3;

#if 0
    i = 5;
    j = 10;
    printf("my_max:%d \n",my_max(i++, j++));
    
    i = 5;
    j = 10;
    printf("kernel_max:%d \n",kernel_max(i++, j++));
#else
    c = 3;
    j = 10;
    printf("my_max:%d \n",my_max(c, j));
    
    c = c;
    j = 10;
    printf("kernel_max:%d \n",kernel_max(c, j));
#endif

    return 0;
}
