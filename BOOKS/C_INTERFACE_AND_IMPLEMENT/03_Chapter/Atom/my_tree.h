#ifndef __MY_TREE_H_
#define __MY_TREE_H_

#include "my_type.h"

#define TREE_TYPE  S32

typedef struct TreeNode_s{
TREE_TYPE Value;
struct TreeNode_s *left;
struct TreeNode_s *right;
}TreeNode_t;

S32 my_tree_insert(TREE_TYPE Value);
TreeNode_t * my_tree_find(TREE_TYPE Value);
S32 my_tree_pre_order_traverse(void (*callback)(TREE_TYPE Value));

#endif //__MY_TREE_H_
