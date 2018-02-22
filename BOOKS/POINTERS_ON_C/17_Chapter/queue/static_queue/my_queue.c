#include "my_queue.h"
#include "my_type.h"
#include "my_error.h"

#define QUEUE_SIZE  (100 + 1)

static QUEUE_TYPE  _gaQueue[QUEUE_SIZE];
static U32         _gu32Front = 1;
static U32		   _gu32Rear  = 0;

static S32 _queue_is_empty(void)
{
	return (_gu32Rear + 1) % QUEUE_SIZE == _gu32Front;
}

static S32 _queue_is_full(void)
{
	return (_gu32Rear + 2) % QUEUE_SIZE == _gu32Front;
}

S32 my_queue_insert(QUEUE_TYPE Value)
{
	if (_queue_is_full())
	{
		MY_ERROR("queue is full\n");
		return MY_FAIL;
	}

	_gu32Rear = (_gu32Rear + 1) % QUEUE_SIZE;
	_gaQueue[_gu32Rear] = Value;

	return MY_SUCCESS;
}

S32 my_queue_delete(void)
{
	QUEUE_TYPE Value = 0;
	
	if (_queue_is_empty())
	{
		MY_ERROR("queue is empty\n");
		return MY_FAIL;
	}

	Value = _gaQueue[_gu32Front];

	_gu32Front = (_gu32Front + 1) % QUEUE_SIZE;

	return Value;
}

QUEUE_TYPE my_queue_first(void)
{
	if (_queue_is_empty())
	{
		MY_ERROR("queue is empty\n");
		return MY_FAIL;
	}

	return _gaQueue[_gu32Front];
}
