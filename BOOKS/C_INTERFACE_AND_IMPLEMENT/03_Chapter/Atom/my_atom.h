#ifndef __MY_ATOM_H_
#define __MY_ATOM_H_

#include "my_type.h"

S32 my_atom_length(const S8 *ps8Str);
S8 *my_atom_new(const S8 *ps8Str, S32 s32Len);
S8 *my_atom_string(const S8 *ps8Str);
S8 *my_atom_init(S32 s32Num);
S32 my_atom_print(void);


#endif //__MY_ATOM_H_
