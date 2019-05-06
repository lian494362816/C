#include <stdio.h>

__attribute__((constructor)) void main_before(void)
{
    printf("%s \n", __FUNCTION__);
}

__attribute__((destructor)) void main_after(void)
{
    printf("%s \n", __FUNCTION__);
}


int main(int argc, char *argv[])
{
    printf("main hello \n"); 
    return 0;
}
