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
	MI_S32 s32Tmp = 0;

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

	s32Tmp = pstQueueInfo->s32Size + s32Size;
	if (s32Tmp > pstQueueInfo->s32Max)
	{
		printf("Queue has not enough space\n");
		printf("Input Size:%d, Remain Size:%d\n", s32Size, pstQueueInfo->s32Max- pstQueueInfo->s32Size);
		return -1;
	}

	if (pstQueueInfo->s32Front + s32Size > pstQueueInfo->s32Max)
	{
		s32Tmp = pstQueueInfo->s32Max - pstQueueInfo->s32Front;
		memcpy(pstQueueInfo->pBuff + pstQueueInfo->s32Front, pInputBuff, s32Tmp);
		memcpy(pstQueueInfo->pBuff, pInputBuff + s32Tmp, s32Size - s32Tmp);
	}
	else
	{
		memcpy(pstQueueInfo->pBuff + pstQueueInfo->s32Front, pInputBuff, s32Size);
	}

	pstQueueInfo->s32Front = (pstQueueInfo->s32Front + s32Size) % pstQueueInfo->s32Max;
	pstQueueInfo->s32Size += s32Size;
	//printf("pstQueueInfo->s32Size:%d\n",pstQueueInfo->s32Size);

	return MI_SUCCESS;
}

MI_S32 _MI_AO_QueueDraw(_MI_AO_QueueInfo_t *pstQueueInfo, MI_U8 *pOutputBuff, MI_S32 s32Size)
{
	MI_S32 s32Tmp = 0;
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

	s32Tmp = pstQueueInfo->s32Size - s32Size;
	if (s32Tmp < 0)
	{
		printf("Queue has not enough data\n");
		printf("Input Size:%d, Remain data Size:%d\n", s32Size, pstQueueInfo->s32Size);
		return -1;
	}

	if (pstQueueInfo->s32Rear + s32Size > pstQueueInfo->s32Max)
	{
		s32Tmp = pstQueueInfo->s32Max - pstQueueInfo->s32Rear;
		memcpy(pOutputBuff,pstQueueInfo->pBuff +  pstQueueInfo->s32Rear, s32Tmp);
		memcpy(pOutputBuff + s32Tmp, pstQueueInfo->pBuff, s32Size - s32Tmp);
	}
	else
	{
		memcpy(pOutputBuff, pstQueueInfo->pBuff + pstQueueInfo->s32Rear, s32Size);
	}

	pstQueueInfo->s32Rear = (pstQueueInfo->s32Rear + s32Size) % pstQueueInfo->s32Max;
	pstQueueInfo->s32Size -= s32Size;
		
	return MI_SUCCESS;
}

void _MI_AO_QueuePrint (_MI_AO_QueueInfo_t *pstQueueInfo)
{
	printf("Front:%d\n", pstQueueInfo->s32Front);
	printf("Rear:%d\n", pstQueueInfo->s32Rear);
	printf("Max:%d\n", pstQueueInfo->s32Max);
	printf("Size:%d\n", pstQueueInfo->s32Size);
}

#define MAX (100)


int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	MI_U8 InputBuff[MAX * 2] = {0};
	MI_U8 OutputBuff[MAX * 2] = {0};
	_MI_AO_QueueInfo_t *pstQueue = NULL;

	pstQueue = _MI_AO_QueueCreate(100);

	for (i = 0; i < MAX * 2; i++)
	{
		InputBuff[i] = 'a' + (i % 26);
	}

#if 0
	_MI_AO_QueueInsert(pstQueue, InputBuff, 26);
	_MI_AO_QueuePrint(pstQueue);
	printf("=============\n");
	_MI_AO_QueueInsert(pstQueue, InputBuff, 26);
	_MI_AO_QueuePrint(pstQueue);
	printf("=============\n");
	_MI_AO_QueueInsert(pstQueue, InputBuff, 26);
	_MI_AO_QueuePrint(pstQueue);
	printf("=============\n");
	_MI_AO_QueueDraw(pstQueue, OutputBuff, 3 * 26);
	_MI_AO_QueuePrint(pstQueue);
	printf("=============\n");

	printf("######################\n");
	_MI_AO_QueueInsert(pstQueue, InputBuff, 26);
	_MI_AO_QueuePrint(pstQueue);
	printf("=============\n");
	_MI_AO_QueueInsert(pstQueue, InputBuff, 26);
	_MI_AO_QueuePrint(pstQueue);
	printf("=============\n");
	_MI_AO_QueueInsert(pstQueue, InputBuff, 26);
	_MI_AO_QueuePrint(pstQueue);
	printf("=============\n");
	_MI_AO_QueueDraw(pstQueue, OutputBuff, 4 * 26);
	_MI_AO_QueuePrint(pstQueue);
#else
	for (i = 0; i < 25; i++)
	{
		_MI_AO_QueueInsert(pstQueue, InputBuff, 26);
		_MI_AO_QueueDraw(pstQueue, OutputBuff, 25);
		for (j = 0; j < 25; j++)
		{
			printf("%c", OutputBuff[j]);
		}
		printf("\n");
	}

#endif

	for (i = 0; i < MAX; i++)
	{
		//printf("[%d]:%c\n", i, OutputBuff[i]);
	}
	printf("\n");

	return MI_SUCCESS;
}
