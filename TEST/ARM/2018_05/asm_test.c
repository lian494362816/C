#include <stdio.h>

int main(int argc, char *argv)
{
	int a = 100;
	int b = 100;
	int c = 0;

	__asm__ __volatile__ (
	"mov r0, %1	\n"
	"mov r1, %2 \n"
	"add r2, r1, r2 \n"
	"mov %0, r2 \n"

	:"=r"(c)
	:"r"(a), "r"(b)
	:"r0", "r1", "r2"
	);
	return 0;
}
