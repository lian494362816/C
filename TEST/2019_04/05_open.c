#include <stdio.h>
#include "sysdep.h"

int main(int argc, char *argv[])
{
    INLINE_SYSCALL_CALL(openat, AT_FDCWD, file, oflag, mode); 
    return 0;
}
