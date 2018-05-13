#ifndef __MY_FUNC_H_
#define __MY_FUNC_H_

#include <stdlib.h>
#include "my_error.h"

#define MALLOC(n, type)  (type *)malloc((n) * (sizeof(type)))

#define CHECK_POINTER(p) do{\
	if (NULL == p)\
	{\
		MY_BUG("NULL Pointer\n");\
	}\
}while(0)

#endif //__MY_FUNC_H_
