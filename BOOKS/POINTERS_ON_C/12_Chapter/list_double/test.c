#include <string.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include <stdio.h>


//Date 2018.2.12
//Program double list test

S32 my_list_add(S32 s32Value, struct my_list_s *pList)
{
	my_list_t *pNewList = NULL;
	my_list_t *pPreList = NULL;
	my_list_t *pCurList = NULL;

	if (NULL == pList)
	{
		MY_WARING("NULL Pointer\n");
		return MY_FAIL;
	}

	pCurList = pList;
	while (pCurList != NULL &&  pCurList->s32Value < s32Value)
	{
		pPreList = pCurList;
		pCurList = pCurList->pNext;
	}

	pNewList = malloc(sizeof(my_list_t));
	if (NULL == pNewList)
	{
		MY_WARING("NULL Pointer\n");
		return MY_FAIL;
	}
	memset(pNewList, 0, sizeof(my_list_t));

	pNewList->s32Value = s32Value;

	//开头
	if (NULL == pCurList->pPrev)
	{
		pNewList->pNext = pCurList;
		pCurList->pPrev = pNewList;
		return MY_SUCCESS;
	}

	//结尾
	if (NULL == pCurList->pNext)
	{
		pNewList->pNext = NULL;
		pNewList->pPrev = pCurList;
		pCurList->pNext = pNewList;
		return MY_SUCCESS;
	}

	//中间
	pNewList->pNext = pCurList;
	pNewList->pPrev = pPreList;
	pPreList->pNext = pNewList;
	pCurList->pPrev = pNewList;


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
		pList = pList->pNext;
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
	pstHeadList->pNext = NULL;
	pstHeadList->pPrev = NULL;
	pstHeadList->s32Value = 0;

	printf("before:\n");
	my_list_print(pstHeadList);

	//my_list_add(-10, pstHeadList);
	my_list_add(10, pstHeadList);
	//my_list_add(12, pstHeadList);
	//my_list_add(20, pstHeadList);
	//my_list_add(15, pstHeadList);
	//my_list_add(2, pstHeadList);
	//my_list_add(-8, pstHeadList);
	//my_list_add(-30, pstHeadList);

	printf("after:\n");
	my_list_print(pstHeadList);

	return 0;
}
