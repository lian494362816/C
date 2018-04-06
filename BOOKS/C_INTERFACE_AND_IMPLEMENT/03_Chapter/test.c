#include <string.h>
#include <ctype.h>
#include "list.h"
#include "my_type.h"
#include "my_error.h"
#include "my_func.h"
#include "my_queue.h"
#include "my_atom.h"


//Date:2018 4 6
//Program: Atom test

#define MAX (100)

int main(int argc, char *argv[])
{
    S32 s32i = 0;
//    S32 my_atom_length(const S8 *ps8Str);
//    S8 *my_atom_new(const S8 *ps8Str, S32 s32Len);
//    S8 *my_atom_string(const S8 *ps8Str);
//    S8 *my_atom_init(S32 s32Num);
//   S32 my_atom_print(void);

    for (s32i = 0; s32i < MAX; s32i++)
    {
        my_atom_init(s32i);
    }

    my_atom_print();

	return MY_SUCCESS;
}
