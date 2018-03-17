#include <string.h>
#include <ctype.h>
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"


//Date:2018.3.17
//Program: advace queue

typedef struct _MI_AO_QueueInfo_s{
	MI_S32 s32Front;
	MI_S32 s32Rear;
	MI_S32 s32Max;//Max len of queue
	MI_S32 s32Size; //current size
	MI_U8  *pBuff;
}_MI_AO_QueueInfo_t;

_MI_AO_QueueInfo_t * _MI_AO_QueueCreate(MI_S32 s32Size)
{
	_MI_AO_QueueInfo_t *pstQueueInfo = NULL;	

	pstQueueInfo = (_MI_AO_QueueInfo_t *)malloc(sizeof(_MI_AO_QueueInfo_t));
	if (NULL == pstQueueInfo)
	{
		printf("malloc failed\n");
		return NULL;
	}
		
	pstQueueInfo->pBuff = (MI_U8 *)malloc(s32Size);
	if (NULL == pstQueueInfo->pBuff)
	{
		printf("malloc failed\n");
		free(pstQueueInfo);
		return NULL;
	}

	pstQueueInfo->s32Front = 0;
	pstQueueInfo->s32Rear = 0;
	pstQueueInfo->s32Max = s32Size;//one buff is not uese
	pstQueueInfo->s32Size = 0;

	return pstQueueInfo;
}

MI_S32 _MI_AO_Queue_Destroy(_MI_AO_QueueInfo_t *pstQueueInfo)
{
	if (NULL == pstQueueInfo)
	{
		printf("NULL Pointer\n");
		return -1;
	}

	free(pstQueueInfo->pBuff);

	return MI_SUCCESS;
}

MI_S32 _MI_AO_QueueInsert(_MI_AO_QueueInfo_t *pstQueueInfo, MI_U8 *pInputBuff, MI_S32 s32Size)
{
	if (NULL == pstQueueInfo)
	{
		printf("NULL Pointer \n");
		return -1;
	}

	if (NULL == pInputBuff)
	{
		printf("NULL Pointer\n");
		return -1;
	}

	if (s32Size < 0)
	{
		s32Size = 0;
	}

	pstQueueInfo->s32Size += s32Size;
	if (pstQueueInfo->s32Size > pstQueueInfo->s32Max)
	{
		printf("Queue has not enough space\n");
		printf("Input Size:%d, Remain Size:%d\n", s32Size, pstQueueInfo->s32Max- pstQueueInfo->s32Size);
		return -1;
	}

	memcpy(pstQueueInfo->pBuff + pstQueueInfo->s32Front, pInputBuff, s32Size);
	pstQueueInfo->s32Front += (pstQueueInfo->s32Front + s32Size) % pstQueueInfo->s32Max;

	return MI_SUCCESS;
}

MI_S32 _MI_AO_QueueDraw(_MI_AO_QueueInfo_t *pstQueueInfo, MI_U8 *pOutputBuff, MI_S32 s32Size)
{
	if (NULL == pstQueueInfo)
	{
		printf("NULL Pointer \n");
		return -1;
	}

	if (NULL == pOutputBuff)
	{
		printf("NULL Pointer\n");
		return -1;
	}

	if (s32Size < 0)
	{
		s32Size = 0;
	}

	if (s32Size > pstQueueInfo->s32Size)
	{
		printf("Queue has not enough data\n");
		printf("Input Size:%d, Data Size:%d\n", s32Size, pstQueueInfo->s32Size);
		return -1;
	}

	memcpy(pOutputBuff, pstQueueInfo->pBuff + pstQueueInfo->s32Rear, s32Size);
	pstQueueInfo->s32Rear = (pstQueueInfo->s32Rear + s32Size) % pstQueueInfo->s32Max;
		
	return MI_SUCCESS;
}

#define MAX (100)


int main(int argc, char *argv[])
{
	int i = 0;
	MI_U8 InputBuff[MAX * 2] = {0};
	MI_U8 OutputBuff[MAX * 2] = {0};
	_MI_AO_QueueInfo_t *pstQueue = NULL;

	pstQueue = _MI_AO_QueueCreate(100);

	for (i = 0; i < MAX+1; i++)
	{
		InputBuff[i] = 'a' + (i % 26);
	}

	_MI_AO_QueueInsert(pstQueue, InputBuff, MAX);
	_MI_AO_QueueDraw(pstQueue, OutputBuff, MAX);

	for (i = 0; i < MAX; i++)
	{
		printf("[%d]:%c\n", i, OutputBuff[i]);
	}
	printf("\n");

	return MI_SUCCESS;
}
