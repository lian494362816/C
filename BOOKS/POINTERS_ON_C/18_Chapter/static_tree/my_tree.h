#ifndef __MY_TREE_H_

#include "my_type.h"

#define TREE_TYPE  S32

S32 my_tree_insert(TREE_TYPE Value);

S32 my_tree_find(TREE_TYPE Value);

S32 my_tree_pre_order_traverse(void (*callback)(TREE_TYPE Value));

#endif //__MY_TREE_H_
