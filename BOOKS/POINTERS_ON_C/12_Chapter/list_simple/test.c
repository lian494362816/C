
#include <string.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"

//Date 2018.2.12
//Program 单链表测试程序, 使用&pList->list 代替pPreList


S32 my_list_add(S32 s32Value, struct my_list_s **pList)
{
	my_list_t *pNewList = NULL;
	my_list_t *pCurList = NULL;

	if (NULL == pList)
	{
		MY_WARING("NULL Pointer\n");
		return MY_FAIL;
	}

	pCurList = *pList;
	while (pCurList != NULL &&  pCurList->s32Value < s32Value)
	{
		pList = &pCurList->list;
		pCurList = *pList;
	}

	pNewList = malloc(sizeof(my_list_t));
	if (NULL == pNewList)
	{
		MY_BUG("malloc failed\n");
		return MY_FAIL;
	}

	pNewList->s32Value = s32Value;

	pNewList->list = pCurList;
	*pList = pNewList;
	
	return MY_SUCCESS;
}

S32 my_list_print(my_list_t *pList)
{
	if (NULL == pList)
	{
		MY_WARING("NULL Pointer\n");
		return MY_FAIL;
	}

	while(pList != NULL)
	{
		printf("Value = %d\n", pList->s32Value);
		pList = pList->list;
	}
		
	return MY_SUCCESS;
}

int main(int argc, char *argv[])
{
	my_list_t *pstHeadList = NULL;

	pstHeadList = malloc(sizeof(my_list_t));
	if (NULL == pstHeadList)
	{
		MY_ERROR("malloc failed\n");
		return MY_FAIL;
	}

	memset(pstHeadList, 0, sizeof(my_list_t));
	pstHeadList->list = NULL;
	pstHeadList->s32Value = 0;

	printf("before:\n");
	my_list_print(pstHeadList);

	my_list_add(-10, &pstHeadList);
	my_list_add(10, &pstHeadList);
	my_list_add(12, &pstHeadList);
	my_list_add(20, &pstHeadList);
	my_list_add(15, &pstHeadList);
	my_list_add(2, &pstHeadList);
	my_list_add(-8, &pstHeadList);
	my_list_add(-30, &pstHeadList);

	printf("after:\n");
	my_list_print(pstHeadList);

	return MY_SUCCESS;
}
