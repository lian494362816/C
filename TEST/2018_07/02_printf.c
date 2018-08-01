#include <stdio.h>

struct person{
	char *name;
	int age;
	char score;
	int id;
};

int my_printf(const char *format, ...)
{
	char *p = (char *)&format;
    int arg2 = 0;
	struct person arg3;
	char arg4 = 0;
	double arg5;// must be duoble
	printf("arg1:%s\n", format);
	p += sizeof(char *);

	arg2 = *((int *)p);
	p += sizeof(int);
	printf("arg2:%d\n", arg2);

	arg3 = *((struct person *)p);
    p += sizeof(struct person);
	printf("arg3:name:%s,age:%d,score:%c, id:%d\n", arg3.name, arg3.age, arg3.score, arg3.id);

    arg4 = *((char *)p);
    p += ((sizeof(char) + 3) & ~3);
    printf("arg4:%c\n", arg4);

    arg5 = *((double *)p);
    printf("arg5:%lf\n", arg5);

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
