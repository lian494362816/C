
SECTIONS {
    . = 0x40008000 ;

    . = ALIGN(4) ;
    __copy_code_start = . ;
    .init :
    {
       ./module/main.o
    }

    .text :
    {
        *(.text)
    }

    . = ALIGN(4) ;
    .rodata : { *(.rodata) }

    . = ALIGN(4) ;
    .data : { *(.data) }

    . = ALIGN(4) ;
    __bss_start = . ;
    .bss : { *(.bss) *(.COMMON) }
    __end = . ;

}
