#include <stdio.h>

typedef int s8  __attribute__((mode(QI)));
typedef int s16 __attribute__((mode(HI)));
typedef int s32 __attribute__((mode(SI)));
typedef int s64 __attribute__((mode(DI)));

typedef unsigned int u8  __attribute__((mode(QI)));
typedef unsigned int u16 __attribute__((mode(HI)));
typedef unsigned int u32 __attribute__((mode(SI)));
typedef unsigned int u64 __attribute__((mode(DI)));

int main(int argc, char *argv[])
{
    printf("s8 :%ld \n", sizeof(s8)); 
    printf("s16:%ld \n", sizeof(s16)); 
    printf("s32:%ld \n", sizeof(s32)); 
    printf("s64:%ld \n", sizeof(s64)); 

    printf("================= \n");

    printf("u8 :%ld \n", sizeof(u8)); 
    printf("u16:%ld \n", sizeof(u16)); 
    printf("u32:%ld \n", sizeof(u32)); 
    printf("u64:%ld \n", sizeof(u64)); 

    return 0;
}
