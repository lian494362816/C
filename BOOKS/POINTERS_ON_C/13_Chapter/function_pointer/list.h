#ifndef __LIST_H_
#include <stdio.h>

#include "my_type.h"

typedef struct my_list_s{
	struct my_list_s *list;	
	S32  s32Value;
}my_list_t;

#endif //__LIST_H_
