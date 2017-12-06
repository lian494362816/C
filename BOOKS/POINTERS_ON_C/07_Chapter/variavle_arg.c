#include <stdio.h>
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>


float my_average(int count, ...)
{
	int i = 0;
	va_list var_arg;
	float average;
	int sum = 0;

	va_start(var_arg, count);

	for (i = 0; i < count; i++)
	{
		sum += va_arg(var_arg, int);
	}

	printf("sum = %d\n", sum);

	average = sum / count;

	va_end(var_arg);

	return average;
}

int main(int argc, char *argv[])
{
	float average = 0;		

	average = my_average(10, 1, 2, 3, 4, 5, 6,7 , 8,9, 10);

	printf("average = %f\n", average);

	return 0;
}
