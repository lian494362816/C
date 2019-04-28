#include <stdio.h>

struct test_t{
    char c;
    short s;
    int i;
}__attribute__((packed));

int main(int argc, char *argv[])
{
    printf("sizeof:%ld \n", sizeof(struct test_t));
    return 0;
}
