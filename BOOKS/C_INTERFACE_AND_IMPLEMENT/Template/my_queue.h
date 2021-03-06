#ifndef __MY_QUEUE_H_
#define __MY_QUEUE_H_

#include "my_type.h"

#define QUEUE_TYPE  int

S32 my_queue_insert(QUEUE_TYPE Value);
S32 my_queue_delete(void);
QUEUE_TYPE my_queue_first(void);

S32 my_queue_create(void);
S32 my_queue_destroy(void);
S32 my_queue_test(void);

#endif //__MY_QUEUE_H_
