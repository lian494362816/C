#include "my_queue.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include <string.h>


typedef struct QueueNode_s{
	struct QueueNode_s *prev;
	struct QueueNode_s *next;
	QUEUE_TYPE         value;
}QueueNode_t;

static QueueNode_t  *_gpQueueNode = NULL;

static S32 _queue_is_empty(void)
{
	return _gpQueueNode->next == _gpQueueNode;
}

static S32 _queue_is_full(void)
{
	return MY_FALSE;
}

S32 my_queue_create(void)
{
	_gpQueueNode = MALLOC(1, QueueNode_t);
	if (NULL == _gpQueueNode)
	{
		MY_ERROR("malloc failed\n");
		return MY_FAIL;
	}

	memset(_gpQueueNode, 0, sizeof(QueueNode_t));
	_gpQueueNode->next = _gpQueueNode;
	_gpQueueNode->prev = _gpQueueNode;

	return MY_SUCCESS;
}

S32 my_queue_delete(void)
{
	QueueNode_t *pTailNode = NULL;
	S32 s32Value = 0;

	if (_queue_is_empty())
	{
		MY_ERROR("queue is empty\n");
		return MY_FAIL;
	}

	pTailNode = _gpQueueNode->prev;
	s32Value = pTailNode->value;

	pTailNode->prev->next = _gpQueueNode;
	_gpQueueNode->prev = pTailNode->prev;
	
	free(pTailNode);

	return s32Value;
}

S32 my_queue_destroy(void)
{
	while (!_queue_is_empty())
	{
		my_queue_delete();
	}

	return MY_SUCCESS;
}

S32 my_queue_insert(QUEUE_TYPE Value)
{
	QueueNode_t  *pNewQueueNode = NULL;

	pNewQueueNode = MALLOC(1, QueueNode_t);
	if (NULL == pNewQueueNode)
	{
		MY_ERROR("malloc failed\n");
		return MY_FAIL;
	}

	if (_queue_is_full())
	{
		MY_ERROR("queue is full\n");
		return MY_FAIL;
	}

	memset(pNewQueueNode, 0, sizeof(QueueNode_t));
	pNewQueueNode->value = Value;
	pNewQueueNode->prev = _gpQueueNode->prev;
	_gpQueueNode->prev->next = pNewQueueNode;
	pNewQueueNode->next = _gpQueueNode;
	_gpQueueNode->prev = pNewQueueNode;

	return MY_SUCCESS;
}

S32 my_queue_test(void)
{
	QueueNode_t  *pstTmpNode;

	for (pstTmpNode = _gpQueueNode->next; pstTmpNode != _gpQueueNode;)
	{
		printf("%d\n", pstTmpNode->value);
		pstTmpNode = pstTmpNode->next;
	}

	return MY_SUCCESS;
}


QUEUE_TYPE my_queue_first(void)
{
	if (_queue_is_empty())
	{
		MY_ERROR("queue is empty\n");
		return MY_FAIL;
	}

	return _gpQueueNode->prev->value;
}
