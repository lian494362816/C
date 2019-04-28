#include <stdio.h>



int my_printf1(const char *format, ...) __attribute__((format(printf, 1, 2)));
int my_printf2(int num1, const char *format, ...) __attribute__((format(printf, 2, 3)));
int my_printf3(int num1, int num2, const char *format, ...) __attribute__((format(printf, 3, 4)));

int my_printf(int level, const char *format, ...) __attribute__((format(printf, 2, 3)));

int my_printf(int level, const char *format, ...)
{
    
    return 0;
}




int main(int argc, char *argv[])
{
    
    return 0;
}
