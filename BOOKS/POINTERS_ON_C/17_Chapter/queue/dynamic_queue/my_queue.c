#include "my_queue.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"


static U32         _gu32Front = 1;
static U32		   _gu32Rear  = 0;
static U32         _gu32QueueSize = 0;
static QUEUE_TYPE  *_gpQueue = NULL;

static S32 _queue_is_empty(void)
{
	if (0 == _gu32QueueSize)
	{
		MY_ERROR("queue is not exist\n");
		return MY_FAIL;
	}

	return (_gu32Rear + 1) % _gu32QueueSize == _gu32Front;
}

static S32 _queue_is_full(void)
{
	if (0 == _gu32QueueSize)
	{
		MY_ERROR("queue is not exist\n");
		return MY_FAIL;
	}

	return (_gu32Rear + 2) % _gu32QueueSize == _gu32Front;
}

S32 my_queue_create(U32 u32Size)
{
	if (0 != _gu32QueueSize)
	{
		MY_INFO("queue is already exist\n");
		return MY_FAIL;
	}

	_gu32QueueSize = u32Size;

	_gpQueue = MALLOC(_gu32QueueSize, QUEUE_TYPE);
	if (NULL == _gpQueue)
	{
		MY_ERROR("malloc failed\n");
		return MY_FAIL;
	}

	return MY_SUCCESS;
}

S32 my_queue_destroy(void)
{
	if (0 == _gu32QueueSize)
	{
		MY_INFO("queue is not exist\n");	
		return MY_FAIL;
	}

	free(_gpQueue);

	//set default value
	_gu32QueueSize = 0;
	_gpQueue = NULL;

	return MY_SUCCESS;
}

S32 my_queue_insert(QUEUE_TYPE Value)
{
	if (_queue_is_full())
	{
		MY_ERROR("queue is full\n");
		return MY_FAIL;
	}

	_gu32Rear = (_gu32Rear + 1) % _gu32QueueSize;
	_gpQueue[_gu32Rear] = Value;

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

	Value = _gpQueue[_gu32Front];

	_gu32Front = (_gu32Front + 1) % _gu32QueueSize;

	return Value;
}

QUEUE_TYPE my_queue_first(void)
{
	if (_queue_is_empty())
	{
		MY_ERROR("queue is empty\n");
		return MY_FAIL;
	}

	return _gpQueue[_gu32Front];
}
