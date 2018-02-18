#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"


//Date 2018.2.18
//Program fread fwrite test

typedef struct my_class_s{
	U32 u32Age;
	S8  as8Name[50];
}my_class_t;

static S32 my_class_print(my_class_t *pstClass)
{
	printf("Age:%d\n", pstClass->u32Age);
	printf("Name:%s\n", pstClass->as8Name);
	
	return MY_SUCCESS;
}

int main(int argc, char *argv[])
{
	FILE *pInput = NULL;	
	FILE *pOutput = NULL;
	my_class_t stStudent1;
	my_class_t stStudent2;

	pInput = fopen("./read.txt", "r");
	if (NULL == pInput)
	{
		MY_ERROR("fopen failed\n");
		return MY_FAIL;
	}

	pOutput = fopen("./write.txt", "w");
	if (NULL == pOutput)
	{
		MY_ERROR("fopen failed\n");
		return MY_FAIL;
	}

	memset(&stStudent1, 0, sizeof(my_class_t));
	memset(&stStudent2, 0, sizeof(my_class_t));

	fread(&stStudent1, sizeof(my_class_t), 1, pInput);
	fread(&stStudent2, sizeof(my_class_t), 1, pInput);

	my_class_print(&stStudent1);
	my_class_print(&stStudent2);

	fwrite(&stStudent1, sizeof(my_class_t), 1, pOutput);
	fwrite(&stStudent2, sizeof(my_class_t), 1, pOutput);

	fclose(pInput);
	fclose(pOutput);

	return 0;
}
