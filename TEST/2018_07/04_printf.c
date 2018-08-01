#include <stdio.h>
//#include <stdarg.h>

typedef char *  va_list;
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)&v + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
//#define va_arg(ap,t)    (ap = ap + _INTSIZEOF(t), *(t *)(ap - _INTSIZEOF(t)))
//#define va_arg(ap,t)    (*(t *)(ap = ap + _INTSIZEOF(t), ap - _INTSIZEOF(t)))
#define va_end(ap)      ( ap = (va_list)0 )	

struct person{
	char *name;
	int age;
	char score;
	int id;
};

//use va_list va_start va_arg va_end 
int my_printf(const char *format, ...)
{
	//char *p = (char *)&format;
	va_list p;
		
    int arg2 = 0;
	struct person arg3;
	char arg4 = 0;
	double arg5;// must be duoble

	//arg1
	printf("arg1:%s\n", format);
	//p+= sizeof(char);
	va_start(p, format);

	//arg2
	//arg2 = *((int *)p);
	//p += sizeof(int);
	arg2 = va_arg(p, int);
	printf("arg2:%d\n", arg2);

	//arg3
	//arg3 = *((struct person *)p);
    //p += sizeof(struct person);
	arg3 = va_arg(p, struct person);
	printf("arg3:name:%s,age:%d,score:%c, id:%d\n", arg3.name, arg3.age, arg3.score, arg3.id);

	//arg4
    //arg4 = *((char *)p);
    //p += ((sizeof(char) + 3) & ~3);
	arg4 = va_arg(p, int); //must be int, because alignment is 4
    printf("arg4:%c\n", arg4);

	//arg5
    //arg5 = *((double *)p);
	arg5 = va_arg(p, double);
    printf("arg5:%lf\n", arg5);

	va_end(p);

	return 0;
}

int main(int argc, char *argv)
{
	struct person per = {"Black", 26, 'A', 53};
	//my_printf("abcd");
	//my_printf("abcd", 123);
	//my_printf("abcd", 123, per);
	//my_printf("abcd", 123, per, 'C');

    my_printf("abcd", 123, per, 'C', 4.321);

	return 0;
}
