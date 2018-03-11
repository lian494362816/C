#ifndef __MY_ADT_STACK_H_
#define __MY_ADT_STACK_H_

#include "my_error.h"

#define STACK_CREATE(STACK_TYPE, SUFFIX, STACK_SIZE)\
	static STACK_TYPE stack##SUFFIX[STACK_SIZE];\
	static int  top_element##SUFFIX = -1;\
	\
	int is_empty##SUFFIX(void)\
	{\
		return -1 == top_element##SUFFIX;\
	}\
\
	int is_full##SUFFIX(void)\
	{\
		return (STACK_SIZE -1) == top_element##SUFFIX;\
	}\
\
	STACK_TYPE	top##SUFFIX(void)\
	{\
		if (is_empty##SUFFIX())\
		{\
			MY_WARING("is empty\n");\
			return MY_FAIL;\
		}\
	\
		return  stack##SUFFIX[top_element##SUFFIX];\
	}\
\
	int push##SUFFIX(STACK_TYPE Value)\
	{\
		if (is_full##SUFFIX())\
		{\
			MY_WARING("is full\n");\
			return MY_FAIL;\
		}\
	\
		top_element##SUFFIX ++;\
		stack##SUFFIX[top_element##SUFFIX] = Value;\
	\
		return MY_SUCCESS;\
	}\
\
	STACK_TYPE pop##SUFFIX(void)\
	{\
		STACK_TYPE Tmp;\
		if (is_empty##SUFFIX())\
		{\
			MY_WARING("is empty\n");\
			return MY_FAIL;\
		}\
	\
		Tmp = stack##SUFFIX[top_element##SUFFIX];\
		top_element##SUFFIX --;\
		return Tmp;\
	}

#endif
