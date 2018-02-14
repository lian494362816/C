#include <string.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"

//Date 2018.2.13
//Program function-pointer, funtion-pointer array test

typedef  enum E_OPERATIION_{
	E_OPERATION_ADD = 0,
	E_OPERATION_SUB = 1,
	E_OPERATION_MUL = 2,
	E_OPERATION_DIV = 3,
}E_OPERATION;

F64 my_add(F64 f64Num1, F64 f64Num2)
{
	return f64Num1 + f64Num2;
}

F64 my_sub(F64 f64Num1, F64 f64Num2)
{
	return f64Num1 - f64Num2;
}

F64 my_mul(F64 f64Num1, F64 f64Num2)
{
	return f64Num1 * f64Num2;
}

F64 my_div(F64 f64Num1, F64 f64Num2)
{
	return f64Num1 / f64Num2;
}

F64 my_operation_switch(E_OPERATION eOperation, F64 f64Num1, F64 f64Num2)
{
	F64 f64Result = 0.0;

	switch(eOperation)
	{
		case E_OPERATION_ADD:
			f64Result = my_add(f64Num1, f64Num2);	
			break;

		case E_OPERATION_SUB:
			f64Result = my_sub(f64Num1, f64Num2);
			break;

		case E_OPERATION_MUL:
			f64Result = my_mul(f64Num1, f64Num2);
			break;

		case E_OPERATION_DIV:
			f64Result = my_div(f64Num1, f64Num2);
			break;

		default:
			return MY_FAIL;
	}
	
	return f64Result;
}

F64 my_operation_pointer(F64 (*opt)(F64, F64), F64 f64Num1, F64 f64Num2)
{
	F64 f64Result = 0.0;

	f64Result = opt(f64Num1, f64Num2);

	return f64Result;
}


F64 (*my_operation_array[]) (F64, F64)= {
	my_add, my_sub, my_mul, my_div
};

int main(int argc, char *argv[])
{
	F64 f64Num1 = 4.0;
	F64 f64Num2 = 2.0;

	printf("my_operation_switch:\n");
	printf("add:%lf\n", my_operation_switch(E_OPERATION_ADD, f64Num1, f64Num2));
	printf("sub:%lf\n", my_operation_switch(E_OPERATION_SUB, f64Num1, f64Num2));
	printf("mul:%lf\n", my_operation_switch(E_OPERATION_MUL, f64Num1, f64Num2));
	printf("div:%lf\n", my_operation_switch(E_OPERATION_DIV, f64Num1, f64Num2));

	printf("my_operation_poiner:\n");
	printf("add:%lf\n", my_operation_pointer(my_add, f64Num1, f64Num2));
	printf("sub:%lf\n", my_operation_pointer(my_sub, f64Num1, f64Num2));
	printf("mul:%lf\n", my_operation_pointer(my_mul, f64Num1, f64Num2));
	printf("div:%lf\n", my_operation_pointer(my_div, f64Num1, f64Num2));

	printf("my_operation_array:\n");
	printf("add:%lf\n", my_operation_array[0](f64Num1, f64Num2));
	printf("sub:%lf\n", my_operation_array[1](f64Num1, f64Num2));
	printf("mul:%lf\n", my_operation_array[2](f64Num1, f64Num2));
	printf("div:%lf\n", my_operation_array[3](f64Num1, f64Num2));

	return MY_SUCCESS;
}
